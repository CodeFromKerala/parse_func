#include "parsefunc.h"
#include <math.h>
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

double parse(parsed func_parsed, double x){
  double e = exp(1);
  if (func_parsed.arr[0] == 0){
    double stmt = 0;
    for (int i = 1; i < 4; i++){
      stmt += func_parsed.arr[i]*pow(x, i);
    }
    return stmt;
  }else if (func_parsed.arr[0] == 1){
    if (func_parsed.arr[2] == 0){
      return func_parsed.arr[1] * pow(e, x);
    }
    return func_parsed.arr[1] * pow(func_parsed.arr[2], x);
  }else if (func_parsed.arr[0] == 2){
    if (func_parsed.arr[2] == 0){
      return func_parsed.arr[1] * log(x)/log(e);
    }
    return func_parsed.arr[1] * log(x)/log(func_parsed.arr[2]);
  }
  return e;
}
