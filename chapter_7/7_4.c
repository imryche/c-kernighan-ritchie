#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>


void minscanf(char *fmt, ...) {
  va_list ap;
  char *p;

  va_start(ap, fmt);
  for (p = fmt; *p; p++) {
    if (*p != '%')
      continue;
    switch (*++p) {
    case 'd':
      scanf("%d", va_arg(ap, int *));
      break;
    case 's':
      scanf("%s", va_arg(ap, char *));
    }
  }
}


int main() {
  int day, year;
  char monthname[20];

  minscanf("%d %s %d", &day, monthname, &year);
  printf("%d %s %d\n", day, monthname, year);
}
