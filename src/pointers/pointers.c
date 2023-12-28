#include "pointers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * -> return the value of the variable pointed;
 & -> return the the memory address of a variable (that a pointer can store).
 pointer without anything return the address it is pointing (the address of the variable pointed).
*/

void pointers() {
    int var = 1;
    int *p = &var;

    printf("value of var = %d\n", var);
    printf("address of var = %p\n", &var);

    printf("value of p = %p \n", p);
    printf("value of where p is pointing = %d \n", *p);
    printf("address of p = %p \n", &p);

    printf("\n");

    int alpha = 4;
    int beta = 7;
    int *pointer;

    pointer = &alpha;
    printf("alpha -> %d, beta -> %d, pointer -> %p \n", alpha, beta, pointer);

    beta = *pointer;
    printf("alpha -> %d, beta -> %d, pointer -> %p \n", alpha, beta, pointer);

    *pointer = 5; // assign new value to the variable pointed
    (*pointer)++; // increment value of the variable pointed
    printf("alpha -> %d, beta -> %d, pointer -> %p \n", alpha, beta, pointer);
}

void pointer_array() {
    char letters[4] = {'a', 'b', 'c', '\0'};

    puts("array indexing");
    printf("%c\n", letters[0]);
    printf("%c\n", letters[1]);
    printf("%c\n", letters[2]);

    puts("pointers Arithmetic");
    printf("%c\n", *(letters));
    printf("%c\n", *(letters + 1));
    printf("%c\n", *(letters + 2));
}

void swap(int *apt, int *bpt) {
    int temp;
    temp = *apt;
    *apt = *bpt;
    *bpt = temp;
}

void pass_double_pointer_string_to_function() {
    char *pointer_str = (char *)malloc(25);
    strcpy(pointer_str, "this is a pointer string");

    char array_str[25] = "this is an array string";

    update_double_pointer_string(&pointer_str);
    printf("pointer after change call: %s\n", pointer_str);

    char *array_str_pointer = &array_str[0];
    update_double_pointer_string(&array_str_pointer);
    printf("array after change call: %s\n", pointer_str);
}

void update_double_pointer_string(char **str) {
    printf("%s\n", *str);
    *str = "new string";
}

void pass_single_pointer_string_to_function() {
    char *str = (char *)malloc(50);
    strcpy(str, "this is a pointer string");

    size_t str_length = strlen(str);

    printf("--> before passing to function: \n");
    printf("string length = %lu\n", str_length);
    printf("string content: %s\n", str);
    printf("address of pointed string = %p\n", str);
    printf("address of pointer = %p\n", &str);

    update_single_pointer_string(str);

    printf("--> after passing to function: \n");
    printf("string content: %s\n", str);
}

void update_single_pointer_string(char *str) {
    char *new_str = (char *)malloc(25);
    strcpy(new_str, "hello new!");

    size_t new_str_length = strlen(new_str);

    for (int i = 0; i <= new_str_length; i++) {
        *(str + i) = *(new_str + i);
    }

    size_t str_length = strlen(str);

    printf("--> inside function: \n");
    printf("string length = %lu\n", str_length);
    printf("string content: %s\n", str);
    printf("address of pointed string = %p\n", str);
    printf("address of pointer = %p\n", &str);
}

void func_1() {
    puts("I'm function 1");
}

void func_2() {
    puts("I'm function 2");
}

void func_3() {
    puts("I'm function 3");
}

void call_function_pointers() {
    function_pointer function_list[] = {func_1, func_2, func_3};
    int function_list_size = 3;
    FunctionsContainer all_functions = {.function_list = function_list, .function_list_size = function_list_size};

    for (int i = 0; i < function_list_size; i++) {
        all_functions.function_list[i]();
    }
}