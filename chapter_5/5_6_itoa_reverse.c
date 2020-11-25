#include <stdio.h>
#include <string.h>

void itoa(int n, char *s);
void reverse(char *s);

int main() {
  char s[100];
  itoa(123, s);
  printf("%s\n", s);

  return 0;
}

void itoa(int n, char *s) {
  int sign;
  char *t = s;

  if ((sign = n) < 0)
    n = -n;

  do {
    *s++ = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
    *s++ = '-';

  *s = '\0';

  reverse(t);
}

void reverse(char *s) {
  int c;
  char *t;

  for (t = s + strlen(s) - 1; s < t; s++, t--) {
    c = *s;
    *s = *t;
    *t = c;
  }
}
