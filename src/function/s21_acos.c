#include "../s21_math.c"


long double s21_acos(double x) {
  long double res = 0;
  if(x != x || x >= S21_LLONG_MAX || x <= S21_LLONG_MIN){
    res = (x != x) ? x : S21_NAN;
  }
  else if (x == -1) {
    res = 3.141593f;
  } else {
    res = S21_M_PI / 2 - s21_asin(x);
  }
  return res;
}