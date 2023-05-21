#include "../../src/modules/struct.h"
#include <check.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void struct_setup(void) {
    //
}

void struct_teardown(void) {
    //
}

START_TEST(is_should_create_struct) {
    // given
    char *title = "Beautiful Brighton";
    char *author = "Bob";

    // when
    struct Book book = create_struct(title, author, 2008, 15.60);
    printf("Book title: %s \n", book.title);
    printf("Book year: %d \n", book.year);

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
    char *title = "Beautiful Brighton";
    char *author = "this is a too long author name";

    // when
    struct Book book = create_struct(title, author, 2008, 15.60);

    // then
    ck_assert_int_eq(book.isInitialized, 0);
}
END_TEST

START_TEST(is_should_create_typedef_struct_by_value) {
    // given
    char *name = "Colombo";
    char *race = "Pitbull";

    // when
    Dog dog = create_typedef_struct_by_value(name, race, 7, 12.30);
    printf("Dog name: %s \n", dog.name);
    printf("Dog race: %s \n", dog.race);

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
    char *name = "Colombo";
    char *race = "to long race name for a dog";

    // when
    Dog dog = create_typedef_struct_by_value(name, race, 7, 12.30);

    // then
    ck_assert_int_eq(dog.isInitialized, 0);
}
END_TEST

START_TEST(is_should_create_typedef_struct_by_pointer) {
    // given
    char *name = "Franz";
    char *race = "Mix";

    // when
    Dog *dog = create_typedef_struct_by_pointer(name, race, 8, 14.55);
    printf("Dog name: %s \n", dog->name);
    printf("Dog race: %s \n", dog->race);

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
    char *name = "Franz";
    char *race = "to long race name for a dog";

    // when
    Dog *dog = create_typedef_struct_by_pointer(name, race, 8, 14.55);

    // then
    ck_assert(dog == NULL);
}
END_TEST

Suite *get_struct_suite(void) {
    Suite *struct_suite = suite_create("Struct suite");
    TCase *struct_tc = tcase_create("Struct test case");

    tcase_add_checked_fixture(struct_tc, struct_setup, struct_teardown);
    tcase_add_test(struct_tc, is_should_create_struct);
    tcase_add_test(struct_tc, is_should_not_create_struct);
    tcase_add_test(struct_tc, is_should_create_typedef_struct_by_value);
    tcase_add_test(struct_tc, is_should_not_create_typedef_struct_by_value);
    tcase_add_test(struct_tc, is_should_create_typedef_struct_by_pointer);
    tcase_add_test(struct_tc, is_should_not_create_typedef_struct_by_pointer);
    suite_add_tcase(struct_suite, struct_tc);

    return struct_suite;
}