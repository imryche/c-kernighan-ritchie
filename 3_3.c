#include <stdio.h>

void expand(char s1[], char s2[]);

int main() {
  char s1[] = "a-c";
  char s2[50];

  printf("%s\n", s1);
  expand(s1, s2);
  printf("%s\n", s2);

  return 0;
}

void expand(char s1[], char s2[]) {
  int i, j, c;

  i = j = 0;
  while ((c = s1[i++]) != '\0') {
    if (s1[i] == '-' && s1[i + 1] >= c) {
      i++;
      while (c < s1[i]) {
        s2[j++] = c++;
      }
    } else {
      s2[j++] = c;
    }
  }

  s2[j] = '\0';
}
