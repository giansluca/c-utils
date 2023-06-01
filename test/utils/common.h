#include <check.h>

void tc_setup();
void tc_teardown();

Suite *get_basic_suite();
Suite *get_structs_suite();
Suite *get_arrays_suite();
Suite *get_pointers_suite();
Suite *get_malloc_suite();