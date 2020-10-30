#include <stdio.h>
#include <ctype.h>

int htoi(char s[]);

int main() {
  printf("%d\n", htoi("0x7BE")); /* 1982 */
  printf("%d\n", htoi("0x3D10")); /* 15632 */
  return 0;
}

int htoi(char s[]) {
  int i, c;
  int n = 0;
  
  for (int i = 0; s[i] != '\0'; ++i) {
    c = tolower(s[i]);

    if (c >= '0' && c <= '9')
      n = 16 * n + (c - '0');
    else if (c >= 'a' && c <= 'f')
      n = 16 * n + (c - 'a' + 10);
  }

  return n;
}
