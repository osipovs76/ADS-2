// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

double pown(double value, uint16_t n) {
  uint16_t i = n;
  double c = value;
  if (n == 0) {
    return 1;
  }
  while (i != 1) {
    c *= value;
    i--;
  }
  return c;
}

uint64_t fact(uint16_t n) {
  if(n==0){
    return 1;
  }
  uint64_t b = 1;
  for (int i = n; i != 1; i--) {
    b *= i;
  }
  return b;
}

double calcItem(double x, uint16_t n) {
  double a = pown(x, n) / fact(n);
  return a;
}

double expn(double x, uint16_t count) {
  double a = 1;
  int n = 1;
  while (count > n - 1) {
    a += calcItem(x, n);
    n++;
  }
  return a;
}

double sinn(double x, uint16_t count) {
  double a = 0;
  for (uint16_t i = 1; i <= count; i++) {
     a += pown(-1, (i - 1)) * calcItem(x, 2 * i - 1);
  }
  return a;
}

double cosn(double x, uint16_t count) {
  double a = 0;
  for (uint16_t i = 1; i <= count; i++) {
    a += pown(-1, (i - 1)) * calcItem(x, 2 * i - 2);
  }
  return a;
}
