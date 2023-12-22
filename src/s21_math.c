#include "s21_math.h"

#include <float.h>
#include <limits.h>
#include <stdio.h>

long double s21_pow(double a, double x) {
  if (a < 0 && (int)(x) != x) {
    return -0. / 0.;
  }
  long double a_ = a;
  long double res = 1;
  if ((int)x == x) {
    int deg = s21_fabs(x);
    while (deg) {
      if (deg % 2 == 0) {
        deg /= 2;
        a_ *= a_;
      } else {
        deg--;
        res *= a_;
      }
    }
    if (x < 0) {
      res = 1 / res;
    }
  } else {
    if (a_ == 0) {
      res = 0;
    } else {
      res = s21_exp(x * s21_log(a));
    }
  }
  return res;
}

long double s21_sin(double x) {
  if(x != x || x >= S21_LLONG_MAX || x <= S21_LLONG_MIN){
    return x;
  }
  x = s21_fmod(x, 2.0 * S21_M_PI);
  long double sum = 0.0;
  for (int i = 0; i <= 20; i++) {
    double fa = 1.0, pow = 1.0;
    for (int j = 1; j <= 2 * i + 1; j++) {
      fa *= j;
      pow *= x;
    }
    sum += ((i % 2 ? -1.0 : 1.0) / fa) * pow;
  }
  return sum;
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

long double s21_floor(double num) {
  long double res;
  if (num >= S21_LLONG_MAX || num <= S21_LLONG_MIN) {
    res = (long double)num;
  } else {
    long double tmp = (long long)num;
    res = tmp - (tmp > num);
  }
  return res;
}

long double s21_log(double num) {
  unsigned ans = 0;
  double y = 0;
  if (num > 0) {
    unsigned d;
    double z = 0, a = 0, x = num;
    for (; (x = x / S21_E) > 1; ++ans) {
    }
    x = 1 / (x * S21_E - 1);
    x = x * 2 + 1;
    a = x * x;
    y = 0;
    for (d = 1, x = x / 2; z = y, y += 1 / (d * x), y - z;) {
      d += 2;
      x *= a;
    }
  } else {
    y = S21_INF * -1;
  }
  return ans + y;
}

long double s21_fmod(double num_1, double num_2) {
  return (long double)((1 - 2 * (num_1 < 0)) * (s21_fabs(num_1) - s21_fabs(((int)(num_1 / num_2)) * num_2)));
}

long double s21_exp(double x) {
  long double res = 1;
  long double temp = 1;
  long double i = 1;
  int flag = 0;
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
  long double t_s = 0, last = 1;
  for (int k = 1; s21_fabs(last) > 1e-12; ++k) {
    t_s += last;
    last *= -x * x / (2.0 * k - 1.0) / (2.0 * k);
  }
  return t_s;
}
long double s21_fabs(double x) { return (long double)(x < 0) ? -x : x; }

long double s21_ceil(double x) {
  long double result;
  long long temp = x;
  if (x == S21_INF) {
    result = S21_INF;
  } else if (x == S21_INF * -1) {
    result = S21_INF * -1;
  } else if (x != x) {
    result = S21_NAN;
  } else {
    result = temp;
    if (x < 0 && x > -1) {
      result *= -1;
    }
    if (x != temp && x > 0) {
      result += 1;
    }
  }
  return result;
}

int s21_abs(int a) { return a > 0 ? a : -a; }

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

long double s21_atan(double x) { return s21_asin(x / s21_sqrt(1.0 + x * x)); }
