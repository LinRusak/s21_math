#include "../s21_math.c"


long double s21_sqrt(double x) {
  if (x != x) return S21_NAN;
  if (x < 0) return S21_NAN * -1;
  double sqrt, temp;
  sqrt = x / 2;
  temp = 0;
  while (sqrt != temp) {
    temp = sqrt;
    sqrt = (x / temp + temp) / 2;
  }
  return (long double)sqrt;
}
