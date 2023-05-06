#include "../../src/headers/functions.h"
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

Suite *functions_suite(void) {
    Suite *s;
    TCase *tc_core;

    s = suite_create("Functions");

    /* Core test case */
    tc_core = tcase_create("Core");

    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, first_test);
    tcase_add_test(tc_core, second_test);
    suite_add_tcase(s, tc_core);

    return s;
}
