#include <stdio.h>

void strcopy(char *, char *);

int main() {
  char *s, *t;
  t = "hello, world";
  strcopy(s, t);
  printf("%s\n", s);
  return 0;
}

void strcopy(char *s, char *t) {
  while ((*s++ = *t++))
    ;
}
