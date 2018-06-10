#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* Socket stuff */
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>


/* Option Codes */
#define WILL    251
#define WONT    252
#define DO      253
#define DONT    254

/* Interpret As Command (IAC) */
#define IAC     255

#define NBC     2       /* Number of bytes when dealing with an command */
#define NBO     3       /* Number of bytes when dealing with an option */

/* Other codes */
#define SE      240     /* End of subnegotiation parameters */
#define NOP     241     /* No operation */
#define DM      242     /* The data stream portion of a Synch
                           This should always be accompanied by
                           a TCP Urgent notification*/
#define BREAK   243     /* NVT character BRK */
#define IP      244     /* The function IP */
#define AO      245     /* The function AO */
#define AYT     246     /* The function AYT */
#define EC      247     /* The function EC */
#define EL      248     /* The function EL */
#define GA      249     /* The GA signal */
#define SB      250     /* Indicates that what follows is subnegotiation of the
                           indicated option */

// 2 Byte command: [IAC] [CODE]
// 3 Byte command: [IAC] [CODE] [OPTION] (0xFF WILL WINDOW_SIZE)

#define BUFLEN  (2048*10)

void error(const char *msg) {
    perror(msg);
    exit(0);
}

#define TS_IP               "www.taylorswiftfanclub.nl"
#define TS_SQ_PORT          10011
#define TS_PORT             "9987"
#define TS_PW               "pw"
#define TS_LOGIN            "login"

#define SEARCH_NICK         "client_nickname="
#define SEARCH_TALKING      "client_flag_talking="
#define SEARCH_CHANNEL_NAME "channel_name="
#define SEARCH_CHANNEL_ID   "cid="

typedef struct atrw {
    int buflen;
    char *buf;
    int fd; // For PC
    ssize_t (*write) (struct atrw *self, const void *, size_t);
    ssize_t (*read) (struct atrw *self, void *, size_t);
} atrw_t;

/* Parse AT commands */
ssize_t at_command(atrw_t *at, char *command) {
    ssize_t n;

    n = at->write(at, command, strlen(command));
    if (n == -1) {
        fprintf(stderr, "Writing AT command: %s failed\n", command);
        perror(NULL);
        return -1;
    }

    //bzero(at->buf, at->buflen);
    usleep(10 * 10000);
    n = at->read(at, at->buf, at->buflen-1);
    if (n == -1) {
        fprintf(stderr, "Reading AT response for: %s failed\n", command);
        perror(NULL);
        return -1;
    }
    printf("READ: %d\n", n);
    at->buf[n] = '\0';
}

ssize_t write_network(atrw_t *self, const void *buf, size_t count) {
    return write(self->fd, buf, count);
}

ssize_t read_network(atrw_t *self, void *buf, size_t count) {
    return read(self->fd, buf, count);
}


typedef struct tsUser {
    char *nick;
    char *channel;
    char *talking;
} ts_user_t;

typedef struct tsStatus {
    struct {
        strlist_t *nick_head;
        strlist_t *cid_head;
    } users;
    struct {
        strlist_t *channel_head;
        strlist_t *cid_head;
    } channels;
} ts_status_t;


ssize_t ts3_serverquery_search(char *buf, const char *search, strlist_t **head, bool copy) {
    char *pos, *start, *str;
    int cnt;

    pos = buf;
    while ((pos = strstr(pos, search)) != NULL) {
        pos += strlen(search);
        start = pos;
        cnt = 0;
        while (*pos++ != ' ') {
            ++cnt;
        }

        if (copy == true) {
            str = (char *)malloc(sizeof(char) * (cnt + 1));
            memcpy(str, start, sizeof(char) * cnt);
            str[cnt] = '\0';
            //printf("String: %s, cnt: %d\n", str, cnt);
        } else {
            *(pos-1) = '\0';
            str = start;
        }
        *head = ll_prepend(*head, str);
    }
}

const char *ts3_serverquery_find_channel_name(ts_status_t *status, const char *cid) {
    strlist_t *c_cid = status->channels.cid_head;
    strlist_t *c_channel = status->channels.channel_head;

    while (c_cid != NULL && c_channel != NULL) {
        if (strcmp(cid, c_cid->str) == 0) {
            return c_channel->str;
        }
        c_cid = c_cid->next;
        c_channel = c_channel->next;
    }
}

void ts3_print_user_channel(ts_status_t *status) {
    const char *channel_name;
    strlist_t *c_cid = status->users.cid_head;
    strlist_t *c_nick = status->users.nick_head;

    while (c_cid != NULL && c_nick != NULL) {
        channel_name = ts3_serverquery_find_channel_name(status, c_cid->str);
        printf("User: %s resides in Channel(%s): %s\n", c_nick->str, c_cid->str, channel_name);

        c_cid = c_cid->next;
        c_nick = c_nick->next;
    }
}


int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    static char buffer[BUFLEN];
    char *pos;
    char c;

    atrw_t at;

    // Linked list
    ts_user_t user;
    ts_status_t status;

    status.users.nick_head = NULL;
    status.users.cid_head = NULL;
    status.channels.channel_head = NULL;
    status.channels.cid_head = NULL;

    portno = TS_SQ_PORT;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(TS_IP);

    if (server == NULL) {
        error("ERROR no such host");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    printf("Connected!\r\n");

    /* Setup AT settings */
    at.buf = buffer;
    at.buflen = BUFLEN;
    at.fd = sockfd;
    at.write = &write_network;
    at.read = &read_network;

    n = at.read(&at, at.buf, at.buflen-1);
    if (n < 0) {
        error("ERROR reading");
    }
    printf("%s\n", at.buf);

    at_command(&at, "use port=" TS_PORT "\r\n");
    printf("%s\n", at.buf);

    at_command(&at, "login " TS_LOGIN " " TS_PW "\r\n");
    printf("%s\n", at.buf);

    at_command(&at, "channellist\r\n");
    printf("%s\n", at.buf);

    ts3_serverquery_search(at.buf,
            SEARCH_CHANNEL_ID,
            &status.channels.cid_head,
            true);
    ts3_serverquery_search(at.buf,
            SEARCH_CHANNEL_NAME,
            &status.channels.channel_head,
            true);

    at_command(&at, "clientlist all -voice\r\n");
    printf("%s\n", at.buf);

    ts3_serverquery_search(at.buf,
            SEARCH_NICK,
            &status.users.nick_head,
            true);
    ts3_serverquery_search(at.buf,
            SEARCH_CHANNEL_ID,
            &status.users.cid_head,
            true);

    traverse(status.users.nick_head, ll_print_str);
    traverse(status.users.cid_head, ll_print_str);
    printf("\n");
    traverse(status.channels.channel_head, ll_print_str);
    traverse(status.channels.cid_head, ll_print_str);
    printf("\n");
    ts3_fix_space(status.channels.channel_head->next->str);
    ts3_print_user_channel(&status);

}
