#include "../../src/modules/malloc.h"
#include "utils.h"
#include <check.h>
#include <stdio.h>

void malloc_setup() {
    printf("----> \n");
}

void malloc_teardown() {
    printf("<---- \n");
}

START_TEST(it_should_run_malloc_example) {
    // given - when - then
    malloc_example();
}
END_TEST

Suite *get_malloc_suite() {
    Suite *malloc_suite = suite_create("Malloc");
    TCase *malloc_tc = tcase_create("Malloc");

    tcase_add_unchecked_fixture(malloc_tc, tc_setup, tc_teardown);
    tcase_add_checked_fixture(malloc_tc, malloc_setup, malloc_teardown);
    tcase_add_test(malloc_tc, it_should_run_malloc_example);

    suite_add_tcase(malloc_suite, malloc_tc);

    return malloc_suite;
}