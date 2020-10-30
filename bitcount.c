#include <stdio.h>

int bitcount(unsigned x);

int main() {
  printf("%d", bitcount((unsigned)12));
}

int bitcount(unsigned x) {
  int b;

  for (b = 0; x != 0; x >>= 1)
    if (x & 01)
      b++;
  return b;
}
