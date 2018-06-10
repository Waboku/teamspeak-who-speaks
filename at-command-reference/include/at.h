#ifndef __AT_H__
#define __AT_H__

#include <unistd.h>

typedef struct atrw {
    int buflen;
    char *buf;
    ssize_t (*write) (const struct atrw *, const void *, ssize_t);
    ssize_t (*read) (const struct atrw *, void *, ssize_t);
    void *extra; // If extra data is needed
} atrw_t;


ssize_t at_command(const atrw_t *at, char *command);

#endif /* __AT_H__ */
