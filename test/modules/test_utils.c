#include "../../src/headers/utils.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

void setup(void) {
    //
}

void teardown(void) {
    //
}

START_TEST(first_test) {
    int int_test = 5;
    char string_test[] = "this is a test";

    ck_assert_int_eq(int_test, 5);
    ck_assert_str_eq(string_test, "this is a test");
}
END_TEST

START_TEST(second_test) {
    int int_test = 5;
    char string_test[] = "this is a test 2";

    ck_assert_int_eq(int_test, 5);
    ck_assert_str_eq(string_test, "this is a test 2");
}
END_TEST

Suite *get_utils_suite(void) {
    Suite *utils_suite = suite_create("Utils suite");
    TCase *utils_tc = tcase_create("Utils test case");

    tcase_add_checked_fixture(utils_tc, setup, teardown);
    tcase_add_test(utils_tc, first_test);
    tcase_add_test(utils_tc, second_test);
    suite_add_tcase(utils_suite, utils_tc);

    return utils_suite;
}
