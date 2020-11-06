#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main() {
  char s[100];
  itob(123, s, 16);
  printf("%s\n", s);

  return 0;
}

void itob(int n, char s[], int b) {
  int i, r, sign;

  if ((sign = n) < 0)
    n = -n;

  i = 0;
  do {
    r = n % b;
    s[i++] = r < 10 ? r + '0': r + 'a' - 10;
  } while ((n /= b) > 0);

  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[]) {
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
