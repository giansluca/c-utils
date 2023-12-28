#ifndef C_UTILS_POINTERS_HEADER_H
#define C_UTILS_POINTERS_HEADER_H

typedef void (*function_pointer)(void);

typedef struct {
    function_pointer *function_list;
    int function_list_size;
} FunctionsContainer;

void pointers();
void pointer_array();
void swap(int *apt, int *bpt);
void pass_double_pointer_string_to_function();
void update_double_pointer_string(char **str);
void pass_single_pointer_string_to_function();
void update_single_pointer_string(char *str);
void call_function_pointers();

#endif // C_UTILS_POINTERS_HEADER_H