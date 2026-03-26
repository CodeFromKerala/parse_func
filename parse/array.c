#include "array.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

DynamicArray createArray(int capacity) {
  DynamicArray out = {
      .data = malloc(capacity * sizeof(int)), .size = 0, .capacity = capacity};
  return out;
}

void append(DynamicArray *arr, double element) {
  if (arr->size == arr->capacity) {
    arr->capacity *= 2;
    arr->data = realloc(arr->data, arr->capacity * sizeof(int));
  }
  arr->data[arr->size] = element;
  (arr->size)++;
}

double get(DynamicArray arr, size_t index) { return arr.data[index]; }
void set(DynamicArray *arr, size_t index, double element) {
  if (index >= arr->size) {
    arr->size = index + 1;
  }

  if (index >= arr->capacity) {
    if (arr->capacity == 0) {
      arr->capacity = 1;
    }
    while (index >= arr->capacity) {
      arr->capacity *= 2;
    }
    arr->data = realloc(arr->data, arr->capacity * sizeof(int));
  }

  arr->data[index] = element;
}

int getCapacity(DynamicArray arr) { return arr.capacity; }
int length(DynamicArray arr) { return arr.size; }
void freeArr(DynamicArray *arr) {
  free(arr->data);
  arr->data = NULL;
}

void display(DynamicArray arr) {
  printf("[ ");
  for (size_t i = 0; i < arr.size; i++) {
    printf("%f, ", arr.data[i]);
  }
  printf("]\n");
}
