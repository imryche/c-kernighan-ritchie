#include <stdio.h>
#include <ctype.h>

#define SIZE 100
#define BUFSIZE 100

int getch(void);
void ungetch(int);
int getint(double *);

int buf[BUFSIZE];
int bufp = 0;

int main() {
  int n;
  double array[SIZE] = {0}, power;
  for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    ;

  for (int i = 0; i < SIZE; i++)
    printf("%.3f ", array[i]);
  printf("\n");
  return 0;
}

int getint(double *pn) {
  int c;
  double sign, power;

  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1.0 : 1.0;
  if (c == '+' || c == '-')
    c = getch();
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  if (c == '.')
    c = getchar();
  for (power = 1.0; isdigit(c); c = getch()){
    *pn = 10.0 * *pn + (c - '0');
    power *= 10;
  }

  *pn = sign * *pn / power;

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
