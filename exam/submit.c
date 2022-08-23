#include <stdio.h>

int sum(int a, int b) {
  int temp = 0;
  temp = a + b;
  return temp;
}

int main() {
  int a = 10;
  int b = 20;
  int ret = 0;
  ret = sum(a, b);
  printf("ret = %d\n", ret);
  return 0;
}