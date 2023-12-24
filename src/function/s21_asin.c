#include "../s21_math.h"


long double s21_asin(double a) {
  long double tmp = a, sum = S21_NAN;
  if(a != a || a >= S21_LLONG_MAX || a <= S21_LLONG_MIN){
    sum = (a != a) ? a : S21_NAN;
  }else if (a == 1.0 || a == -1.0) {
    sum = (a > 0) ? 1.570796 : -(1.570796);
  } else if (-1.0 < a && a < 1.0) {
    sum = tmp;
    long double x = a * a;
    for (double i = 1.0; s21_fabs(tmp) > 1e-10; i += 2){
      tmp *= x * i / (i + 1);
      sum += tmp / (i + 2);
      
    }
  }
  return sum;
}