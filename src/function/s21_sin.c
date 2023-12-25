#include "../s21_math.h"

long double s21_sin(double x) {
  x = s21_fmod(x, 2.0 * S21_M_PI);

  long double result = 0, item = x;
  for (int n = 1; s21_fabs(item) > 1e-12; n++) {
    result += item;
    item *= -x * x / ((2.0 * n) * (2.0 * n + 1.0));
  }
  return result;
}