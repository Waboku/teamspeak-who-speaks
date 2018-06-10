#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>

#include "common.h"
#include "linkedlist.h"
#include "ts3_serverquery.h"

static void test_ts3_serverquery_search_copy(void **state)
{
    #define SEARCH_TEXT "This is a search string, and we need to " \
    "find test1=test1_result and next we have test2=test2_result and finally " \
    "test3=test3_result"

    static const char * search_str_1 = "test1=";
    static const char * search_str_2 = "test2=";
    static const char * search_str_3 = "test3=";

    char search_buffer[] = SEARCH_TEXT;

    char **strList = NULL;

    ts3_serverquery_search(search_buffer, search_str_1, &strList);
    ts3_serverquery_search(search_buffer, search_str_2, &strList);
    ts3_serverquery_search(search_buffer, search_str_3, &strList);

    assert_string_equal(*strList, "test3_result");
    free(*strList);

    strList = linkedlist_remove(strList);
    assert_string_equal(*strList, "test2_result");
    free(*strList);

    strList = linkedlist_remove(strList);
    assert_string_equal(*strList, "test1_result");
    free(*strList);

    strList = linkedlist_remove(strList);

    assert_string_equal(search_buffer, SEARCH_TEXT);
    assert_null(strList);
}

static void test_ts3_serverquery_search_nocopy(void **state)
{
    #define SEARCH_TEXT "This is a search string, and we need to " \
    "find test1=test1_result and next we have test2=test2_result and finally " \
    "test3=test3_result"

    static const char * search_str_1 = "test1=";

    char search_buffer[] = SEARCH_TEXT;

    char **strList = NULL;

    ts3_serverquery_search_ncopy(search_buffer, search_str_1, &strList);

    assert_string_equal(*strList, "test1_result");

    strList = linkedlist_remove(strList);

    assert_string_not_equal(search_buffer, SEARCH_TEXT);
    assert_null(strList);
}

static void test_ts3_serverquery_find_channel_name(void **state)
{
    const char *found_channel = NULL;

    static ts_status_t tsStatus; // Must be init as zero
    tsStatus.channels.cid_head = linkedlist_add(tsStatus.channels.cid_head);
    tsStatus.channels.channel_head = linkedlist_add(tsStatus.channels.channel_head);
    *tsStatus.channels.cid_head = "1";
    *tsStatus.channels.channel_head = "test_channel_cid_1";

    tsStatus.channels.cid_head = linkedlist_add(tsStatus.channels.cid_head);
    tsStatus.channels.channel_head = linkedlist_add(tsStatus.channels.channel_head);
    *tsStatus.channels.cid_head = "2";
    *tsStatus.channels.channel_head = "test_channel_cid_2";

    tsStatus.channels.cid_head = linkedlist_add(tsStatus.channels.cid_head);
    tsStatus.channels.channel_head = linkedlist_add(tsStatus.channels.channel_head);
    *tsStatus.channels.cid_head = "3";
    *tsStatus.channels.channel_head = "test_channel_cid_3";

    found_channel = ts3_serverquery_find_channel_name(&tsStatus, "1");
    assert_string_equal(found_channel, "test_channel_cid_1");

    found_channel = ts3_serverquery_find_channel_name(&tsStatus, "3");
    assert_string_equal(found_channel, "test_channel_cid_3");

    found_channel = ts3_serverquery_find_channel_name(&tsStatus, "2");
    assert_string_equal(found_channel, "test_channel_cid_2");

    found_channel = ts3_serverquery_find_channel_name(&tsStatus, "1");
    assert_string_not_equal(found_channel, "test_channel_cid_2");

    linkedlist_free(tsStatus.channels.channel_head);
    linkedlist_free(tsStatus.channels.cid_head);
}

#if 0 // Need to rethink ts_status_t first
static void test_ts3_print_user_channel(void **state)
{
    /* TODO: Move this to a common setup for ts_status_t */
    static ts_status_t tsStatus; // Must be init as zero
    tsStatus.channels.cid_head = linkedlist_add(tsStatus.channels.cid_head);
    tsStatus.channels.channel_head = linkedlist_add(tsStatus.channels.channel_head);
    *tsStatus.channels.cid_head = "1";
    *tsStatus.channels.channel_head = "test_channel_cid_1";

    tsStatus.channels.cid_head = linkedlist_add(tsStatus.channels.cid_head);
    tsStatus.channels.channel_head = linkedlist_add(tsStatus.channels.channel_head);
    *tsStatus.channels.cid_head = "2";
    *tsStatus.channels.channel_head = "test_channel_cid_2";

    tsStatus.users.cid_head = linkedlist_add(tsStatus.users.cid_head);
    tsStatus.users.nick_head = linkedlist_add(tsStatus.users.nick_head);
    *tsStatus.user.nick_head = "nick_1";
    *tsStatus.users.cid_head = "2";

    tsStatus.users.cid_head = linkedlist_add(tsStatus.users.cid_head);
    tsStatus.users.nick_head = linkedlist_add(tsStatus.users.nick_head);
    *tsStatus.user.nick_head = "nick_2";
    *tsStatus.users.cid_head = "1";

    tsStatus.users.cid_head = linkedlist_add(tsStatus.users.cid_head);
    tsStatus.users.nick_head = linkedlist_add(tsStatus.users.nick_head);
    *tsStatus.user.nick_head = "nick_3";
    *tsStatus.users.cid_head = "2";

    ts3_print_user_channel(&tsStatus);

    linkedlist_free(tsStatus.channels.cid_head);
    linkedlist_free(tsStatus.channels.channel_head);
    linkedlist_free(tsStatus.users.cid_head);
    linkedlist_free(tsStatus.users.nick_head);
}
#endif

/*
* Register Tests
*/
int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_ts3_serverquery_search_copy),
        cmocka_unit_test(test_ts3_serverquery_search_nocopy),
        cmocka_unit_test(test_ts3_serverquery_find_channel_name)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
