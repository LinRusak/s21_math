#include "../s21_math.h"

long double s21_floor(double x) {
  long double res;

 if(x != x || x == S21_INF || x == S21_INF * -1){
        res = x;
    }
 else {
    long double tmp = (long long)x;
    res = tmp - (tmp > x);
  }
  return res;
}

