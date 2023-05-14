#include "../../src/headers/struct.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

void struct_setup(void) {
    //
}

void struct_teardown(void) {
    //
}

START_TEST(test_create_struct) {
    // given
    char *title = "Beautiful Brighton";
    char *author = "Bob";

    // when
    struct Book book = create_struct(title, author, 2008, 15.60);
    printf("Title: %s \n", book.title);
    printf("Year: %d \n", book.year);

    // then
    ck_assert_str_eq(book.title, title);
    ck_assert_str_eq(book.author, author);
    ck_assert_int_eq(book.year, 2008);
    ck_assert_double_eq(book.price, 15.60);
}
END_TEST

Suite *get_struct_suite(void) {
    Suite *struct_suite = suite_create("Struct suite");
    TCase *struct_tc = tcase_create("Struct test case");

    tcase_add_checked_fixture(struct_tc, struct_setup, struct_teardown);
    tcase_add_test(struct_tc, test_create_struct);
    suite_add_tcase(struct_suite, struct_tc);

    return struct_suite;
}