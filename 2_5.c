#include <stdio.h>

int any(char s1[], char s2[]);
int contains(int c, char s[]);

int main() {
  char s1[] = "hello, world";
  char s2[] = "lord";
  printf("%d", any(s1, s2));

  return 0;
}

int any(char s1[], char s2[]) {
  int i, j;

  for (i = j = 0; s1[i] != '\0'; i++) {
    if (contains(s1[i], s2)) 
      return i;
  }
  return -1;
}

int contains(int c, char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; i++)
    if (s[i] == c)
      return 1;
  return 0;
}
