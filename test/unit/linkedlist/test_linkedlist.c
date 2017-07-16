#include <stdarg.h>
#include <stdint.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include "linkedlist.h"

/*
* Int tests
*/
static void test_linkedlist_add_int(void **state)
{
    int *intList = NULL, *intList2;

    intList = (int *)linkedlist_add(intList);
    *intList = 100;

    intList = (int *)linkedlist_add(intList);
    *intList = 200;

    assert_true(*intList == 200);
    intList2 = linkedlist_next(intList);
    assert_true(*intList2 == 100);

    linkedlist_free(intList);
}

static void test_linkedlist_remove_int(void **state)
{
    int *intList = NULL;

    intList = (int *)linkedlist_add(intList);
    *intList = 100;

    intList = (int *)linkedlist_add(intList);
    *intList = 200;

    assert_true(*intList == 200);
    intList = linkedlist_remove(intList);
    assert_true(*intList == 100);
    intList = linkedlist_remove(intList);
    assert_null(intList);
}

static int test_traverse_array_int[3];
static int test_traverse_array_int_index = 0;

static void test_traverse_callback_int(void *intPointer)
{
    int *val = (int *)intPointer;
    test_traverse_array_int[test_traverse_array_int_index++] = *val;
}

static void test_linkedlist_traverse_int(void **state)
{
    int *intList = NULL;

    intList = (int *)linkedlist_add(intList);
    *intList = 100;

    intList = (int *)linkedlist_add(intList);
    *intList = 200;

    intList = (int *)linkedlist_add(intList);
    *intList = 300;

    linkedlist_traverse(intList, &test_traverse_callback_int);
    assert_true(test_traverse_array_int[0] == 300);
    assert_true(test_traverse_array_int[1] == 200);
    assert_true(test_traverse_array_int[2] == 100);

    linkedlist_free(intList);
}

/*
* Struct tests
*/
struct LinkedListTestStruct {
    int integer_array[3];
    char * str;
};

static void test_linkedlist_add_struct(void **state)
{
    struct LinkedListTestStruct *structList = NULL, *structList2;

    structList = (struct LinkedListTestStruct *)linkedlist_add(structList);
    structList->integer_array[0] = 1;
    structList->integer_array[1] = 2;
    structList->integer_array[2] = 3;
    structList->str = "TestStruct1";

    structList = (struct LinkedListTestStruct *)linkedlist_add(structList);
    structList->integer_array[0] = 10;
    structList->integer_array[1] = 20;
    structList->integer_array[2] = 30;
    structList->str = "TestStruct2";

    assert_true(structList->integer_array[1] == 20);
    structList2 = linkedlist_next(structList);
    assert_true(structList2->integer_array[1] == 2);
    assert_string_equal(structList->str, "TestStruct2");
    assert_string_equal(structList2->str, "TestStruct1");

    linkedlist_free(structList);
}

/*
* String tests
*/
static void test_linkedlist_add_string(void **state)
{
    char **strList = NULL, **strList2;

    strList = (char **)linkedlist_add(strList);
    *strList = "TestStr1";

    strList = (char **)linkedlist_add(strList);
    *strList = "TestStr2";

    assert_string_equal(*strList, "TestStr2");
    strList2 = linkedlist_next(strList);
    assert_string_equal(*strList2, "TestStr1");

    linkedlist_free(strList);
}

/*
* NULL tests
*/
static void test_linkedlist_next_NULL(void **state)
{
    int *intList = NULL;
    intList = linkedlist_next(NULL);
    assert_null(intList);
}

static void test_linkedlist_remove_NULL(void **state)
{
    int *intList = NULL;
    intList = linkedlist_remove(NULL);
    assert_null(intList);
}

static void test_linkedlist_free_NULL(void **state)
{
    linkedlist_free(NULL);
}

/*
* Register Tests
*/
int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(test_linkedlist_add_int),
        cmocka_unit_test(test_linkedlist_remove_int),
        cmocka_unit_test(test_linkedlist_traverse_int),
        cmocka_unit_test(test_linkedlist_add_struct),
        cmocka_unit_test(test_linkedlist_add_string),
        cmocka_unit_test(test_linkedlist_next_NULL),
        cmocka_unit_test(test_linkedlist_remove_NULL),
        cmocka_unit_test(test_linkedlist_free_NULL)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}
