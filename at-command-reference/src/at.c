#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "common.h"
#include "at.h"

ssize_t at_command(const atrw_t *at, char *command)
{
    ssize_t n;

    n = at->write(at, command, strlen(command)+1);
    if (n == -1) {
        fprintf(stderr, "Writing AT command: %s failed\n", command);
        perror(NULL);
        return -1;
    }

    //usleep(10 * 10000);
    n = at->read(at, at->buf, at->buflen-1);
    if (n == -1) {
        fprintf(stderr, "Reading AT response for: %s failed\n", command);
        perror(NULL);
        return -1;
    }

    at->buf[n] = '\0';

    return n;
}
