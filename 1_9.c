#include <stdio.h>

int main() {
  int c, inspace;

  inspace = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (inspace == 0) {
        putchar(c);
        inspace = 1;
      }
    } else {
      putchar(c);
      inspace = 0;
    }
  }
}
