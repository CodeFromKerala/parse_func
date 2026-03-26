#ifndef FUNCS_H
#define FUNCS_H

#include "array.h"

typedef enum { POLYNOMIAL, EXPONENTIAL, LOGARITHMIC } func_t;
typedef struct {
  func_t type;
  DynamicArray params;
} func;

func createPolynomialFromArr(DynamicArray params);
func createPolynomial(double params[], int n);
func initPolynomial();

#endif
