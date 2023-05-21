#include <stdlib.h>

#include "./modules/test_basic.h"
#include "./modules/test_struct.h"

int main(void) {
    int number_failed;

    Suite *basic_suite = get_basic_suite();
    Suite *struct_suite = get_struct_suite();

    SRunner *srunner = srunner_create(basic_suite);
    srunner_add_suite(srunner, struct_suite);

    srunner_run_all(srunner, CK_VERBOSE);
    number_failed = srunner_ntests_failed(srunner);
    srunner_free(srunner);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}