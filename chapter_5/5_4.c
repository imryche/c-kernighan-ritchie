#include <stdio.h>
#include <string.h>

int strend(char *, char *);

int main() {
  printf("%d\n", strend("hello world", "world"));
  return 0;
}

int strend(char *s, char *t) {
  s += strlen(s) - strlen(t);
  for (; *s == *t; s++, t++)
    if (*s == '\0')
      return 1;
  return 0;
}
