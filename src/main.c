#include "math.h"
#include "stdio.h"
#include <float.h>
#include <string.h>
#include "s21_math.h"

#include <float.h>
#include <limits.h>
#include <stdio.h>
// #include "s21_math.h"

#define EPS_6 1e-06
#define S21S_NAN 0.0 / 0.0
#define S21_NAN S21S_NAN / S21S_NAN * -1
#define S21_INF 1.0 / 0.0

#define S21_LLONG_MAX __LONG_LONG_MAX__
#define S21_LLONG_MIN (-__LONG_LONG_MAX__ - 1)

#define S21_E 2.71828182845904523536028747135266250





#define S21_LLONG_MAX __LONG_LONG_MAX__
#define S21_LLONG_MIN (-__LONG_LONG_MAX__ - 1)
#define S21_E 2.71828182845904523536028747135266250
#define S21_M_PI \
  3.1415926535897932384626433832795028841971693993751058209749445923078164
#define S21S_NAN 0.0 / 0.0
#define S21_NAN S21S_NAN / S21S_NAN * -1
#define S21_INF 1.0 / 0.0
#define EPS_6 1e-06

long double s21_pow(double base, double expi);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);
long double s21_floor(double num);
long double s21_log(double num);
long double s21_fmod(double num_1, double num_2);
long double s21_trunc(double x);
long double s21_cos(double x);
long double s21_fabs(double x);
long double s21_ceil(double x);
long double s21_exp(double x);
int s21_abs(int a);
long double s21_acos(double x);
long double s21_asin(double a);
long double s21_atan(double x);


// long double s21_pow(double base, double exp_s){
//   double long res = 1;
//   if(exp_s != exp_s){
//       res = exp_s;
//   }else if(exp_s >= S21_LLONG_MAX && fabs(base - 0.0) < EPS_6){
//     res = 0;
//   }else if(exp_s <= S21_LLONG_MIN && base > 0.0){
//     res = 0;
//   }else if((exp_s <= S21_LLONG_MIN || exp_s >= S21_LLONG_MAX) && fabs(base) == 1){
//     res = 1;
//   }
//   else if((base>= S21_LLONG_MAX || base <= S21_LLONG_MIN) && exp_s < 0){
//     res = 0;
//   }
//   else if(exp_s <= S21_LLONG_MIN || base <= S21_LLONG_MIN ){
//     res = S21_INF;
//   }else if(exp_s >= S21_LLONG_MAX || base >= S21_LLONG_MAX){
//     res = S21_INF;
//   }else if(base == 0){
//     res = 0;
//   }else if((int)exp_s == exp_s){
//     int deg = fabs(exp_s);
//     while (deg) {
      
//     }
//     if (exp_s < 0) {
//       res = 1 / res;
//     }
//   }
//   else{
//     res = exp(exp_s * log(base));
//   }
  
//   return res;
// }
void test(){
  long double base_test[] ={2, 2, 2, 2, 0, 0, 0, 0, -1, -1, -1, -1, 1.0001, 1.0001, -S21_INF, S21_INF, -S21_NAN, S21_NAN, -20};
  long double exp_test[] ={S21_NAN, -S21_NAN, S21_INF, S21_INF * -1, S21_NAN, -S21_NAN, S21_INF, S21_INF * -1, -S21_NAN, S21_INF, S21_INF * -1, S21_INF, -S21_INF, 4 -4};

  char str1[100], str2[100];

  for(int i = 0; base_test[i] != -20; i ++){
      long double res1 = pow(base_test[i],exp_test[i]);
      long double res2 = s21_pow(base_test[i],exp_test[i]);
      snprintf(str1, sizeof(str1), "%.6Lf", res1);
      snprintf(str2, sizeof(str2), "%.6Lf", res2);
      if(strcmp(str1, str2) != 0){
        printf("get %Lf | %Lf value %Lf | %Lf\n", res1, res2, base_test[i], exp_test[i]);
      }
  }

  for(int i = 0; base_test[i] != -20; i ++){
      long double res1 = cos(base_test[i]);
      long double res2 = s21_cos(base_test[i]);
      snprintf(str1, sizeof(str1), "%.6Lf", res1);
      snprintf(str2, sizeof(str2), "%.6Lf", res2);
      if(strcmp(str1, str2) != 0){
        printf("get %Lf | %Lf value %Lf | %Lf\n", res1, res2, base_test[i], exp_test[i]);
      }
  }

  for(int i = 0; base_test[i] != -20; i ++){
      long double res1 = sin(base_test[i]);
      long double res2 = s21_sin(base_test[i]);
      snprintf(str1, sizeof(str1), "%.6Lf", res1);
      snprintf(str2, sizeof(str2), "%.6Lf", res2);
      if(strcmp(str1, str2) != 0){
        printf("get %Lf | %Lf value %Lf | %Lf\n", res1, res2, base_test[i], exp_test[i]);
      }
  }
}


int main(){
  // printf("%f\n", pow((double)-2 * 0.33333, 2 * 1.33333));
  // printf("%Lf\n", s21_pow((double)-2 * 0.33333, 2 * 1.33333));

  printf("%Lf\n",s21_atan(2));
  printf("%f", tan(2));

  // test();
}


long double s21_pow(double base, double exp){
  double long res = 1;
  if(exp != exp){
      res = exp;
  }else if(exp >= S21_LLONG_MAX && s21_fabs(base - 0.0) < EPS_6){
    res = 0;
  }else if(exp <= S21_LLONG_MIN && base > 0.0){
    res = 0;
  }else if((exp <= S21_LLONG_MIN || exp >= S21_LLONG_MAX) && s21_fabs(base) == 1){
    res = 1;
  }
  else if((base>= S21_LLONG_MAX || base <= S21_LLONG_MIN) && exp < 0){
    res = 0;
  }
  else if(exp <= S21_LLONG_MIN || base <= S21_LLONG_MIN ){
    res = S21_INF;
  }else if(exp >= S21_LLONG_MAX || base >= S21_LLONG_MAX){
    res = S21_INF;
  }else if(base == 0){
    res = 0;
  }else if((int)exp == exp){
    for(int deg = s21_fabs(exp); deg >= 1; deg--){
      res *= base;
    }
    if (exp < 0) {
      res = 1 / res;
    }
  }
  else{
    res = s21_exp(exp * s21_log(base));


  }
  
  return res;
}

long double s21_sin(double x) {
  x = s21_fmod(x, 2.0 * S21_M_PI);

  long double result = 0, item = x;
  for (int n = 1; s21_fabs(item) > 1e-12; n++) {
    result += item;
    item *= -x * x / ((2.0 * n ) * (2.0 * n + 1.0));
  }
  return result;

}

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
  return sqrt;
}

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



long double s21_log(double x) {
  int ex_pow = 0;
  double result = 0;
  double compare = 0;
  
  if (x > 0) {
    for(; x >= S21_E; x /=S21_E, ex_pow++){
      continue;
    }

    for(int i = 0; i < 100; i++){
      compare  = result;
      result = compare + 2 * ((x - s21_exp(compare))/ (x + s21_exp(compare)));
    }

    result += ex_pow;

  }else {
    result = S21_INF * -1;
  }
  
  return result;
}

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


long double s21_exp(double x) {
  long double res = 1;
  long double temp = 1;
  long double i = 1;
  int flag = 0;
  if(x <= S21_LLONG_MIN || x >= S21_LLONG_MAX){
    return -S21_NAN;
  }

  if (x < 0) {
    x *= -1;
    flag = 1;
  }

  while (s21_fabs(res) > 1e-10) {
    res *= x / i;
    i += 1;
    temp += res;
    if (temp > DBL_MAX) {
      temp = S21_INF;
      break;
    }
  }
  if (flag == 1) {
    if (temp > DBL_MAX) {
      temp = 0;
    } else {
      temp = 1. / temp;
    }
  }
  if (temp > DBL_MAX) {
    return S21_INF;
  }
  return temp;
}

long double s21_cos(double x) {
  if(x != x || x >= S21_LLONG_MAX || x <= S21_LLONG_MIN){
    return -S21_NAN;
  }
  x = s21_fmod(x, 2.0 * S21_M_PI);
  
  long double result = 0, item = 1;
  for (int n = 1; s21_fabs(item) > 1e-11; n++) {
    result += item;
    item *= -x * x / (2.0 * n - 1.0) / (2.0 * n);
  }
  return result;
}

long double s21_fabs(double x){
    return (long double)(x < 0) ? -x : x;
}

long double s21_ceil(double x) {
  long double res;

  if(x != x || x >= S21_LLONG_MAX || x <= S21_LLONG_MIN){
          res = x;
  }else {
    res = (long long)x;
    if(x < 0 && x > -1){
      res *= -1;
    }
    else if (x != (long long)x && x > 0) {
      res += 1;
    }
  }
  return res;
}

int s21_abs(int x){
    return x > 0 ? x : -x; 
}


long double s21_acos(double x) {
  long double res = 0;
  if (x == -1) {
    res = 3.141593f;
  } else {
    res = S21_M_PI / 2 - s21_asin(x);
  }
  return res;
}

long double s21_asin(double a) {
  long double tmp = a, sum = S21_NAN;
  if (a == 1.0 || a == -1.0) {
    sum = (a > 0) ? 1.570796 : -(1.570796);
  } else if (-1.0 < a && a < 1.0) {
    sum = tmp;
    a *= a;
    for (int k = 1; s21_fabs(tmp) > 1e-10; k += 2)
      sum += (tmp *= a * k / (k + 1)) / (k + 2);
  }
  return sum;
}

long double s21_atan(double x) { 

  //  x = s21_fmod(x, 2.0 * S21_M_PI);
   
  long double value = (x > 1 || x < -1) ? 1 / x : x;

  long double result = 0.0, item = value;

  for (int n = 3.0; s21_fabs(item) > 1e-16; n+=2.0) {
    result += item;
    item *= -value * value / n;
  }


  if(x > 1 || x < -1){
    result = x / x * S21_M_PI / 2 - result;
  }
  return result;
  }
