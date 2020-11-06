#include <stdio.h>

#define swap(t, x, y) {t _t; _t = x; x = y; y = _t;}

int main() {
  int x = 3;
  int y = 7;

  printf("x = %d, y = %d\n", x, y);
  swap(int, x, y);
  printf("x = %d, y = %d\n", x, y);

  return 0;
}
