#include<stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void) {
  printf("%u", (unsigned)invert((unsigned)8, (int)3, (int)3));
}

unsigned invert(unsigned x, int p, int n) {
  return x ^ (~(~0 << n) << (p + 1 - n));
}
