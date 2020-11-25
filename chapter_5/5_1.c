#include <stdio.h>
#include <ctype.h>

#define SIZE 100
#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getint(int *);

int buf[BUFSIZE];
int bufp = 0;

int main() {
  int n, array[SIZE] = {0};
  for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    ;

  for (int i = 0; i < SIZE; i++)
    printf("%d ", array[i]);
  printf("\n");
  return 0;
}

int getint(int *pn) {
  int c, s, sign;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    s = c;
    c = getch();
    if (!isdigit(c)) {
      if (c != EOF)
        ungetch(c);
      ungetch(s);
      return s;
    }
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
