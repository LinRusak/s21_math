#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double res;
  
  if (y ==  0.0){
    res = -S21_NAN;
  }

  else if(x == S21_INF || x == S21_INF * -1){
    res  = -S21_NAN;
  }

  else{
    res = x / y;
    if(res < 0){
      res = s21_ceil(res);
    }
    else{
      res = s21_floor(res);
    }

    res = x - y * res;
  }
  return res;
}
