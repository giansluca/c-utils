#include "functions/test_functions.h"
#include <stdlib.h>

int main(void) {
    int number_failed;

    Suite *suite = functions_suite();
    SRunner *srunner = srunner_create(suite);

    srunner_run_all(srunner, CK_VERBOSE);
    number_failed = srunner_ntests_failed(srunner);
    srunner_free(srunner);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}