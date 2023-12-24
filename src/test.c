#include <check.h>
#include <math.h>

#include "s21_math.h"
#include "stdio.h"
#include "stdlib.h"

static const double exp_test_value[] = {S21_NAN, S21_INF, -S21_INF, -S21_INF, S21_INF, -S21_INF, 1};
static const double base_test_value[] = {0, 0, 1, 1, 1, -1, S21_INF}; 
static const double tan_test_value[] = {S21_M_PI / 6.0, S21_M_PI / 4.0};

START_TEST(pow_test) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf",
           s21_pow((double)_i * 0.33333, 2 * 1.33333));
  snprintf(str2, sizeof(str1), "%.6f", pow((double)_i * 0.33333, 2 * 1.33333));
  ck_assert_str_eq(str1, str2);
}
END_TEST;



START_TEST(pow_test2) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf", s21_pow((double)_i * 1.33333, 3));

  snprintf(str2, sizeof(str2), "%.6f", pow((double)_i * 1.33333, 3));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

START_TEST(pow_test3) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf", s21_pow(base_test_value[_i], exp_test_value[_i]));

  snprintf(str2, sizeof(str2), "%.6f", pow(base_test_value[_i], exp_test_value[_i]));
  ck_assert_str_eq(str1, str2);
}
END_TEST;



START_TEST(sin_test) {
  long double x1 = s21_sin((double)_i * 5.12);
  long double x2 = sin((double)_i * 5.12);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
  long double x3 = s21_sin((double)_i / 10);
  long double x4 = sin((double)_i / 10);
  ck_assert_ldouble_eq_tol(x3, x4, EPS_6);
}
END_TEST;

START_TEST(cos_test) {
  long double x1 = s21_cos((double)_i * 3.12);
  long double x2 = cos((double)_i * 3.12);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
  long double x3 = s21_cos((double)_i / 10);
  long double x4 = cos((double)_i / 10);
  ck_assert_ldouble_eq_tol(x3, x4, EPS_6);
}
END_TEST;

START_TEST(sqrt_test) {
  long double x1 = s21_sqrt((double)_i * 5.12);
  long double x2 = sqrt((double)_i * 5.12);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}

END_TEST;
START_TEST(sqrt_test2) {
  char str1[1000] = "", str2[1000] = "";
  snprintf(str1, sizeof(str1), "%.6Lf", s21_sqrt((double)_i * 5.12));
  snprintf(str2, sizeof(str2), "%.6f", sqrt((double)_i * 5.12));
  ck_assert_str_eq(str1, str2);
}

START_TEST(tan_test) {
  long double x1 = s21_tan((double)_i * 3.33);
  long double x2 = tan((double)_i * 3.33);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}

START_TEST(tan_test2) {
  long double x1 = s21_tan(S21_M_PI * (double)_i);
  long double x2 = tan(S21_M_PI * (double)_i);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}

START_TEST(tan_test3) {
  char str1[1000] = "", str2[1000] = "";

  snprintf(str1, sizeof(str1), "%.6Lf", s21_tan(tan_test_value[_i]));
  snprintf(str2, sizeof(str2), "%.6f", tan(tan_test_value[_i]));
  ck_assert_str_eq(str1, str2);
}


START_TEST(floor_test) {
  long double x1 = s21_floor((double)_i * S21_M_PI);
  long double x2 = floor((double)_i * S21_M_PI);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}

START_TEST(floor_test2) {
  long double x1 = s21_floor((double)_i / 10000);
  long double x2 = floor((double)_i / 10000);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}


// При 0 выдаёт бесконечность вместо -бесконечности в 3 тесте (который
// закоменчен)
START_TEST(log_test) {
  long double x1 = s21_log((double)_i * S21_M_PI);
  long double x2 = log((double)_i * S21_M_PI);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}

START_TEST(log_test2) {
  long double x1 = s21_log((double)_i / 10000);
  long double x2 = log((double)_i / 10000);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}

START_TEST(log_test3) {
  char str1[1000] = "", str2[1000] = "";
  snprintf(str1, sizeof(str1), "%.6Lf", s21_log(0));
  snprintf(str2, sizeof(str2), "%.6f", log(0));
  ck_assert_str_eq(str1, str2);
}


START_TEST(fmod_test) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf",
           s21_fmod((double)_i * 5.12, S21_M_PI / _i * 0.12416541));
  snprintf(str2, sizeof(str2), "%.6f",
           fmod((double)_i * 5.12, S21_M_PI / _i * 0.12416541));
  ck_assert_str_eq(str1, str2);
}
END_TEST;
START_TEST(fmod_test1) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf",
           s21_fmod((double)_i / 10, S21_M_PI * 2.14616712));
  snprintf(str2, sizeof(str2), "%.6f",
           fmod((double)_i / 10, S21_M_PI * 2.14616712));
  ck_assert_str_eq(str1, str2);
}
END_TEST;


START_TEST(exp_test) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf", s21_exp((double)_i / 1000));
  snprintf(str2, sizeof(str2), "%.6f", exp((double)_i / 1000));
  ck_assert_str_eq(str1, str2);
}
END_TEST;
START_TEST(exp_test2) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf", s21_exp((double)_i));
  snprintf(str2, sizeof(str2), "%.6f", exp((double)_i));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

START_TEST(fabs_test) {
  long double x1 = s21_fabs((double)_i * 0.589);
  long double x2 = fabs((double)_i * 0.589);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}
END_TEST;



START_TEST(ceil_test) {
  long double x1 = s21_ceil((double)_i * 0.589);
  long double x2 = ceil((double)_i * 0.589);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}
END_TEST;

START_TEST(ceil_test2) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf", s21_ceil((double)_i / 100));
  snprintf(str2, sizeof(str2), "%.6f", ceil((double)_i / 100));
  ck_assert_str_eq(str1, str2);
}
END_TEST;


START_TEST(abs_test) {
  long double x1 = s21_abs(_i);
  long double x2 = abs(_i);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}
END_TEST;


START_TEST(acos_test) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf", s21_acos((double)_i * 0.72));
  snprintf(str2, sizeof(str2), "%.6f", acos((double)_i * 0.72));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

START_TEST(acos_test2) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf", s21_acos((double)_i));
  snprintf(str2, sizeof(str2), "%.6f", acos((double)_i));
  ck_assert_str_eq(str1, str2);
}
END_TEST;




START_TEST(asin_test) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf", s21_asin((double)_i * 0.72));
  snprintf(str2, sizeof(str2), "%.6f", asin((double)_i * 0.72));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

START_TEST(asin_test2) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf", s21_asin((double)_i));
  snprintf(str2, sizeof(str2), "%.6f", asin((double)_i));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

START_TEST(asin_test3) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf", s21_asin(exp_test_value[_i]));
  snprintf(str2, sizeof(str2), "%.6f", asin(exp_test_value[_i]));
  ck_assert_str_eq(str1, str2);
}
END_TEST;


START_TEST(atan_test) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf", s21_atan((double)_i * 0.72));
  snprintf(str2, sizeof(str2), "%.6f", atan((double)_i * 0.72));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

START_TEST(atan_test1) {
  char str1[1000], str2[1000];
  snprintf(str1, sizeof(str1), "%.6Lf", s21_atan(exp_test_value[_i]));
  snprintf(str2, sizeof(str2), "%.6f", atan(exp_test_value[_i]));
  ck_assert_str_eq(str1, str2);
}
END_TEST;



int main() {
  int n = 5;
  Suite* s1 = suite_create("Core");
  TCase* tc1_1 = tcase_create("Core");
  SRunner* sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);

  tcase_add_loop_test(tc1_1, pow_test, -n, n);
  tcase_add_loop_test(tc1_1, pow_test2, 1, n);
  tcase_add_loop_test(tc1_1, pow_test3, 0, 7);

  tcase_add_loop_test(tc1_1, sin_test, -n, n);
  tcase_add_loop_test(tc1_1, cos_test, -n, n);

  tcase_add_loop_test(tc1_1, sqrt_test2, -n, 1);
  tcase_add_loop_test(tc1_1, sqrt_test, 1, n);

  tcase_add_loop_test(tc1_1, tan_test, -n, n);
  tcase_add_loop_test(tc1_1, tan_test2, -n, n);
  tcase_add_loop_test(tc1_1, tan_test3, 0, 2);

  tcase_add_loop_test(tc1_1, floor_test, -n, n);
  tcase_add_loop_test(tc1_1, floor_test2, -n, n);

  tcase_add_loop_test(tc1_1, log_test, 1, n);
  tcase_add_loop_test(tc1_1, log_test2, 1, n);
  tcase_add_loop_test(tc1_1, log_test3, -n, n);

  tcase_add_loop_test(tc1_1, fmod_test, 1, n);
  tcase_add_loop_test(tc1_1, fmod_test1, 1, n);

  tcase_add_loop_test(tc1_1, exp_test, -n, n);
  tcase_add_loop_test(tc1_1, exp_test2, -n, n);

  tcase_add_loop_test(tc1_1, fabs_test, -10, 10);

  tcase_add_loop_test(tc1_1, ceil_test, -n, n);
  tcase_add_loop_test(tc1_1, ceil_test2, -n, n);

  tcase_add_loop_test(tc1_1, asin_test, -n, n);
  tcase_add_loop_test(tc1_1, asin_test2, -2, 2);
  tcase_add_loop_test(tc1_1, asin_test3, 0, 8);

  tcase_add_loop_test(tc1_1, acos_test, -n, n);
  tcase_add_loop_test(tc1_1, acos_test2, -2, 2);

  tcase_add_loop_test(tc1_1, atan_test, -n, n);
  tcase_add_loop_test(tc1_1, atan_test1, 0, 5);


  tcase_add_loop_test(tc1_1, abs_test, -10, 10);
  tcase_add_loop_test(tc1_1, pow_test2, S21_M_PI, S21_M_PI + 10);
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
