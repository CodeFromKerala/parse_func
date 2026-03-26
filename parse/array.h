#ifndef ARRAY_H
#define ARRAY_H

#include <stddef.h>
typedef struct {
  double *data;
  size_t size;
  size_t capacity;
} DynamicArray;

DynamicArray createArray(int capacity);
void append(DynamicArray *arr, double element);
double get(DynamicArray arr, size_t index);
void set(DynamicArray *arr, size_t index, double element);
int getCapacity(DynamicArray arr);
int length(DynamicArray arr);
void freeArr(DynamicArray *arr);
void display(DynamicArray arr);

#endif
