#include <stdio.h>

#define MAXLINE 1000
#define TABSIZE 4

void detab(int tabsize);

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t')
      detab(TABSIZE);
    else
      putchar(c);
  }

  return 0;
}

void detab(int tabsize) {
  int i;
  for (i = 0; i < tabsize; ++i)
    putchar(' ');
}
