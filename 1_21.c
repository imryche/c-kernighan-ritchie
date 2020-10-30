#include <stdio.h>

#define TABSIZE 4

int main() {
  int c, spaces, i;

  spaces = 0;
  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++spaces;
    } else {
      if (spaces == TABSIZE) {
        putchar('\t');
      } else {
        for (i = 0; i < spaces; ++i) {
          putchar(' ');
        }
      }
      spaces = 0;
      putchar(c);
    }
  }

  return 0;
}
