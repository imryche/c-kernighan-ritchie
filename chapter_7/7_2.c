#include <stdio.h>
#include <ctype.h>

#define MAXLINE 3

int main() {
  int c, len = 0;

  while ((c = getchar()) != EOF) {
    len++;
    if (isgraph(c) || isspace(c)) {
      putchar(c);
    } else {
      printf("%x", c);
    }
    if (len > MAXLINE - 1) {
      putchar('\n');
      len = 0;
    }
  }

  return 0;
}
