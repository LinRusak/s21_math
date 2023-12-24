#include "../s21_math.h"


long double s21_atan(double x) { 
    if(x != x || x >= S21_LLONG_MAX || x <= S21_LLONG_MIN){
        return (x != x) ? x : S21_NAN;
    }
    return s21_asin(x / s21_sqrt(1.0 + x * x)); 
}