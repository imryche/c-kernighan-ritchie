#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main() {
  int m, d;
  month_day(1988, 60, &m, &d);
  printf("%d %d\n", d, m);
  printf("%d\n", day_of_year(1988, 2, 29));
  return 0;
}

int day_of_year(int year, int month, int day) {
  int i, leap;
  char *p;

  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  p = daytab[leap];
  while (month--)
    day += *p++;
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap;
  char *p;

  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  for (p = daytab[leap]; yearday > *p; p++)
    yearday -= *p;
  *pmonth = p - *(daytab + leap);
  *pday = yearday;
}
