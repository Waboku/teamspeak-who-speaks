#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "common.h"

#ifdef AT_SOCKET

#include "socket_at.h"

#else /* Use POSIX sockets */

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#endif /* AT_SOCKET */


#define BUF_SIZE 500

#define TS_URL              "www.taylorswiftfanclub.nl"
#define TS_SQ_PORT          "10011"
#define TS_PORT             "9987"
#define TS_PW               "pw"
#define TS_LOGIN            "login"

int main(void) {
    struct addrinfo hints;
    struct addrinfo *result;

    int sfd, s, j;

    size_t len;
    ssize_t nread;

    char buf[BUF_SIZE];

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    s = getaddrinfo(TS_URL, TS_SQ_PORT, &hints, &result);
    if (s != 0 || result == NULL) {
        printf("getaddrinfo: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
    }

    // We just use the first one
    sfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sfd == -1) {
        printf("socket call failed\n");
    }

    s = connect(sfd, result->ai_addr, result->ai_addrlen);
    if (s == -1) {
        printf("connect call failed\n");
    }

    // No longer needed
    freeaddrinfo(result);

    // Do stuff


    // END do stuff

    close(sfd);

}
