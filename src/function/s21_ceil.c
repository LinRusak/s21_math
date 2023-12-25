#include "../s21_math.h"

long double s21_ceil(double x) {
  long double res;

  if (x != x || x >= S21_LLONG_MAX || x <= S21_LLONG_MIN) {
    res = x;
  } else {
    res = (long long)x;
    if (x < 0 && x > -1) {
      res *= -1;
    } else if (x != (long long)x && x > 0) {
      res += 1;
    }
  }
  return res;
}