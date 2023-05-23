#include "../../src/include/basic.h"
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
    // given
    char *tuesday = "tuesday";
    char *saturday = "saturday";
    char *no_day = "aaaaaa";

    // when
    enum days enum_day_tue = enumerations(tuesday);
    enum days enum_day_sat = enumerations(saturday);
    enum days enum_day_no = enumerations(no_day);

    // then
    ck_assert_int_eq(enum_day_tue, 3);
    ck_assert_int_eq(enum_day_sat, 7);
    ck_assert_int_eq(enum_day_no, 0);
}
END_TEST

Suite *get_basic_suite(void) {
    Suite *basic_suite = suite_create("Basic suite");
    TCase *basic_tc = tcase_create("Basic test case");

    tcase_add_checked_fixture(basic_tc, basic_setup, basic_teardown);
    tcase_add_test(basic_tc, first_test);
    suite_add_tcase(basic_suite, basic_tc);

    return basic_suite;
}
