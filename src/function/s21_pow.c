#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  double long res = 1;
  if (exp != exp) {
    res = exp;
  } else if (exp >= S21_LLONG_MAX && s21_fabs(base) < EPS_6) {
    res = 0;
  } else if ((exp <= S21_LLONG_MIN || exp >= S21_LLONG_MAX) &&
             s21_fabs(base) == 1) {
    res = 1;
  } else if (exp <= S21_LLONG_MIN && base > 0.0) {
    res = 0;
  } else if ((base >= S21_LLONG_MAX || base <= S21_LLONG_MIN) && exp < 0) {
    res = 0;
  } else if (exp <= S21_LLONG_MIN || base <= S21_LLONG_MIN) {
    res = S21_INF;
  } else if (exp >= S21_LLONG_MAX || base >= S21_LLONG_MAX) {
    res = S21_INF;
  } else if (base == 0) {
    res = 0;
  } else if ((int)exp == exp) {
    for (int deg = s21_fabs(exp); deg >= 1; deg--) {
      res *= base;
    }
    if (exp < 0) {
      res = 1 / res;
    }
  } else {
    res = s21_exp(exp * s21_log(base));
  }

  return res;
}