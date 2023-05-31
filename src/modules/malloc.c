#include "malloc.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void malloc_example() {
    int elements = 100;

    printf("array number elements: %d \n", elements);
    int *array = (int *)malloc(sizeof(int) * elements);

    if (array == NULL) {
        printf("memory error\n");
        exit(1);
    }

    int allocated_bytes = sizeof(int) * elements;

    int i;
    for (i = 0; i < elements; i++) {
        array[i] = i;
    }

    printf("elements value: \n");
    for (i = 0; i < elements; i++)
        printf("%d %c\n", *(array + i), i % 10 == 9 ? '>' : ' ');

    int *p = &array[4];

    printf("element 4 of array: %d \n", *p);
    printf("elements number: %d\n", elements);
    printf("element size: %lu bytes\n", sizeof(int));
    printf("bytes allocated: %d\n", allocated_bytes);

    free(array);
}

void realloc_example() {
    int block_elements = 3;
    printf("elements in a block: %d\n", block_elements);

    int int_byte_size = sizeof(int);
    int block_byte_size = block_elements * int_byte_size;
    printf("element size: %d bytes\n", int_byte_size);
    printf("block size: %d bytes\n", block_byte_size);

    int *array = (int *)malloc(block_byte_size);
    if (array == NULL) {
        printf("memory not sufficient");
        exit(1);
    }

    int allocated_bytes = block_byte_size;
    printf("allocated: %d bytes \n", allocated_bytes);
    printf("input integer terminated with #\n");

    int input;
    int used_bytes = 0;
    int i = 0;
    int n = 0;
    while (scanf("%d", &input)) {
        used_bytes += int_byte_size;

        if (used_bytes > allocated_bytes) {
            allocated_bytes += block_byte_size;

            printf("allocating new space calling realloc ...\n");
            array = (int *)realloc(array, allocated_bytes);

            if (array == NULL) {
                printf("memory not sufficient\n");
                exit(1);
            }
            i++;
        }

        array[n++] = input;
    }

    printf("\n");
    printf("allocated: %d bytes\n", allocated_bytes);
    printf("used: %d bytes\n", used_bytes);
    printf("realloc calls: %d\n", i);
    printf("numbers: %d\n", n);

    int j;
    for (j = 0; j < n; j++)
        printf("%d\n", array[j]);
}
