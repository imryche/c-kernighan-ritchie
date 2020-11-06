#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNC 'f'
#define MAXVAL 100
#define BUFSIZE 100

int getop(char s[]);
void mathfunc(char s[]);
void push(double);
double pop(void);
void clear(void);
int getch(void);
void ungetch(int);

int sp = 0;
double val[MAXVAL];
char buf[BUFSIZE];
int bufp = 0;

int main() {
  int type;
  double op1, op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case FUNC:
      mathfunc(s);
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      if (op2 != 0.0)
        push(pop() / op2);
      else
        printf("error: zero divisor\n");
      break;
    case '%':
      op2 = pop();
      if (op2 != 0.0)
        push(fmod(pop(), op2));
      else
        printf("error: zero modulo\n");
      break;
    case '?':
      op2 = pop();
      printf("\t%.8g\n", op2);
      push(op2);
      break;
    case 'd':
      op2 = pop();
      push(op2);
      push(op2);
      break;
    case 's':
      op1 = pop();
      op2 = pop();
      push(op1);
      push(op2);
      break;
    case 'c':
      clear();
      break;
    case '\n':
      printf("\t%.8g\n", pop());
      break;
    default:
      printf("error: unknown command %s\n", s);
      break;
    }
  }
  return 0;
}

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void clear(void) {
  sp = 0;
}

int getop(char s[]) {
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;

  s[1] = '\0';
  i = 0;

  if (islower(c)) {
    while (islower(s[++i] = c = getch()))
      ;

    s[i] = '\0';

    if (c != EOF)
      ungetch(c);

    if (strlen(s) > 1)
      return FUNC;
    else
      return c;
  }

  if (!isdigit(c) && c != '.' && c != '-')
    return c;

  if (c == '-') {
    if (isdigit(c = getch()))
      s[++i] = c;
    else {
      if (c != EOF)
        ungetch(c);
      return '-';
    }
  }

  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;

  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';
  if (c != EOF)
    ungetch(c);

  return NUMBER;
}

void mathfunc(char s[]) {
  double op2;

  if (strcmp(s, "sin") == 0) {
    push(sin(pop()));
  } else if (strcmp(s, "exp") == 0) {
    push(exp(pop()));
  } else if (strcmp(s, "pow") == 0) {
    op2 = pop();
    push(pow(op2, pop()));
  }
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
