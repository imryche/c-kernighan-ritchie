#include <stdio.h>
#include <stdlib.h>

void itoa(int, char []);

int main() {
  char s[10];
  itoa(-123, s);
  printf("%s", s);

  return 0;
}

void itoa(int n, char s[]) {
  static int i = 0;

  if (n / 10)
    itoa(n / 10, s);
  else {
    i = 0;
    if (n < 0)
      s[i++] = '-';
  }

  s[i++] = abs(n) % 10 + '0';
  s[i + 1] = '\0';
}
