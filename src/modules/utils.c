#include <ctype.h>  /* testing and mapping characters .. toupper() */
#include <stdio.h>  /* input output */
#include <stdlib.h> /* exit */
#include <string.h> /* memcpy, memset */

#include "../headers/utils.h"

/**
 * Useful functions
 *
 * int strcmp(const char *str1, const char *str2) --> compares two strings, return 0 if they are equals
 *
 * char *strcpy(char *dest, const char *src) --> copies the string pointed by src to dest
 *
 * char *strcat(char *dest, const char *src) --> appends the string pointed by src to the end to dest
 *
 * int strlen(const char *str) --> return the length of a string (only string)
 *
 * int sizeof(var) --> returns the size in bytes of a variable type. sizeof(a). If 'a' is integer it will return 4
 *
 * void *memset(void *str, int c, size_t n) --> copies the character c (an unsigned char)
 * to the first n characters of the string pointed to by the argument str
 *
 * void *memcpy(void *str1, const void *str2, size_t n) --> copies n characters from memory area
 * str2 to memory area str1
 *
 * int sprintf(char *str, const char *format, ...) --> sends formatted output to a string pointed by str
 *
 * char *strchr(const char *str, int c) --> searches for the first occurrence of the character c
 * (an unsigned char) in the string pointed to by the argument str. Return NULL if the character is not found
 *
 * char *strtok(char *str, const char *delim) --> breaks string str into a series of tokens using
 * the delimiter delim
 *
 * void *memmove(void *str1, const void *str2, size_t n) --> copies n characters from str2 to str1,
 * but for overlapping memory blocks, memmove() is a safer approach than memcpy().
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

    printf("Value of var a: %d \n", a);
    printf("Value of var b: %d \n", b);
    printf("Value of var c: %d \n", c);
    printf("Value of var character: %c \n", character);
    printf("\n");
    printf("Value of var a3: %f \n", a3);
}

/**
 * Scanf example, with scanf is not allowed the 'SPACE' character
 * toupper example
 */
void scanf_example() {
    char string[99];
    char a = 'd';

    printf("Insert string: ");
    scanf("%s", string);
    printf("String inserted: %s \n", string);
    printf("Character upper transform: %c \n", toupper(a));
}

/**
 * Scanf example
 * if / else ternary operator
 */
void scanf_example_2() {
    int max;
    int first;
    int second;

    printf("Insert first number: ");
    scanf("%d", &first);
    printf("insert second number: ");
    scanf("%d", &second);

    max = (first > second) ? first : second;

    printf("numbers inserted: %d %d \n", first, second);
    printf("Max is: %d \n", max);
}

/**
 * Scanf example
 * check character, if i scan only one character i need to put a blank space
 * before the placeholder " %c"
 */
void scanf_example_3() {
    int i = 0;
    char a = 'u';
    char input;

    while (i != 9000) {
        fflush(stdin);
        printf("Try to guess the secret character: ");
        scanf(" %c", &input);
        if (input == a) {
            printf("Correct!\n");
            i = 9000;
        } else {
            printf("The character %c is wrong\n", input);
        }
    }
}

/**
 * Whit getchar and putchar is allowed the 'SPACE' character
 */
void get_put_char_example() {
    int max = 3000;
    char string[max];
    char ch = '\0';
    int i = 0;

    printf("Insert string: ");
    while (ch != '\n') {
        ch = getchar();
        string[i] = ch;
        i++;
    }
    string[i] = '\0';

    i = 0;
    printf("String inserted: ");

    while (string[i] != '\0') {
        putchar(string[i]);
        i++;
    }
}

/**
 * Conditional statement example if, else if, else
 */
void conditional_example() {
    int vote;
    printf("Insert vote: ");
    scanf("%d", &vote);

    if (vote >= 18) {
        printf("Good! you have passed the exam \n");
    } else if (vote >= 15 && vote < 18) {
        printf("You have to do the second part now \n");
    } else {
        printf("You didn't pass the exam, try again \n");
    }
}

/**
 * Increment static variable
 */
void test_static_variable() {
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
 * DoWhile loop test
 */
void test_do_while_loop() {
    int value = 0;
    do {
        printf("Press 1 to continue : ");
        scanf("%d", &value);
        printf("\n");
    } while (value != 1);

    printf("Out of the loop");
}

/**
 * For loop test
 */
void test_for_loop() {
    int i;
    for (i = 0; i <= 100; i++) {
        printf("n: %d \n", i);
    }

    printf("Out of the loop");
}

/**
 * while loop test with break and continue
 */
void test_while_loop() {
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
 * Switch example
 */
void test_switch() {
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
 * char array initialized as a String and printer as a String
 * and as a char array as well
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
 * Two dimension Array (matrix)
 */
void test_multi_dim_array() {
    int n = 10;
    int m = 12;
    int matrix[n][m];
    int i;
    int j;

    for (i = 0; i < m; i++) {
        printf("line n. %d \n", i);

        for (j = 0; j < n; j++) {
            printf("%d \n", matrix[i][j]);
        }

        printf("\n");
    }
}

/**
 * Check between strings whit scanf e strcmp
 */
void guess_word() {
    int i = 0;
    char a[5] = "hello";
    char input[6];

    while (i != 9000) {
        // base array length (a = hello)
        int length_array = sizeof(a) / sizeof(a[0]);

        for (int z = 0; z < length_array; z++) {
            printf("%c", a[z]);
        }

        printf("\n");

        // get input
        fflush(stdin);
        printf("Try to guess the secret word: ");
        scanf("%s", input);

        // check input
        int r = strcmp(input, a);
        if (r == 0) {
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
void casting_example() {
    // from float to int
    int integer;
    float rational;
    rational = 47.19;
    integer = (int)rational;
    printf("Number: %f \n", rational);
    printf("Number: %d \n", integer);
    printf("\n");

    // from int to float
    int integer_2;
    float rational_2;
    integer_2 = 18;
    rational_2 = (float)integer_2;
    printf("Number: %f \n", rational_2);
    printf("Number: %d \n", integer_2);
    printf("\n");

    // from char to int
    int integer_3;
    int character;
    character = 'A';
    integer_3 = (int)character;
    printf("Number: %c \n", character);
    printf("Number: %d \n", integer_3); // it is 65, the ASCII value of A
    printf("\n");
}

/**
 * enumerations example
 */
void test_enumerations() {
    enum days { mon = 5,
                tue,
                wen,
                thu,
                fri,
                sat,
                sun };
    enum days week;
    week = wen + 1;

    printf("Day number:  %d \n", week);
}

/**
 * Struct test
 */
void test_struct() {
    struct Book {
        char title[100];
        char author[50];
        int year;
        float price;
    };

    struct Book book_1;

    // i need to use strcpy, i can't assign a string directly
    strcpy(book_1.title, "Beautiful Brighton");
    book_1.year = 2007;
    printf("TITLE: %s \n", book_1.title);
    printf("YEAR: %d \n", book_1.year);
}

/**
 * Typedef Struct test define a new variable type and an array af this new type
 * (i can define it inside the header file)
 */
void test_typedef_struct() {
    typedef struct Book {
        char title[100];
        char author[50];
        int year;
        float price;
    } Book;

    Book big_book;
    big_book.year = 2008;
    printf("Year: %d \n", big_book.year);

    Book small_book[10];
    small_book[3].year = 2006;
    printf("Year: %d \n", small_book[3].year);

    Dog small_dog;
    small_dog.age = 5;
    small_dog.race = "pitbull";
    printf("Age dog: %d \n", small_dog.age);
    printf("race dog: %s \n", small_dog.race);
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
