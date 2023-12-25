#include "../s21_math.h"

long double s21_log(double x) {
  int ex_pow = 0;
  double result = 0;
  double compare = 0;

  if (x > 0) {
    for (; x >= S21_E; x /= S21_E, ex_pow++) {
      continue;
    }

    for (int i = 0; i < 100; i++) {
      compare = result;
      result = compare + 2 * ((x - s21_exp(compare)) / (x + s21_exp(compare)));
    }

    result += ex_pow;

  } else {
    result = S21_INF * -1;
  }

  return result;
}
