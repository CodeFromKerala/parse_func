#ifndef PARSEFUNC_H
#define PARSEFUNC_H

typedef double (*func)(double);
typedef struct {
  int arr[5];
} parsed;
double parse(parsed func_parsed, double x);

#endif
