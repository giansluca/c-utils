#include "structs.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Struct
 */
struct Book create_struct(char *title, char *author, int year, double price) {
    struct Book book;

    size_t title_length = strlen(title);
    size_t author_length = strlen(author);
    if (title_length >= 50 || author_length >= 20) {
        printf("title size or author size is too big, Abort! \n");
        book.isInitialized = false;
        return book;
    }

    // i use strcpy
    strcpy(book.title, title);
    strcpy(book.author, author);
    book.year = year;
    book.price = price;
    book.isInitialized = true;

    return book;
}

/**
 * Typedef Struct - it define a new variable type - return value
 */
Dog create_typedef_struct_by_value(char *name, char *race, int age, float weight) {
    Dog dog;

    size_t name_length = strlen(name);
    size_t race_length = strlen(race);
    if (name_length >= 20 || race_length >= 10) {
        printf("name size or race size is too big, Abort! \n");
        dog.isInitialized = false;
        return dog;
    }

    strcpy(dog.name, name);
    dog.race = race;
    dog.age = age;
    dog.weight = weight;
    dog.isInitialized = true;

    return dog;
}

/**
 * Typedef Struct - it define a new variable type - return pointer
 */
Dog *create_typedef_struct_by_pointer(char *name, char *race, int age, float weight) {
    Dog *dog = (Dog *)malloc(sizeof(Dog));

    if (dog == NULL) {
        return NULL;
    }

    size_t name_length = strlen(name);
    size_t race_length = strlen(race);
    if (name_length >= 200 || race_length >= 10) {
        printf("name size or race size is too big, Abort! \n");
        free(dog);
        return NULL;
    }

    strcpy(dog->name, name);
    dog->race = race;
    dog->age = age;
    dog->weight = weight;
    dog->isInitialized = true;

    return dog;
}