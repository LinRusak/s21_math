#include "../s21_math.c"


long double s21_atan(double x) { return s21_asin(x / s21_sqrt(1.0 + x * x)); }