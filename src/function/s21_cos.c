#include "../s21_math.h"


long double s21_cos(double x) {
  if(x != x || x >= S21_LLONG_MAX || x <= S21_LLONG_MIN){
    return (x != x) ? x : -S21_NAN;
  }
  x = s21_fmod(x, 2.0 * S21_M_PI);
  
  long double result = 0, item = 1;
  for (int n = 1; s21_fabs(item) > 1e-11; n++) {
    result += item;
    item *= -x * x / (2.0 * n - 1.0) / (2.0 * n);
  }
  return result;
}