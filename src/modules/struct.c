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

    size_t title_length = strlen(title);
    if (title_length > 100) {
        printf("Title size is bigger than 100 chars, Abort! \n");
        exit(-1);
    }

    // i need to use strcpy, i can't assign a string directly
    strcpy(book.title, title);
    strcpy(book.author, author);
    book.year = year;
    book.price = price;

    return book;
}

/**
 * Typedef Struct - it define a new variable type, return value
 */
Dog create_typedef_struct_value(char *name, char *race, int age, float weight) {
    Dog dog;

    strcpy(dog.name, name);
    dog.race = race;
    dog.age = age;
    dog.weight = weight;

    return dog;
}

/**
 * Typedef Struct - it define a new variable type, return pointer
 */
Dog *create_typedef_struct_pointer(char *name, char *race, int age, float weight) {
    Dog *dog = (Dog *)malloc(sizeof(Dog));

    strcpy(dog->name, name);
    dog->race = race;
    dog->age = age;
    dog->weight = weight;

    return dog;
}