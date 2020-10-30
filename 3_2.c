#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main() {
  int i;
  char c, t[MAXLINE], s[MAXLINE];

  for (i = 0; (c = getchar()) != EOF; i++) {
    t[i] = c;
  }
  escape(s, t);
  printf("%s\n", s);

  unescape(t, s);
  printf("%s\n", t);

  return 0;
}

void escape(char s[], char t[]) {
  int i, j;

  for (i = j = 0; t[i] != '\0'; i++, j++) {
    switch (t[i]) {
    case '\n':
      s[j++] = '\\';
      s[j] = 'n';
      break;
    case '\t':
      s[j++] = '\\';
      s[j] = 't';
      break;
    default:
      s[j] = t[i];
    }
  }

  s[j] = '\0';
}

void unescape(char s[], char t[]) {
  int i, j;

  for (i = j = 0; t[i] != '\0'; i++, j++) {
    switch (t[i]) {
    case '\\':
      switch (t[++i]) {
      case 't':
        s[j] = '\t';
        break;
      case 'n':
        s[j] = '\n';
        break;
      default:
        s[j++] = '\\';
        s[j] = t[i];
        break;
      }
      break;
    default:
      s[j] = t[i];
      break;
    }
  }

  s[j] = '\0';
}
