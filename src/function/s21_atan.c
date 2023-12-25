#include "../s21_math.h"

long double s21_atan(double x) {
  if (x != x) {
    return S21_NAN;
  } else if (x >= S21_LLONG_MAX || x <= S21_LLONG_MIN) {
    return (x < 0) ? -1.570796 : 1.570796;
  }
  return s21_asin(x / s21_sqrt(1.0 + x * x));
}