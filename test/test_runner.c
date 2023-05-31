#include "./modules/utils.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int number_failed;

    Suite *basic_suite = get_basic_suite();
    Suite *structs_suite = get_structs_suite();
    Suite *arrays_suite = get_arrays_suite();
    Suite *pointers_suite = get_pointers_suite();

    SRunner *srunner = srunner_create(basic_suite);
    srunner_add_suite(srunner, structs_suite);
    srunner_add_suite(srunner, arrays_suite);
    srunner_add_suite(srunner, pointers_suite);

    srunner_run_all(srunner, CK_VERBOSE);
    number_failed = srunner_ntests_failed(srunner);
    srunner_free(srunner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}