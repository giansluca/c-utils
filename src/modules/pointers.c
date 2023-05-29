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

    printf("Value of var = %d\n", var);
    printf("Address of var = %p\n", &var);

    printf("Value of p = %p \n", p);
    printf("value of where p is pointing = %d \n", *p);
    printf("Address of p = %p \n", &p);

    printf("\n");

    int alpha = 4;
    int beta = 7;
    int *pointer;

    pointer = &alpha;
    printf("alpha -> %d, beta -> %d, pointer -> %p \n", alpha, beta, pointer);

    beta = *pointer;
    printf("alpha -> %d, beta -> %d, pointer -> %p \n", alpha, beta, pointer);

    *pointer = 5;
    printf("alpha -> %d, beta -> %d, pointer -> %p \n", alpha, beta, pointer);
}

void pointer_array() {
    char letters[4] = {'a', 'b', 'c', '\0'};

    puts("Array indexing");
    printf("%c\n", letters[0]);
    printf("%c\n", letters[1]);
    printf("%c\n", letters[2]);

    puts("Pointers Arithmetic");
    printf("%c\n", *(letters));
    printf("%c\n", *(letters + 1));
    printf("%c\n", *(letters + 2));
}

void pointer_function() {
    int alpha = 5;
    int beta = 13;
    printf("alpha -> %d, beta -> %d \n", alpha, beta);
    swap(&alpha, &beta);
    printf("alpha -> %d, beta -> %d \n", alpha, beta);
}

void swap(int *apt, int *bpt) {
    int temp;
    temp = *apt;
    *apt = *bpt;
    *bpt = temp;
}

void pointer_struct() {
    typedef struct Boom {
        int i;
        int j;
        int z;
    } Boom;

    Boom *pointer;
    int *beta = (int *)malloc(sizeof(int));

    Boom var = {1, 2, 3};
    printf("i = %d \n", var.i);
    printf("j = %d \n", var.j);
    printf("z = %d \n", var.z);

    pointer = &var;
    *beta = pointer->j;

    printf(" \n");
    printf("z = %d \n", pointer->z);
    printf("beta = %d \n", *beta);
    printf("address struct = %p \n", pointer);
}

void test_double_pointer_function() {
    char *pointer_str = "This is a pointer string";
    char array_str[25] = "This is an array string";

    change_value(&pointer_str);
    printf("Pointer after change call: %s\n", pointer_str);

    char *p_arr = &array_str[0];
    change_value(&p_arr);
    printf("Array after change call: %s\n", pointer_str);
}

void change_value(char **str) {
    printf("%s\n", *str);
    *str = "New string";
}