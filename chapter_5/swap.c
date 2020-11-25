#include <stdio.h>

void swap(int *, int *);

int main() {
  int x = 3;
  int y = 7;

  printf("x = %d, y = %d\n", x, y);
  swap(&x, &y);
  printf("x = %d, y = %d\n", x, y);

  return 0;
}

void swap(int *px, int *py) {
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}
