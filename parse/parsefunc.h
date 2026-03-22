#ifndef PARSEFUNC_H
#define PARSEFUNC_H
/*
PARSE FUNC v1
To map a function to an integer set, some conventions have to be named

It uses a len-5 integer array to map functions

The array is divided into 2 parts,
1. The function type - first integer(i = 0)
2. The function parameters - integers at (i = 1 to i = 4)

let func be the parsed array, func = {n, a, b, c, d}

n = 0, gives polynomial function, f(x) = ax^3 + bx^2 + cx^1 + d
  = 2, gives exponential functions, f(x) = a * b ^ x, where b = 0 results in evaluation as b = e
  = 3, gives logarithmic functions, f(x) = a * log[b](x), and as above, b = 0, results in evaluation as b = e


*/
typedef struct {
  int type;
  double params[4];
  int buffer;
} func;
double parse(func function, double x);
#endif
