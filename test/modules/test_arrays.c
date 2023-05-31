#include "../../src/modules/arrays.h"
#include "utils.h"
#include <check.h>
#include <stdio.h>

void arrays_setup() {
    printf("----> \n");
}

void arrays_teardown() {
    printf("<---- \n");
}

START_TEST(it_should_create_and_print_array) {
    // given - when - then
    array();
}
END_TEST

START_TEST(it_should_create_and_print_integer_array) {
    // given - when - then
    integer_array();
}
END_TEST

START_TEST(it_should_create_and_print_char_array) {
    // given - when - then
    char_array();
}
END_TEST

Suite *get_arrays_suite() {
    Suite *arrays_suite = suite_create("Arrays");
    TCase *arrays_tc = tcase_create("Arrays");

    tcase_add_unchecked_fixture(arrays_tc, tc_setup, tc_teardown);
    tcase_add_checked_fixture(arrays_tc, arrays_setup, arrays_teardown);
    tcase_add_test(arrays_tc, it_should_create_and_print_array);
    tcase_add_test(arrays_tc, it_should_create_and_print_integer_array);
    tcase_add_test(arrays_tc, it_should_create_and_print_char_array);
    suite_add_tcase(arrays_suite, arrays_tc);

    return arrays_suite;
}
