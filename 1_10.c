#include <stdio.h>

int main() {
  int c, found;

  found = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      putchar('\\');
      putchar('t');
      found = 1;
    }

    if (c == '\b') {
      putchar('\\');
      putchar('b');
      found = 1;
    }

    if (c == '\\') {
      putchar('\\');
      putchar('\\');
      found = 1;
    }

    if (found == 0)
      putchar(c);
  }
}
