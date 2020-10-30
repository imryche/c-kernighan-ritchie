#include <stdio.h>

int main() {
  int i;
  char c;
  int lim = 1000;

  for (i = 0;; ++i) {
    if (i >= lim - 1)
      break;

    c = getchar();

    if (c == '\n')
      break;

    if (c == EOF)
      break;

    putchar(c);
  }
}
