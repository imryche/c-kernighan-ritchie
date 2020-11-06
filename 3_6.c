#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int w);
void reverse(char s[]);

int main() {
  char s[100];
  itoa(123, s, 6);
  printf("%s\n", s);

  return 0;
}

void itoa(int n, char s[], int w) {
  int i, j, sign;

  if ((sign = n) < 0)
    n = -n;

  i = 0;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);

  if (sign < 0)
    s[i++] = '-';

  j = 0;
  while (j <= w - strlen(s) + 1) {
    s[i++] = ' ';
    j++;
  }

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
