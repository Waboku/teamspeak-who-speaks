#ifndef __TS3_SERVERQUERY_H__
#define __TS3_SERVERQUERY_H__

#include <stdbool.h>

typedef struct TsUser {
    char *nick;
    char *channel;
    char *talking;
} ts_user_t;

typedef struct TsStatus {
    struct {
        char **nick_head;
        char **cid_head;
    } users;
    struct {
        char **channel_head;
        char **cid_head;
    } channels;
} ts_status_t;

void _ts3_serverquery_search(char *buf, const char *search, char ***head, bool copy);
const char *ts3_serverquery_find_channel_name(ts_status_t *status, const char *cid);
//void ts3_print_user_channel(ts_status_t *status);

#define ts3_serverquery_search(_buf, _search, _head) _ts3_serverquery_search(_buf, _search, _head, true)
#define ts3_serverquery_search_ncopy(_buf, _search, _head) _ts3_serverquery_search(_buf, _search, _head, false)

#endif /* __TS3_SERVERQUERY_H__ */
