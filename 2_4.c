#include <stdio.h>

void squeeze(char s1[], char s2[]);
int contains(int c, char s[]);

int main() {
  char s1[] = "hello, world";
  char s2[] = "lord";
  squeeze(s1, s2);
  printf("%s", s1);

  return 0;
}

void squeeze(char s1[], char s2[]) {
  int i, j;

  for (i = j = 0; s1[i] != '\0'; i++) {
    if (!contains(s1[i], s2)) 
      s1[j++] = s1[i];
  }
  s1[j] = '\0';
}

int contains(int c, char s[]) {
  int i;
  for (i = 0; s[i] != '\0'; i++)
    if (s[i] == c)
      return 1;
  return 0;
}
