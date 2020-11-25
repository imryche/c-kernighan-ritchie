#include <stdio.h>

#define MAXLINE 1000

int getln(char *line, int max);

int main() {
  char line[MAXLINE];

  while (getln(line, MAXLINE) > 0)
    printf("%s", line);

  return 0;
}

int getln(char *s, int max) {
  int c;
  char *start = s;

  while (--max > 0 && (c = getchar()) != EOF && c != '\n')
    *s++ = c;

  if (c == '\n')
    *s++ = c;

  *s = '\0';

  return s - start;
}
