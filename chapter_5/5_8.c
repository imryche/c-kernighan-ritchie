#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main() {
  int m, d;
  month_day(1988, 600, &m, &d);
  printf("%d %d\n", d, m);
  printf("%d\n", day_of_year(1988, 2, 29));
  return 0;
}

int day_of_year(int year, int month, int day) {
  int i, leap;

  if (year < 1)
    return -1;

  if (month < 1 || month > 12)
    return -1;

  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  for (i = 1; i < month; i++)
    day += daytab[leap][i];
  return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
  int i, leap, maxday;

  if (year < 1) {
    *pmonth = -1;
    *pday = -1;
    return;
  }

  leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
  maxday = leap == 1 ? 366 : 365;
  printf("%d\n", maxday);

  if (yearday < 1 || yearday > maxday) {
    *pmonth = -1;
    *pday = -1;
    return;
  }

  for (i = 1; yearday > daytab[leap][i]; i++)
    yearday -= daytab[leap][i];
  *pmonth = i;
  *pday = yearday;
}
