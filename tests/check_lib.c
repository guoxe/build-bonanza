#include <check.h>
#include <stdbool.h>
#include <stdlib.h>

#include "lib.h"
#include "rslib.h"

START_TEST(test_foo) { ck_assert_int_eq(square(2), 4); }
END_TEST

START_TEST(test_cube) { ck_assert_int_eq(cube(3), 27); }
END_TEST

static Suite *core_suite(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("Core suite");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_foo);
  tcase_add_test(tc_core, test_cube);
  suite_add_tcase(s, tc_core);
  return s;
}

int main() {
  Suite *s;
  SRunner *sr;
  s = core_suite();
  sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  int number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return !number_failed ? EXIT_SUCCESS : EXIT_FAILURE;
}
