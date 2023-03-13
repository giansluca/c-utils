#ifndef TEST_01_TEST_HEADER_H
#define TEST_01_TEST_HEADER_H

typedef struct Dog {
    char name[100];
    char *race;
    int age;
    float weight;
} Dog;

/* BASIC */
void basic_operations();
void scanf_example();
void scanf_example_2();
void scanf_example_3();
void get_put_char_example();
void conditional_example();
void test_static_variable();
void test_do_while_loop();
void test_for_loop();
void test_while_loop();
void test_switch();
void test_char_array();
void test_integer_array();
void test_multi_dim_array();
void guess_word();
void casting_example();
void test_enumerations();

/* STRUCT */
void test_struct();
void test_typedef_struct();

/* POINTERS, ARRAY */
void test_array();
void test_pointers();
void test_pointer_array();
void test_pointer_function();
void swap(int *apt, int *bpt);
void test_double_pointer_function();
void change_value(char **str);
void test_pointer_struct();
void test_malloc();
void test_realloc();

#endif // TEST_01_TEST_HEADER_H
