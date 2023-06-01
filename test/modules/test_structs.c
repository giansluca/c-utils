#include "../../src/structs/structs.h"
#include "../utils/common.h"
#include <check.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void structs_setup() {
    printf("----> \n");
}

void structs_teardown() {
    printf("<---- \n");
}

START_TEST(is_should_create_struct) {
    // given
    char *title = "beautiful Brighton";
    char *author = "Bob";

    // when
    struct Book book = create_struct(title, author, 2008, 15.60);
    printf("book title: %s \n", book.title);
    printf("book year: %d \n", book.year);

    // then
    ck_assert_str_eq(book.title, title);
    ck_assert_str_eq(book.author, author);
    ck_assert_int_eq(book.year, 2008);
    ck_assert_double_eq(book.price, 15.60);
    ck_assert_int_eq(book.isInitialized, 1);
}
END_TEST

START_TEST(is_should_not_create_struct) {
    // given
    char *title = "beautiful Brighton";
    char *author = "this is a too long author name";

    // when
    struct Book book = create_struct(title, author, 2008, 15.60);

    // then
    ck_assert_int_eq(book.isInitialized, 0);
}
END_TEST

START_TEST(is_should_create_typedef_struct_by_value) {
    // given
    char *name = "colombo";
    char *race = "pitbull";

    // when
    Dog dog = create_typedef_struct_by_value(name, race, 7, 12.30);
    printf("dog name: %s \n", dog.name);
    printf("dog race: %s \n", dog.race);

    // then
    ck_assert_str_eq(dog.name, name);
    ck_assert_str_eq(dog.race, race);
    ck_assert_int_eq(dog.age, 7);
    ck_assert_float_eq(dog.weight, 12.30);
    ck_assert_int_eq(dog.isInitialized, 1);
}
END_TEST

START_TEST(is_should_not_create_typedef_struct_by_value) {
    // given
    char *name = "colombo";
    char *race = "to long race name for a dog";

    // when
    Dog dog = create_typedef_struct_by_value(name, race, 7, 12.30);

    // then
    ck_assert_int_eq(dog.isInitialized, 0);
}
END_TEST

START_TEST(is_should_create_typedef_struct_by_pointer) {
    // given
    char *name = "franz";
    char *race = "mix";

    // when
    Dog *dog = create_typedef_struct_by_pointer(name, race, 8, 14.55);
    printf("dog name: %s \n", dog->name);
    printf("dog race: %s \n", dog->race);

    // then
    ck_assert_str_eq(dog->name, name);
    ck_assert_str_eq(dog->race, race);
    ck_assert_int_eq(dog->age, 8);
    ck_assert_float_eq(dog->weight, 14.55);
    ck_assert_int_eq(dog->isInitialized, 1);

    free(dog);
}
END_TEST

START_TEST(is_should_not_create_typedef_struct_by_pointer) {
    // given
    char *name = "franz";
    char *race = "to long race name for a dog";

    // when
    Dog *dog = create_typedef_struct_by_pointer(name, race, 8, 14.55);

    // then
    ck_assert(dog == NULL);
}
END_TEST

Suite *get_structs_suite() {
    Suite *structs_suite = suite_create("Structs");
    TCase *structs_tc = tcase_create("Structs");

    tcase_add_unchecked_fixture(structs_tc, tc_setup, tc_teardown);
    tcase_add_checked_fixture(structs_tc, structs_setup, structs_teardown);
    tcase_add_test(structs_tc, is_should_create_struct);
    tcase_add_test(structs_tc, is_should_not_create_struct);
    tcase_add_test(structs_tc, is_should_create_typedef_struct_by_value);
    tcase_add_test(structs_tc, is_should_not_create_typedef_struct_by_value);
    tcase_add_test(structs_tc, is_should_create_typedef_struct_by_pointer);
    tcase_add_test(structs_tc, is_should_not_create_typedef_struct_by_pointer);
    suite_add_tcase(structs_suite, structs_tc);

    return structs_suite;
}