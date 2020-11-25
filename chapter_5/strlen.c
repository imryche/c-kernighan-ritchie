#include <stdio.h>

int strlength(char *);

int main() {
  printf("%d\n", strlength("hello, world!"));
  return 0;
}

int strlength(char *s) {
  int n;
  for (n = 0; *s != '\0'; s++)
    n++;
  return n;
}
