#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[]);

/* this program is not finished, but I have no time to spend... */

int main() {
  char s[MAXLINE];
  int c, i, len;
  int parentheses, brackets, braces, s_quotes, d_quotes;

  parentheses = brackets = braces = s_quotes = d_quotes = 0;
  while ((len = get_line(s)) > 0) {
    for (i = 0; i < len; ++i) {
      if (s[i] == '(')
        ++parentheses;
      if (s[i] == ')')
        --parentheses;
      if (s[i] == '[')
        ++brackets;
      if (s[i] == ']')
        --brackets;
      if (s[i] == '{')
        ++braces;
      if (s[i] == '}')
        --braces;
      if (s[i] == '\'')
        ++s_quotes;
      if (s[i] == '"')
        ++d_quotes;
    }
  }

  if parentheses != 0 || brackets != 0 || braces != 0) {
    printf("Syntax error!\n");
  }

  printf("%d %d %d %d %d", parentheses, brackets, braces, s_quotes, d_quotes);

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
