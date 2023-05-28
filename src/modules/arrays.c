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
    int int_array[100];
    int array_length = sizeof(int_array) / sizeof(int_array[0]);
    int i;

    for (i = 0; i < array_length; i++) {
        int_array[i] = i;
    }

    for (i = 0; i < array_length; i++) {
        printf("%d \n", int_array[i]);
    }
}

void char_array() {
    char characters[] = "Hello World!";
    int i;
    printf("%s \n", characters);

    for (i = 0; characters[i] != '\0'; i++) {
        printf("%c", characters[i]);
    }

    printf("\n");
}