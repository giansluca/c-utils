#include <ctype.h>  /* testing and mapping characters .. toupper() */
#include <stdio.h>  /* input output */
#include <stdlib.h> /* exit */
#include <string.h> /* memcpy, memset */

#include "../include/basic.h"

/**
 * Useful functions
 *
 * int strcmp(const char *str1, const char *str2) --> compares two strings, return 0 if they are equals
 * char *strcpy(char *dest, const char *src) --> copies the string pointed by src to dest
 * char *strncpy(char *dest, const char *src, size_t n) --> copies copies up to n characters from the string
 *      pointed to, by src to dest
 * char *strcat(char *dest, const char *src) --> appends the string pointed by src to the end to dest
 * int strlen(const char *str) --> return the length of a string (only string)
 * int sizeof(var) --> returns the size in bytes of a variable type. sizeof(a). If 'a' is integer it will return 4
 * void *memset(void *str, int c, size_t n) --> copies the character c (an unsigned char)
 *      to the first n characters of the string pointed to by the argument str
 * void *memcpy(void *str1, const void *str2, size_t n) --> copies n characters from memory area
 *      str2 to memory area str1
 * int sprintf(char *str, const char *format, ...) --> sends formatted output to a string pointed by str
 * char *strchr(const char *str, int c) --> searches for the first occurrence of the character c
 *      (an unsigned char) in the string pointed to by the argument str. Return NULL if the character is not found
 * char *strtok(char *str, const char *delim) --> breaks string str into a series of tokens using the delimiter delim
 * void *memmove(void *str1, const void *str2, size_t n) --> copies n characters from str2 to str1,
 *      but for overlapping memory blocks, memmove() is a safer approach than memcpy().
 */

/**
 * Basic print operations
 */
void basic_operations() {
    int a = 2;
    int b = 6;
    int c;
    double a1 = 7.0;
    double a2 = 2.3;
    double a3;
    char character = 'r';

    c = b / a;
    a3 = a1 / a2;

    printf("value of var a: %d \n", a);
    printf("value of var b: %d \n", b);
    printf("value of var c: %d \n", c);
    printf("value of var character: %c \n", character);
    printf("\n");
    printf("value of var a3: %f \n", a3);
}

/**
 * Scanf example
 * if / else ternary operator
 */
void scanf_integer() {
    int max;
    int first;
    int second;

    printf("insert first number: ");
    scanf("%d", &first);
    printf("insert second number: ");
    scanf("%d", &second);

    max = (first > second) ? first : second;

    printf("inserted numbers: %d, %d \n", first, second);
    printf("max is: %d \n", max);
}

/**
 * Scanf example
 * check character, if i scan only one character i need to put a blank space
 * before the placeholder " %c"
 */
void scanf_character() {
    int i = 0;
    char secret_char = 'u';
    char input;

    while (i != 10) {
        fflush(stdin);
        printf("try to guess the secret character: ");
        scanf(" %c", &input);
        if (input == secret_char) {
            printf("correct!\n");
            i = 10;
        } else {
            printf("the character %c is wrong\n", input);
        }
    }
}

/**
 * Scanf example, with scanf is not allowed the 'SPACE' character
 * toupper example
 */
void scanf_string_and_uppercase() {
    char string[100];

    printf("insert string: ");
    scanf("%s", string);

    size_t string_len = strlen(string) + 1;
    char *up_string = malloc(sizeof(char) * string_len);
    strcpy(up_string, string);

    for (int i = 0; up_string[i] != '\0'; i++) {
        if (up_string[i] >= 'a' && up_string[i] <= 'z') {
            up_string[i] = toupper(up_string[i]);
        }
    }

    printf("inserted string: %s \n", string);
    printf("inserted string uppercase: %s \n", up_string);

    free(up_string);
}

/**
 * With getchar and putchar is allowed the 'SPACE' character
 */
void get_put_char() {
    int max = 3000;
    char string[max];
    char ch = '\0';
    int i = 0;

    printf("insert string: ");
    while (ch != '\n') {
        ch = getchar();
        string[i] = ch;
        i++;
    }
    string[i] = '\0';

    printf("string inserted: ");
    i = 0;
    while (string[i] != '\0') {
        putchar(string[i]);
        i++;
    }
}

/**
 * Increment static variable
 */
void static_variable() {
    // static variable in C keeps its state over calls
    for (int i = 0; i < 3; i++) {
        int alpha = 0;
        static int beta = 0;
        printf("(int) alfa = %d, (static int) beta = %d \n", alpha, beta);

        ++alpha;
        ++beta;
    }
}

/**
 * Do while loop
 */
void do_while_loop() {
    int value = 0;
    do {
        printf("Press 1 to continue : ");
        scanf("%d", &value);
        printf("\n");
    } while (value != 1);

    printf("Out of the loop\n");
}

/**
 * For loop test
 */
void for_loop() {
    for (int i = 0; i <= 100; i++) {
        printf("n: %d \n", i);
    }

    printf("Out of the loop\n");
}

/**
 * while loop test with break and continue
 */
void while_loop() {
    int value;
    while (scanf("%d", &value) == 1 && value != 0) {
        if (value < 0) {
            printf("value not allowed \n");
            break;
            // exit the loop
        }

        if (value > 100) {
            printf("value not allowed \n");
            continue;
            // skip one iteration
        }

        int power = value * value;
        printf("Power:  %d \n", power);
    }
}

/**
 * Switch case
 */
void switch_case() {
    int number;

    printf("Insert a number : ");
    scanf("%d", &number);

    switch (number) {
    case 0:
        printf("Zero \n");
        break;
    case 1:
        printf("One \n");
        break;
    case 2:
        printf("Two \n");
        break;
    default:
        printf("Big positive value \n");
        break;
    }
}

/**
 * Check between strings whit scanf e strcmp
 */
void guess_word() {
    int i = 0;
    char array[6] = "hello";
    char input[6];

    while (i != 9000) {
        // base array length (array = hello)
        int length_array = sizeof(array) / sizeof(array[0]);

        for (int i = 0; i < length_array; i++) {
            printf("%c", array[i]);
        }

        printf("\n");

        // get input
        fflush(stdin);
        printf("Try to guess the secret word: ");
        scanf("%s", input);

        // check input
        int result = strcmp(input, array);
        if (result == 0) {
            printf("Yes!!! \n");
            i = 9000;
        } else {
            printf("the word %s is wrong\n", input);
        }
    }
}

/**
 * Casting example, advised explicit casting on arithmetic operations
 */
void casting() {
    // from float to int
    float rational_1 = 47.19;
    int integer_1 = (int)rational_1;
    printf("Rational 1: %f \n", rational_1);
    printf("Integer 1: %d \n", integer_1);
    printf("\n");

    // from int to float
    int integer_2 = 18;
    float rational_2 = (float)integer_2;
    printf("Integer 2: %d \n", integer_2);
    printf("Rational 2: %f \n", rational_2);
    printf("\n");

    // from char to int
    int character = 'A';
    int integer_3 = (int)character;
    printf("Character: %c \n", character);
    printf("Integer 3: %d \n", integer_3); // it is 65, the ASCII value of A
    printf("\n");
}

/**
 * enumerations
 */
enum days enumerations(char *day_name) {
    if (strcmp(day_name, "monday") == 0) {
        return mon;
    } else if (strcmp(day_name, "tuesday") == 0) {
        return tue;
    } else if (strcmp(day_name, "wednesday") == 0) {
        return wen;
    } else if (strcmp(day_name, "thursday") == 0) {
        return thu;
    } else if (strcmp(day_name, "friday") == 0) {
        return fri;
    } else if (strcmp(day_name, "saturday") == 0) {
        return sat;
    } else if (strcmp(day_name, "sunday") == 0) {
        return sun;
    } else {
        return 0;
    }
}

/**
 * Arrays
 */
void test_array() {
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

/**
 * Integer array
 */
void test_integer_array() {
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

/**
 * Char array
 */
void test_char_array() {
    char characters[] = "Hello World!";
    int i;
    printf("%s \n", characters);

    for (i = 0; characters[i] != '\0'; i++) {
        printf("%c", characters[i]);
    }

    printf("\n");
}

/**
 * Pointers
 */
void test_pointers() {
    // * return the value of the variable pointed;
    // & return the the memory address of a variable (that a pointer can store).
    // pointer without anything return the address it is pointing (the address of the variable pointed).

    int i = 1;
    int *p;

    printf("Value of i = %d\n", i);
    printf("Address of i = %p\n", &i);
    p = &i;

    printf("Value of p = %p \n", p);
    printf("value of where p is pointing = %d \n", *p);
    printf("Address of p = %p \n", &p);

    printf("----------------------------------------------\n");

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

/**
 * Array and pointers
 */
void test_pointer_array() {
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

/**
 * Test pointer to function
 */
void test_pointer_function() {
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

/**
 * Test double pointer to function
 */
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

/**
 * Struct and pointers and malloc
 */
void test_pointer_struct() {
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

/**
 * Malloc example
 */
void test_malloc() {
    int elements = 100;

    printf("Array number elements: %d \n", elements);
    int *array = (int *)malloc(sizeof(int) * elements);

    if (array == NULL) {
        printf("memory error\n");
        exit(1);
    }

    int allocated = sizeof(int) * elements;

    int i;
    for (i = 0; i < elements; i++) {
        array[i] = i;
    }

    printf("elements value\n");

    for (i = 0; i < elements; i++) {
        printf("%d %c\n", array[i], i % 10 == 9 ? 'n' : ' ');
        // printf("%d %c\n", *(array + i), i%10 == 9 ? 'n' : ' '); // other way to access the pointer array
    }

    int *p = &array[4];
    printf("Element 4 of array %d \n", *p);

    printf("Elements number %d\n", elements);
    printf("Element size %lu\n", sizeof(int));
    printf("Bytes allocated %d\n", allocated);
    printf("Free memory\n");

    free(array);
}

/**
 * Realloc example
 */
void test_realloc() {
    int block_elements = 3;
    printf("Elements in a block: %d\n", block_elements);

    int int_byte_size = sizeof(int);
    int block_byte_size = block_elements * int_byte_size;

    int *array = (int *)malloc(block_byte_size);
    if (array == NULL) {
        printf("Memory nut sufficient");
        exit(1);
    }

    int allocated = block_byte_size;
    printf("Allocated: %d bytes \n", allocated);
    printf("Input integer terminated with # :n \n");

    int input;
    int used_bytes = 0;
    int i = 0;
    int n = 0;
    while (scanf("%d", &input)) {
        used_bytes += int_byte_size;
        if (used_bytes > allocated) {
            allocated += block_byte_size;
            array = (int *)realloc(array, allocated);
            if (array == NULL) {
                printf("Memory not sufficient \n");
                exit(1);
            }
            i++;
        }
        // in this way we can read n integer numbers
        array[n++] = input;
    }

    printf("\n");
    printf("Allocated: %d bytes\n", allocated);
    printf("block size: %d bytes\n", block_byte_size);
    printf("integer size: %d bytes\n", int_byte_size);
    printf("Used: %d bytes\n", used_bytes);
    printf("Realloc calls: %d\n", i);
    printf("Numbers: %d\n", n);

    printf("Numbers\n");

    for (i = 0; i < n; i++) {
        printf("%d %c \n", array[i], i % 10 == 9 ? 'n' : ' ');
    }

    printf("\n");
}
