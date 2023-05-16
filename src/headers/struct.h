#ifndef C_UTILS_STRUCT_HEADER_H
#define C_UTILS_STRUCT_HEADER_H

struct Book {
    char title[100];
    char author[50];
    int year;
    double price;
};

typedef struct {
    char name[100];
    char *race;
    int age;
    float weight;
} Dog;

struct Book create_struct(char *title, char *author, int year, double price);
Dog create_typedef_struct_value(char *name, char *race, int age, float weight);
Dog *create_typedef_struct_pointer(char *name, char *race, int age, float weight);

#endif // C_UTILS_STRUCT_HEADER_H