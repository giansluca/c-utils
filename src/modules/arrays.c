#include "arrays.h"
#include <stdio.h>

void array() {
    // brace-enclose initialization
    char digits[4] = {'1', '2', '3', '\0'};
    // string literal initialization
    char letters[4] = "abc";

    printf("digits: %p\n", digits);
    printf("letters: %p\n", letters);

    // the array name is an address
    // an array is the address of its first element, thus it is assignable to a pointer
    char *letter_p;
    letter_p = letters;
    printf("letter_p 1: %p\n", letter_p);

    // further evidence
    letter_p = &letters[0];
    printf("letter_p 2: %p\n", letter_p);
}

void integer_array() {
    int int_array[10];
    int array_length = sizeof(int_array) / sizeof(int_array[0]);
    int i;
    int *p = &int_array[0];

    for (i = 0; i < array_length; i++) {
        int_array[i] = i + 10;
        printf("int_array[%d] = %d\n", i, int_array[i]);
    }

    printf("\n");

    for (i = 0; i < array_length; i++) {
        printf("*(p + %d) : %d\n", i, *(p + i));
    }
}

void char_array() {
    char characters1[] = "hello char array 1";
    char *characters2 = "hello char array 2";
    int i;

    printf("%s \n", characters1);
    for (i = 0; characters1[i] != '\0'; i++) {
        printf("%c", characters1[i]);
    }
    printf("\n");

    printf("%s \n", characters2);
    for (i = 0; *(characters2 + i) != '\0'; i++) {
        printf("%c", *(characters2 + i));
    }
    printf("\n");
}