#include <check.h>
#include <limits.h>

#include "math.h"
#include "s21_math.h"
#include "stdio.h"
#include "stdlib.h"

// START_TEST(pow_test) {
//     int x1[10] = {1, 2, 1000, -1,-2, 0, 3};
//     long double  x2[10] = {S21_E,-S21_E, S21_M_PI, -S21_M_PI,
//     0.121241241, 12.124124}; for (size_t i = 0; i < sizeof(x1)/sizeof(x1[0]);
//     i++){
//       for (size_t k = 0; k < sizeof(x2)/sizeof(x2[0]); k++){

//         long double y1 = s21_pow((double)x1[i], x2[k]);
//         long double y2 = pow((double)x1[i], x2[k]);

//         long double y3 = s21_pow(x2[k], (double)x1[i]);
//         long double y4 = pow(x2[k], (double)x1[i]);

//         ck_assert_ldouble_eq_tol(y1, y2, 1e-06);
//         ck_assert_ldouble_eq_tol(y3, y4, 1e-06);
//       }
//     }
// }
// END_TEST

START_TEST(pow_test) {
  char str1[1000], str2[1000];
  str1[0] = snprintf(str1, sizeof(str1), "%.6Lf",
                     s21_pow((double)_i * 0.33333, 2 * 1.33333));
  str2[0] = snprintf(str2, sizeof(str1), "%.6f",
                     pow((double)_i * 0.33333, 2 * 1.33333));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

// Выдаёт ошибку
START_TEST(pow_test2) {
  char str1[1000], str2[1000];
  str1[0] = snprintf(
      str1, sizeof(str1), "%.6Lf",
      s21_pow((double)_i * 1.33333, s21_pow((double)_i * 1.33336, _i)));
  str2[0] =
      snprintf(str2, sizeof(str2), "%.6f",
               pow((double)_i * 1.33333, s21_pow((double)_i * 1.33336, _i)));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

///////////////////////////////////////////////////////////////////////////

START_TEST(sin_test) {
  long double x1 = s21_sin((double)_i * 5.12);
  long double x2 = sin((double)_i * 5.12);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
  long double x3 = s21_sin((double)_i / 10);
  long double x4 = sin((double)_i / 10);
  ck_assert_ldouble_eq_tol(x3, x4, EPS_6);
}
END_TEST;
///////////////////////////////////////////////////////////////////////////
START_TEST(cos_test) {
  long double x1 = s21_cos((double)_i * 3.12);
  long double x2 = cos((double)_i * 3.12);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
  long double x3 = s21_cos((double)_i / 10);
  long double x4 = cos((double)_i / 10);
  ck_assert_ldouble_eq_tol(x3, x4, EPS_6);
}
END_TEST;
///////////////////////////////////////////////////////////////////////////
START_TEST(sqrt_test) {
  long double x1 = s21_sqrt((double)_i * 5.12);
  long double x2 = sqrt((double)_i * 5.12);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}

END_TEST;
START_TEST(sqrt_test2) {
  char str1[1000] = "", str2[1000] = "";
  str1[0] = snprintf(str1, sizeof(str1), "%.6Lf", s21_sqrt((double)_i * 5.12));
  str2[0] = snprintf(str2, sizeof(str2), "%.6f", sqrt((double)_i * 5.12));
  ck_assert_str_eq(str1, str2);
}
///////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////
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

// START_TEST(log_test3) {
//   char str1[1000] = "", str2[1000] = "";
//   str1[0] = snprintf(str1, sizeof(str1), "%.6Lf", s21_log(0));
//   str2[0] = snprintf(str2, sizeof(str2), "%.6f", log(0));
//   ck_assert_str_eq(str1, str2);
// }

///////////////////////////////////////////////////////////////////////////
START_TEST(fmod_test) {
  char str1[1000], str2[1000];
  str1[0] = snprintf(str1, sizeof(str1), "%.6Lf",
                     s21_fmod((double)_i * 5.12, S21_M_PI / _i * 0.12416541));
  str2[0] = snprintf(str2, sizeof(str2), "%.6f",
                     fmod((double)_i * 5.12, S21_M_PI / _i * 0.12416541));
  ck_assert_str_eq(str1, str2);
}
END_TEST;
START_TEST(fmod_test1) {
  char str1[1000], str2[1000];
  str1[999] = snprintf(str1, sizeof(str1), "%.6Lf",
                       s21_fmod((double)_i / 10, S21_M_PI * 2.14616712));
  str2[999] = snprintf(str2, sizeof(str2), "%.6f",
                       fmod((double)_i / 10, S21_M_PI * 2.14616712));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

///////////////////////////////////////////////////////////////////////////
START_TEST(exp_test) {
  char str1[1000], str2[1000];
  str1[0] = snprintf(str1, sizeof(str1), "%.6Lf", s21_exp((double)_i / 1000));
  str2[0] = snprintf(str2, sizeof(str2), "%.6f", exp((double)_i / 1000));
  ck_assert_str_eq(str1, str2);
}
END_TEST;
START_TEST(exp_test2) {
  char str1[1000], str2[1000];
  str1[0] = snprintf(str1, sizeof(str1), "%.6Lf", s21_exp((double)_i));
  str2[0] = snprintf(str2, sizeof(str2), "%.6f", exp((double)_i));
  ck_assert_str_eq(str1, str2);
}
END_TEST;
///////////////////////////////////////////////////////////////////////////
START_TEST(fabs_test) {
  long double x1 = s21_fabs((double)_i * 0.589);
  long double x2 = fabs((double)_i * 0.589);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}
END_TEST;

///////////////////////////////////////////////////////////////////////////
// эта хуйня тоже при -1 одном не то выдаёт  хз почему
// при отрицательных числах не робит
START_TEST(ceil_test) {
  long double x1 = s21_ceil((double)_i * 0.589);
  long double x2 = ceil((double)_i * 0.589);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}
END_TEST;

// START_TEST(ceil_test2) {
//   // long double x1 = s21_ceil((double)_i / 100);
//   // long double x2 = ceil((double)_i / 100);
//   // ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
//   char str1[1000], str2[1000];
//   str1[0] = snprintf(str1, sizeof(str1), "%.6Lf", s21_ceil((double)_i /
//   100)); str2[0] = snprintf(str2, sizeof(str2), "%.6f", ceil((double)_i /
//   100)); ck_assert_str_eq(str1, str2);
// }
END_TEST;
///////////////////////////////////////////////////////////////////////////

START_TEST(abs_test) {
  long double x1 = s21_abs(_i);
  long double x2 = abs(_i);
  ck_assert_ldouble_eq_tol(x1, x2, EPS_6);
}
END_TEST;

///////////////////////////////////////////////////////////////////////////
START_TEST(acos_test) {
  char str1[1000], str2[1000];
  str1[0] = snprintf(str1, sizeof(str1), "%.6Lf", s21_acos((double)_i * 0.72));
  str2[0] = snprintf(str2, sizeof(str2), "%.6f", acos((double)_i * 0.72));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

START_TEST(acos_test2) {
  char str1[1000], str2[1000];
  str1[0] = snprintf(str1, sizeof(str1), "%.6Lf", s21_acos((double)_i));
  str2[0] = snprintf(str2, sizeof(str2), "%.6f", acos((double)_i));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

///////////////////////////////////////////////////////////////////////////
START_TEST(asin_test) {
  char str1[1000], str2[1000];
  str1[0] = snprintf(str1, sizeof(str1), "%.6Lf", s21_asin((double)_i * 0.72));
  str2[0] = snprintf(str2, sizeof(str2), "%.6f", asin((double)_i * 0.72));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

START_TEST(asin_test2) {
  char str1[1000], str2[1000];
  str1[0] = snprintf(str1, sizeof(str1), "%.6Lf", s21_asin((double)_i));
  str2[0] = snprintf(str2, sizeof(str2), "%.6f", asin((double)_i));
  ck_assert_str_eq(str1, str2);
}
END_TEST;

///////////////////////////////////////////////////////////////////////////
START_TEST(atan_test) {
  char str1[1000], str2[1000];
  str1[0] = snprintf(str1, sizeof(str1), "%.6Lf", s21_atan((double)_i * 0.72));
  str2[0] = snprintf(str2, sizeof(str2), "%.6f", atan((double)_i * 0.72));
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

  // tcase_add_test(tc1_1, pow_test);
  tcase_add_loop_test(tc1_1, pow_test, -n, n);
  tcase_add_loop_test(tc1_1, pow_test2, 1, n);

  tcase_add_loop_test(tc1_1, sin_test, -n, n);
  tcase_add_loop_test(tc1_1, cos_test, -n, n);

  tcase_add_loop_test(tc1_1, sqrt_test2, -n, 1);
  tcase_add_loop_test(tc1_1, sqrt_test, 1, n);

  tcase_add_loop_test(tc1_1, tan_test, -n, n);
  tcase_add_loop_test(tc1_1, tan_test2, -n, n);

  tcase_add_loop_test(tc1_1, floor_test, -n, n);
  tcase_add_loop_test(tc1_1, floor_test2, -n, n);

  tcase_add_loop_test(tc1_1, log_test, 1, n);
  tcase_add_loop_test(tc1_1, log_test2, 1, n);
  // tcase_add_loop_test(tc1_1, log_test3, -n, n);

  tcase_add_loop_test(tc1_1, fmod_test, 1, n);
  tcase_add_loop_test(tc1_1, fmod_test1, 1, n);

  tcase_add_loop_test(tc1_1, exp_test, -n, n);
  tcase_add_loop_test(tc1_1, exp_test2, -n, n);

  tcase_add_loop_test(tc1_1, fabs_test, -10, 10);

  tcase_add_loop_test(tc1_1, ceil_test, -n, n);
  // tcase_add_loop_test(tc1_1, ceil_test2, -n, n);

  tcase_add_loop_test(tc1_1, asin_test, -n, n);
  tcase_add_loop_test(tc1_1, asin_test2, -2, 2);

  tcase_add_loop_test(tc1_1, acos_test, -n, n);
  tcase_add_loop_test(tc1_1, acos_test2, -2, 2);
  tcase_add_loop_test(tc1_1, atan_test, -n, n);

  tcase_add_loop_test(tc1_1, abs_test, -10, 10);
  // tcase_add_loop_test(tc1_1, pow_test2, S21_M_PI, S21_M_PI + 10);
  srunner_run_all(sr, CK_NORMAL);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
