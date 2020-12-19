#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000
#define MAXSTOR 5000
#define MAXLEN 1000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);
int getln(char *, int);

void quicksort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int charcmp(char *, char *);

int fold = 0;
int dir = 0;

int main(int argc, char *argv[]) {
  extern int dir;
  int c, nlines;
  int numeric = 0;
  int reverse = 0;
  int (*cmp_proc)(void *, void *) = strcmp;

  while (--argc > 0 && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      switch (c) {
      case 'n':
        cmp_proc = numcmp;
        break;
      case 'f':
        fold = 1;
        dir = 0;
        cmp_proc = charcmp;
        break;
      case 'd':
        dir = 1;
        cmp_proc = charcmp;
        break;
      case 'r':
        reverse = 1;
        break;
      }

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    quicksort((void **) lineptr, 0, nlines - 1, (int (*)(const char *, const char *))cmp_proc);
    writelines(lineptr, nlines, reverse);
    return 0;
  } else {
    printf("input too big to sort\n");
    return 1;
  }
}

void quicksort(void *v[], int left, int right, int (*comp)(void *, void *)) {
  int i, last;
  void swap(void *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if ((*comp)(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  quicksort(v, left, last - 1, comp);
  quicksort(v, last + 1, right, comp);
}

int numcmp(char *s1, char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

int charcmp(char *s, char *t) {
  char a, b;
  extern int fold;
  extern int dir;

  do {
    if (dir) {
      while (!isalnum(*s) && *s != ' ' && *s != '\0')
        s++;
      while (!isalnum(*t) && *t != ' ' && *t != '\0')
        t++;
    }

    a = fold ? tolower(*s): *s;
    s++;
    b = fold ? tolower(*t): *t;
    t++;

    if (a == b && a == '\0')
      return 0;
  } while (a == b);

  return a - b;
}

void swap(void *v[], int i, int j) {
  void *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}

int readlines(char *lineptr[], int maxlines) {
  int len, nlines;
  char *p, line[MAXLEN];

  nlines = 0;
  while((len = getln(line, MAXLEN)) > 0)
    if (nlines >= maxlines || (p = malloc(len)) == NULL) {
      return -1;
    } else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
    }

  return nlines;
}

int getln(char *s, int lim) {
  int c, i;
  char *t = s;

  for (; s - t  < lim - 1 && (c = getchar()) != EOF && c != '\n'; s++)
    *s = c;

  if (c == '\n') 
    *s++ = c;

  *s = '\0';

  return s - t;
}

void writelines(char *lineptr[], int nlines, int reverse) {
  int i;

  if (reverse)
    for (i = nlines - 1; i >= 0; i--)
        printf("%s\n", lineptr[i]);
  else
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}
