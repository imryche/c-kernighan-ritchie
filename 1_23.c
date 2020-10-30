#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[]);

/* this is simple comment */

int main() {
  int c, i, len, in_comment;
  char s[MAXLINE];

  in_comment = 0;
  while ((len = get_line(s)) > 0) {
    for (i = 0; i < len; ++i) {
      if (i + 1 < len) {
        if (s[i] == '/' && s[i + 1] == '*' && i + 1 < len)
          in_comment = 1;

        if (s[i] == '*' && s[i + 1] == '/' && i + 1 < len)
          in_comment = 0;
      }

      if (in_comment == 0 && s[i] != '*' && s[i] != '/') 
        putchar(s[i]);
    }
  }

  return 0;
}

int get_line(char s[]) {
  int i, c;

  for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;

  if (c == '\n') {
    s[i] = c;
    ++i;
  }

  s[i] = '\0';

  return i;
}
