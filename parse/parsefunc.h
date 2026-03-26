#ifndef PARSEFUNC_H
#define PARSEFUNC_H
/*
PARSE FUNC v1
To map a function to an integer set, some conventions have to be named

It uses a len-5 integer array to map functions

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

#include "array.h"
#include "funcs.h"

double parse(func function, double x);
void set_param(func *function, int n, double value);
double get_param(func function, int n);
#endif
