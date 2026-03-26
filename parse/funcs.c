#include "funcs.h"
#include "array.h"

func createPolynomialFromArr(DynamicArray params) {
  func polynomial = {.type = POLYNOMIAL, .params = params};
  return polynomial;
}

func createPolynomial(double params[], int n) {
  DynamicArray arr = createArray(n);
  for (int i = 0; i < n; i++) {
    append(&arr, params[i]);
  }
  return createPolynomialFromArr(arr);
}

func initPolynomial() {
  DynamicArray arr = createArray(4);
  return createPolynomialFromArr(arr);
}
