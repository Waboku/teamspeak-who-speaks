#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "common.h"
#include "linkedlist.h"
#include "ts3_serverquery.h"

void _ts3_serverquery_search(char *buf, const char *search, char ***ll_head, bool copy)
{
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
            //printf("String: %s\n", str);
        }

        *ll_head = linkedlist_add(*ll_head);
        **ll_head = str;
    }
}


const char *ts3_serverquery_find_channel_name(ts_status_t *status, const char *cid) {
    char **c_cid = status->channels.cid_head;
    char **c_channel = status->channels.channel_head;

    while (c_cid != NULL && c_channel != NULL) {
        if (strcmp(cid, *c_cid) == 0) {
            return *c_channel;
        }
        c_cid = linkedlist_next(c_cid);
        c_channel = linkedlist_next(c_channel);
    }
    return NULL;
}

#if 0 // Need to rethink the ugly ts_status_t layout. This sucks */
void ts3_print_user_channel(ts_status_t *status)
{
    const char *channel_name;
    char **c_cid = status->users.cid_head;
    char **c_nick = status->users.nick_head;
    char **c_channel = status->users.channel_head;

    while (c_cid != NULL && c_nick != NULL) {
        channel_name = ts3_serverquery_find_channel_name(status, c_cid);
        //printf("User: %s resides in Channel(%s): %s\n", c_nick, c_cid, channel_name);

        c_cid = linkedlist_next(cid);
        c_nick = linkedlist_next(c_nick);
    }
}
#endif
