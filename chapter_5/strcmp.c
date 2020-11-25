#include <stdio.h>

int strcompare(char *, char *);

int main() {
  char *s = "hello";
  char *t = "hello, world";
  printf("%d\n", strcompare(s, t));
  return 0;
}

int strcompare(char *s, char *t) {
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}
