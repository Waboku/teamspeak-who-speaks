#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <string.h>

#include "at.h"

#define AT_COMMAND_TEST_READ_STR "read test string\r\n"
#define AT_COMMAND_TEST_WRITE_STR "write test string\r\n"
#define AT_COMMAND_TEST_BUFFER_SIZE 256

char at_command_test_buffer[AT_COMMAND_TEST_BUFFER_SIZE];

ssize_t at_command_test_write(const struct atrw *self, const void *buf, ssize_t size)
{
    memcpy(at_command_test_buffer, buf, size);
    return size;
}

ssize_t at_command_test_read(const struct atrw *self, void *buf, ssize_t size)
{
    strcpy(buf, AT_COMMAND_TEST_READ_STR);
    return(strlen(AT_COMMAND_TEST_READ_STR) + 1);
}

static void test_at_command(void **state)
{
    struct atrw at;
    char buffer[AT_COMMAND_TEST_BUFFER_SIZE];

    at.write = at_command_test_write;
    at.read = at_command_test_read;
    at.buf = buffer;
    at.buflen = AT_COMMAND_TEST_BUFFER_SIZE;

    at_command(&at, AT_COMMAND_TEST_WRITE_STR);

    assert_string_equal(at_command_test_buffer, AT_COMMAND_TEST_WRITE_STR);
    assert_string_equal(at.buf, AT_COMMAND_TEST_READ_STR);
}

/*
* Register Tests
*/
int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_at_command)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
