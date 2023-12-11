#include "../../src/pointers/pointers.h"
#include "../utils/common.h"
#include <check.h>
#include <stdio.h>

void pointers_setup() {
    printf("----> \n");
}

void pointers_teardown() {
    printf("<---- \n");
}

START_TEST(it_should_print_pointers) {
    // given - when - then
    pointers();
}
END_TEST

START_TEST(it_should_print_pointer_array) {
    // given - when - then
    pointer_array();
}
END_TEST

START_TEST(it_should_swap_variable_values) {
    // given
    int alpha = 5;
    int beta = 13;
    printf("alpha -> %d, beta -> %d \n", alpha, beta);

    ck_assert_int_eq(alpha, 5);
    ck_assert_int_eq(beta, 13);

    // when
    swap(&alpha, &beta);
    printf("alpha -> %d, beta -> %d \n", alpha, beta);

    // then
    ck_assert_int_eq(alpha, 13);
    ck_assert_int_eq(beta, 5);
}
END_TEST

START_TEST(it_should_print_double_pointer_function) {
    // given - when - then
    double_pointer_function();
}
END_TEST

START_TEST(it_should_pass_string_to_function) {
    // given - when - then
    pass_string_to_function();
}
END_TEST

Suite *get_pointers_suite() {
    Suite *pointers_suite = suite_create("Pointers");
    TCase *pointers_tc = tcase_create("Pointers");

    tcase_add_unchecked_fixture(pointers_tc, tc_setup, tc_teardown);
    tcase_add_checked_fixture(pointers_tc, pointers_setup, pointers_teardown);
    tcase_add_test(pointers_tc, it_should_print_pointers);
    tcase_add_test(pointers_tc, it_should_print_pointer_array);
    tcase_add_test(pointers_tc, it_should_swap_variable_values);
    tcase_add_test(pointers_tc, it_should_print_double_pointer_function);
    tcase_add_test(pointers_tc, it_should_pass_string_to_function);
    suite_add_tcase(pointers_suite, pointers_tc);

    return pointers_suite;
}