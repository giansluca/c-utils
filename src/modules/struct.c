#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/struct.h"

/**
 * Struct
 */
struct Book create_struct(char *title, char *author, int year, double price) {
    struct Book book;

    // i need to use strcpy, i can't assign a string directly
    strcpy(book.title, title);
    strcpy(book.author, author);
    book.year = year;
    book.price = price;

    return book;
}

/**
 * Typedef Struct - it define a new variable type
 */
void create_typedef_struct() {
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
