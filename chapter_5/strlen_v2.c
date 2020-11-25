#include <stdio.h>

int strlength(char *);

int main() {
  printf("%d\n", strlength("hello, world!"));
  return 0;
}

int strlength(char *s) {
  char *p = s;

  while (*p != '\0')
    p++;
  return p - s;
}
