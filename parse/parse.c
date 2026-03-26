#include "../mathobj/mathobj.h"
#include "array.h"
#include "parsefunc.h"
#include <math.h>
#include <stdio.h>
/*
PARSE FUNC v1
To map a function to an integer set, some conventions have to be named

The array is divided into 2 parts,
1. The function type
2. The function parameters - integers at (i = 1 to i = 4)

let func be the parsed array, func = {n, a, b, c, d}

type = POLYNOMIAL gives polynomial function, f(x) = ax^3 + bx^2 + cx^1 + d.
     = EXPONENTIAL gives exponential functions, f(x) = a * b ^ x, where b = 0
results in evaluation as b = e.
    = LOGARITHMIC gives logarithmic functions, f(x) = a * log[b](x), and
      as above, b = 0, results in evaluation as b = e


*/

double parsePolynomial(func function, double x) {
  double val = get(function.params, 0);
  for (int i = 1; i < length(function.params); i++) {
    val += get(function.params, i) * pow(x, i);
  }
  return val;
}

double parse(func function, double x) {
  if (function.type == POLYNOMIAL) {
    return parsePolynomial(function, x);
  } // Algebraic Functions
  return mathObj.e;
}

void set_param(func *function, int n, double value) {
  set(&(function->params), n, value);
}

double get_param(func function, int n) { return get(function.params, n); }
