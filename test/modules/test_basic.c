#include "../../src/headers/basic.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

void basic_setup(void) {
    //
}

void basic_teardown(void) {
    //
}

START_TEST(first_test) {
    int int_test = 5;
    char string_test[] = "this is a test 1";

    ck_assert_int_eq(int_test, 5);
    ck_assert_str_eq(string_test, "this is a test 1");
}
END_TEST

START_TEST(second_test) {
    int int_test = 5;
    char string_test[] = "this is a test 2";

    ck_assert_int_eq(int_test, 5);
    ck_assert_str_eq(string_test, "this is a test 2");
}
END_TEST

Suite *get_basic_suite(void) {
    Suite *basic_suite = suite_create("Basic suite");
    TCase *basic_tc = tcase_create("Basic test case");

    tcase_add_checked_fixture(basic_tc, basic_setup, basic_teardown);
    tcase_add_test(basic_tc, first_test);
    tcase_add_test(basic_tc, second_test);
    suite_add_tcase(basic_suite, basic_tc);

    return basic_suite;
}
