#ifndef C_UTILS_BASIC_HEADER_H
#define C_UTILS_BASIC_HEADER_H

enum days {
    sun = 1,
    mon = 2,
    tue = 3,
    wen = 4,
    thu = 5,
    fri = 6,
    sat = 7
};

void basic_operations();
void scanf_integer();
void scanf_character();
void scanf_string_and_uppercase();
void get_put_char();
void static_variable();
void do_while_loop();
void for_loop();
void while_loop();
void switch_case();
void guess_word();
void casting();
enum days enumerations(char *day_name);

/* MEMORY */
void test_malloc();
void test_realloc();

#endif // C_UTILS_BASIC_HEADER_H
