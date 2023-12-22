#include "math.h"
#include "stdio.h"
#include <float.h>
#include <string.h>

#define EPS_6 1e-06
#define S21S_NAN 0.0 / 0.0
#define S21_NAN S21S_NAN / S21S_NAN * -1
#define S21_INF 1.0 / 0.0

#define S21_LLONG_MAX __LONG_LONG_MAX__
#define S21_LLONG_MIN (-__LONG_LONG_MAX__ - 1)

#define S21_E 2.71828182845904523536028747135266250

// long double s21_pow(double a, double x) {
//   if (a < 0 && (int)(x) != x) {
//     return -0. / 0.;
//   }
//   long double a_ = a;
//   long double res = 1;
//   if ((int)x == x) {
//     int deg = s21_fabs(x);
//     while (deg) {
//       if (deg % 2 == 0) {
//         deg /= 2;
//         a_ *= a_;
//       } else {
//         deg--;
//         res *= a_;
//       }
//     }
//     if (x < 0) {
//       res = 1 / res;
//     }
//   } else {
//     if (a_ == 0) {
//       res = 0;
//     } else {
//       res = s21_exp_s(x * s21_log(a));
//     }
//   }
//   return res;
// }

long double s21_pow(double base, double exp_s){
  double long res = 1;
  if(exp_s != exp_s){
      res = exp_s;
  }else if(exp_s >= S21_LLONG_MAX && fabs(base - 0.0) < EPS_6){
    res = 0;
  }else if(exp_s <= S21_LLONG_MIN && base > 0.0){
    res = 0;
  }else if((exp_s <= S21_LLONG_MIN || exp_s >= S21_LLONG_MAX) && fabs(base) == 1){
    res = 1;
  }
  else if((base>= S21_LLONG_MAX || base <= S21_LLONG_MIN) && exp_s < 0){
    res = 0;
  }
  else if(exp_s <= S21_LLONG_MIN || base <= S21_LLONG_MIN ){
    res = S21_INF;
  }else if(exp_s >= S21_LLONG_MAX || base >= S21_LLONG_MAX){
    res = S21_INF;
  }else if(base == 0){
    res = 0;
  }else if((int)exp_s == exp_s){
    int deg = fabs(exp_s);
    while (deg) {
      
    }
    if (exp_s < 0) {
      res = 1 / res;
    }
  }
  else{
    res = exp(exp_s * log(base));
  }
  
  return res;
}
void test(){
  long double base_test[] ={2, 2, 2, 2, 0, 0, 0, 0, -1, -1, -1, -1, 1.0001, 1.0001, -S21_INF, S21_INF, -20};
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

}


int main(){
  printf("%f\n", pow((double)-1 * 0.33333, 2 * 1.33333));
  printf("%Lf\n", s21_pow((double)-1 * 0.33333, 2 * 1.33333));


  // test();
}


// double helper(double base, double exp_s) {
//   double res = OK;
//   if (base == 0.0) {
//     if (isNAN(exp_s)) {
//       res = S21_NAN;
//     } else if (exp_s == -S21_NAN) {
//       res = -S21_NAN;
//     } else if (isNEG_INF(exp_s)) {
//       res = POS_INF;
//     } else if (exp_s == 0.0) {
//       res = 1.0;
//     } else if (exp_s < 0) {
//       res = POS_INF;
//     }
//     if (isPOS_INF(exp_s) || isNEG_INF(exp_s)) {
//       res = 1.0;
//     }
//   } else if (!isInt(base) && !isPOS_INF(base) && !isNEG_INF(base)) {
//     if (isPOS_INF(exp_s)) {
//       res = 0.0;
//     } else if (isNEG_INF(exp_s)) {
//       res = POS_INF;
//     }
//   } else if (isInt(base)) {
//     if (isPOS_INF(exp_s) || isNEG_INF(exp_s)) {
//       res = POS_INF;
//     }
//   } else if (isPOS_INF(base)) {
//     if (exp_s == 0.0) {
//       res = 1.0;
//     } else if (exp_s > 0 && isInt(exp_s)) {
//       res = POS_INF;
//     } else if (isPOS_INF(exp_s)) {
//       res = POS_INF;
//     } else if (isNAN(exp_s)) {
//       res = S21_NAN;
//     }
//   } else if (isNEG_INF(base)) {
//     if (exp_s == 0.0) {
//       res = 1.0;
//     } else if (exp_s > 0 && isInt(exp_s)) {
//       res = NEG_INF;
//     } else if (isPOS_INF(exp_s)) {
//       res = POS_INF;
//     } else if (isNAN(exp_s)) {
//       res = S21_NAN;
//     }
//   }
//   return res;
// }

// long double fast_pow(double base, long long int exp_s) {
//   long double ans = 1.0;
//   long long copy = s21_fabs(exp_s);
//   while (copy) {
//     ans *= base;
//     copy--;
//   }
//   return (exp_s < 0) ? 1.0 / ans : ans;
// }

// long double s21_pow(double base, double exp_s) {
//   long double ans = 1.0;
//   if (helper(base, exp_s) == 1000.0) {
//     if (isInt(exp_s)) {
//       ans = fast_pow(base, exp_s);
//     } else {  // exp_s in not int
//       if (base < 0) {
//         ans = S21_NAN;
//       } else {
//         ans = s21_exp_s(exp_s * s21_log(base));
//       }
//     }
//   } else {
//     ans = helper(base, exp_s);
//   }
//   return ans;
// }