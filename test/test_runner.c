#include "headers/test_utils.h"
#include <stdlib.h>

int main(void) {
    int number_failed;

    Suite *utils_suite = get_utils_suite();
    SRunner *srunner = srunner_create(utils_suite);

    srunner_run_all(srunner, CK_VERBOSE);
    number_failed = srunner_ntests_failed(srunner);
    srunner_free(srunner);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}