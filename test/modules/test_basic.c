#include "../../src/basic/basic.h"
#include "../utils/common.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

void basic_setup() {
    printf("----> \n");
}

void basic_teardown() {
    printf("<---- \n");
}

START_TEST(it_should_return_correct_enum) {
    // given
    char *tuesday = "tuesday";
    char *saturday = "saturday";
    char *no_day = "aaaaaa";

    // when
    enum days enum_day_tue = enumerations(tuesday);
    enum days enum_day_sat = enumerations(saturday);
    enum days enum_day_no = enumerations(no_day);

    printf("'%s' is enum value %d\n", tuesday, enum_day_tue);
    printf("'%s' is enum value %d\n", saturday, enum_day_sat);
    printf("'%s' is enum value %d\n", no_day, enum_day_no);

    // then
    ck_assert_int_eq(enum_day_tue, 3);
    ck_assert_int_eq(enum_day_sat, 7);
    ck_assert_int_eq(enum_day_no, 0);
}
END_TEST

Suite *get_basic_suite() {
    Suite *basic_suite = suite_create("Basic");
    TCase *basic_tc = tcase_create("Basic");

    tcase_add_unchecked_fixture(basic_tc, tc_setup, tc_teardown);
    tcase_add_checked_fixture(basic_tc, basic_setup, basic_teardown);
    tcase_add_test(basic_tc, it_should_return_correct_enum);
    suite_add_tcase(basic_suite, basic_tc);

    return basic_suite;
}
