#include "../s21_math.c"


long double s21_tan(double x) {
  long double result = 0.0;
  if (x == 0.0) {
    result = 0.0;
  } else if (S21_M_PI / 6 == x) {
    result = 1 / s21_sqrt(3);
  } else if (S21_M_PI / 4 == x) {
    result = 1.0;
  } else if (S21_M_PI / 3 == x) {
    result = s21_sqrt(3);
  } else if (S21_M_PI / 2 == x) {
    result = S21_INF;
  } else if (S21_M_PI == x) {
    result = 0.0;
  } else if (3.0 * S21_M_PI / 2 == x) {
    result = S21_INF;
  } else if (2.0 * S21_M_PI == x) {
    result = 0.0;
  } else {
    result = s21_sin(x) / s21_cos(x);
  }
  return result;
}
