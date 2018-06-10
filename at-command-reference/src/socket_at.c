#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "at.h"
#include "socket_at.h"

#define N_CONNECTIONS   5

struct at_connectionstatus {
    int             in_use;

    int             domain;
    int             type;
    int             protocol;
    struct at_addr  *addr;
};

// Must be set to a vallid at connection using at_setconnection()
// before the sockets can be used
static const atrw_t *at_connection = NULL;

static struct at_connectionstatus at_ConnectionStatus[N_CONNECTIONS];

void at_setconnection(const atrw_t *at_con)
{
    at_connection = at_con;
}

int at_getaddrinfo(const char *node, const char *service,
        struct at_addrinfo *hints,
        struct at_addrinfo **res)
{

    struct at_addr *addr;
    ssize_t n;

    addr = malloc(sizeof(struct at_addr));
    if (addr == NULL) {
        return -1;
    }

    memset(addr, 0, sizeof(struct at_addr));

    addr->url = node;
    addr->port = service;

    hints->ai_addr = addr;

    // Get the IP from the url
    // at_command AT+CIPDOMAIN—DNS result in:
    // addr->ip;
    n = at_command(at_connection, "AT+CIPDOMAIN—DNS");

    // malloc and Strcpy at_connection->buf to addr->ip;

    // Set the result pointer
    *res = hints;

    return 0;
}

void at_freeaddrinfo(struct at_addrinfo *res)
{
    // We free the ai_addr within the close call
    // This is done to save memory
    (void)res;
}

int at_socket(int domain, int type, int protocol)
{
    int i;
    struct at_connectionstatus *connection;

    // Find an unused connection
    for (i=0; i<N_CONNECTIONS; i++) {
        if (!at_ConnectionStatus[i].in_use) {
            break;
        }
    }

    if (i == N_CONNECTIONS) {
        // No availible connections
        return -1;
    }
    connection = &at_ConnectionStatus[i];

    // Set the connection in_use
    connection->in_use = 1;

    connection->domain = domain;
    connection->type = type;
    connection->protocol = protocol;

    return i;
}

int at_connect(int sockfd, struct at_addr *addr, at_socklen_t addrlen)
{
    struct at_connectionstatus *connection;

    (void)addrlen;

    if (sockfd >= N_CONNECTIONS) {
        return -1;
    }

    connection = &at_ConnectionStatus[sockfd];

    connection->addr = addr;

    // AT Command OPEN connection
    //n = at_command(at_connection, "AT+CIPDOMAIN—DNS");

    return 0;
}

int at_close(int fd)
{
    struct at_connectionstatus *connection;

    if (fd >= N_CONNECTIONS) {
        return -1;
    }

    connection = &at_ConnectionStatus[fd];

    free(connection->addr);

    // Send AT command AT+CIPCLOSE
    //n = at_command(at_connection, "AT+CIPDOMAIN—DNS");

    connection->in_use = 0;

    return 0;
}

