#ifndef C_UTILS_STRUCTS_HEADER_H
#define C_UTILS_STRUCTS_HEADER_H

#include <stdbool.h>

struct Book {
    char title[50];
    char author[20];
    int year;
    double price;
    bool isInitialized;
};

typedef struct {
    char name[20];
    char *race;
    int age;
    float weight;
    bool isInitialized;
} Dog;

struct Book create_struct(char *title, char *author, int year, double price);
Dog create_typedef_struct_by_value(char *name, char *race, int age, float weight);
Dog *create_typedef_struct_by_pointer(char *name, char *race, int age, float weight);

#endif // C_UTILS_STRUCTS_HEADER_H