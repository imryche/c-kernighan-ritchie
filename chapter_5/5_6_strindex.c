#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getln(char *line, int max);
int strindex(char *source, char *searchfor);

char pattern[] = "orl";

int main() {
  char line[MAXLINE];
  int found = 0;

  while (getln(line, MAXLINE) > 0)
    if (strindex(line, pattern) >= 0) {
      printf("%s", line);
      found++;
    }

  return found;
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

int strindex(char *s, char *t) {
  char *b = s;
  char *l, *m;

  for (; *s != '\0'; s++) {
    for (l = s, m = t; *m != '\0' && *l == *m; l++, m++)
      ;
    if (m > t && *m == '\0')
      return s - b;
  }
  return -1;
}
