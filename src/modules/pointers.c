#include "pointers.h"
#include <stdio.h>
#include <stdlib.h>

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

void double_pointer_function() {
    char *pointer_str = "this is a pointer string";
    char array_str[25] = "this is an array string";

    change_value(&pointer_str);
    printf("pointer after change call: %s\n", pointer_str);

    char *p_arr = &array_str[0];
    change_value(&p_arr);
    printf("array after change call: %s\n", pointer_str);
}

void change_value(char **str) {
    printf("%s\n", *str);
    *str = "new string";
}