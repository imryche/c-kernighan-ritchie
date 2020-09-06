#include <stdio.h>

int main() {
  int c, state, inspace;

  inspace = 1;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (inspace == 0) {
	putchar('\n');
	inspace = 1;
      }
    } else {
      inspace = 0;
      putchar(c);
    }
  }
}

