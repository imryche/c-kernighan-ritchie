#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int get_line(char line[], int maxline);
void reverse(char line[]);

int main() {
  int len, i;
  char line[MAXLINE];

  while (get_line(line, MAXLINE) > 0) {
    reverse(line);
    printf("%s", line);
  }

  return 0;
}

int get_line(char s[], int lim) {
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  if (i == lim - 1)
    while ((c = getchar()) != '\n')
      ++i;

  return i;
}

void reverse(char s[]) {
  int i, len, tmp;
  
  len = strlen(s) - 1;
  for (i = 0; i < len / 2 ; ++i) {
    tmp = s[i];
    s[i] = s[len - i - 1];
    s[len - i - 1] = tmp;
  }
}
