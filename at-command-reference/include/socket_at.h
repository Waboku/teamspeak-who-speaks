#ifndef __SOCKET_AT_H__
#define __SOCKET_AT_H__

#include "at.h"

#define AT_AF_INET      1
#define AT_SOCK_STREAM  1
#define AT_SOCK_DGRAM   2

typedef unsigned int at_socklen_t;

struct at_addr {
    char *ip;
    const char *url;
    const char *port;
};

struct at_addrinfo {
    int                 ai_family;
    int                 ai_socktype;
    int                 ai_protocol;
    at_socklen_t        ai_addrlen;
    struct at_addr      *ai_addr;
    //char                *ai_canonname; // Unused

    struct at_addrinfo  *ai_next;
};

void at_setconnection(const atrw_t *at_con);

int at_getaddrinfo(const char *node, const char *service,
        struct at_addrinfo *hints,
        struct at_addrinfo **res);

void at_freeaddrinfo(struct at_addrinfo *res);

//const char *at_gai_strerror(int errcode); TODO

int at_socket(int domain, int type, int protocol);
int at_connect(int sockfd, struct at_addr *addr, at_socklen_t addrlen);
int at_close(int fd);

/* Overwrite socket defines */
#define AF_INET         AT_AF_INET
#define SOCK_STREAM     AT_SOCK_STREAM
#define SOCK_DGRAM      AT_SOCK_DGRAM

/* Overwrite socket structs */
#define addrinfo        at_addrinfo

/* Overwite socket calls */
#define getaddrinfo     at_getaddrinfo
#define freeaddrinfo    at_freeaddrinfo
#define socket          at_socket
#define connect         at_connect
#define close           at_close

/* Overwrite unsupported socket calls */
#define gai_strerror(_err)    "unsupported"

#endif /* __NETWORK_AT_H__ */
