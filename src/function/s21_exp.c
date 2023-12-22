#include "../s21_math.h"
#include <float.h>

long double s21_exp(double x) {
  long double res = 1;
  long double ex = 1;
  long double i = 1;
  int flag = 0;

  if (x < 0) {
    x *= -1;
    flag = 1;
  }

  while (s21_fabs(res) > 1e-10) {
    res *= x / i;
    i += 1;
    ex += res;

    if (ex > DBL_MAX) {
      ex = S21_INF;
      break;
    }
  }

  if (flag == 1) {
    if (ex > DBL_MAX) {
      ex = 0;
    } else {
      ex = 1. / ex;
    }
  }

  if (ex > DBL_MAX) {
    return S21_INF;
  }
  return ex;
}