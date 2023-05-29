#include "../../src/modules/pointers.h"
#include "test_utils.h"
#include <check.h>
#include <stdio.h>

void pointers_setup() {
    printf("<-----> \n");
}

void pointers_teardown() {
    //
}

START_TEST(it_should_pass) {
    // given - when - then
    pointers();
}
END_TEST

Suite *get_pointers_suite() {
    Suite *pointers_suite = suite_create("Pointers");
    TCase *pointers_tc = tcase_create("Pointers");

    tcase_add_unchecked_fixture(pointers_tc, tc_setup, tc_teardown);
    tcase_add_checked_fixture(pointers_tc, pointers_setup, pointers_teardown);
    tcase_add_test(pointers_tc, it_should_pass);
    suite_add_tcase(pointers_suite, pointers_tc);

    return pointers_suite;
}