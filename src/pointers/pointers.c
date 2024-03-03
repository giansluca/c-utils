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
    puts("\n");

    char *pointer_str = (char *)malloc(35);
    strcpy(pointer_str, "this is a pointer string - double");

    size_t str_length_before = strlen(pointer_str);
    printf("--> 1 - Before passing to function: \n");
    printf("string length = %lu\n", str_length_before);
    printf("string content: %s\n", pointer_str);
    printf("address of pointed string = %p\n", pointer_str);
    printf("address of pointer = %p\n", &pointer_str);

    update_double_pointer_string(&pointer_str);

    size_t str_length_after = strlen(pointer_str);
    printf("--> 4 - After passing to function: \n");
    printf("string length = %lu\n", str_length_after);
    printf("string content: %s\n", pointer_str);
    printf("address of pointed string = %p\n", pointer_str);
    printf("address of pointer = %p\n", &pointer_str);

    // -- same but passing a string array instead of a pointer
    // char array_str[25] = "this is an array string";
    // char *array_str_pointer = &array_str[0];
    // update_double_pointer_string(&array_str_pointer);
}

void update_double_pointer_string(char **str) {
    size_t str_length_before = strlen(*str);
    printf("--> 2 - Inside function before update: \n");
    printf("string length = %lu\n", str_length_before);
    printf("string content: %s\n", *str);
    printf("address of pointed string = %p\n", *str);
    printf("address of pointer = %p\n", str);

    char *new_pointer_str = (char *)malloc(15);
    strcpy(new_pointer_str, "new string");
    *str = "new string";

    // --> same
    // *str = new_pointer_str;

    printf("--> 3 - Inside function after update: \n");
    size_t str_length_after = strlen(*str);
    printf("string length = %lu\n", str_length_after);
    printf("string content: %s\n", *str);
    printf("address of pointed string = %p\n", *str);
    printf("address of pointer = %p\n", str);
}

void pass_single_pointer_string_to_function() {
    puts("\n");

    char *str = (char *)malloc(50);
    strcpy(str, "this is a pointer string - single");

    size_t str_length_before = strlen(str);
    printf("--> 1 - Before passing to function: \n");
    printf("string length = %lu\n", str_length_before);
    printf("string content: %s\n", str);
    printf("address of pointed string = %p\n", str);
    printf("address of pointer = %p\n", &str);

    update_single_pointer_string(str);

    size_t str_length_after = strlen(str);
    printf("--> 4 - After passing to function: \n");
    printf("string content: %s\n", str);
    printf("string length = %lu\n", str_length_after);
    printf("address of pointed string = %p\n", str);
    printf("address of pointer = %p\n", &str);
}

void update_single_pointer_string(char *str) {
    size_t str_length_before = strlen(str);
    printf("--> 2 - Inside function before update: \n");
    printf("string length = %lu\n", str_length_before);
    printf("string content: %s\n", str);
    printf("address of pointed string = %p\n", str);
    printf("address of pointer = %p\n", &str);

    // This does not work! - because passing the str single pointer, the the address of the pointed string is passed by value
    // and the address of the pointer live only inside the receiving function --> see the printing
    // the value is changed only inside the function and doesn't affect the original pointer
    char *new_pointer_str = (char *)malloc(25);
    strcpy(new_pointer_str, "very new string");
    str = new_pointer_str;

    // This works - accessing and manipulating pointed elements directly
    // size_t new_str_length = strlen(new_pointer_str);
    // for (int i = 0; i <= new_str_length; i++) {
    //     *(str + i) = *(new_pointer_str + i);
    // }

    size_t str_length_after = strlen(str);
    printf("--> 3 - Inside function after update: \n");
    printf("string length = %lu\n", str_length_after);
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