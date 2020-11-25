#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXSTOR 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], char *linestor, int nlines);
void writelines(char *lineptr[], int nlines);
void qqsort(char *lineptr[], int left, int right);

int main() {
  int nlines;
  char linestor[MAXSTOR];

  if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) {
    qqsort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  } else {
    printf("error: input too big to sort\n");
    return 1;
  }
}

#define MAXLEN 1000
int getln(char *, int);

int readlines(char *lineptr[], char *linestor, int maxlines) {
  int len, nlines;
  char line[MAXLEN];
  char *p = linestor;
  char *linestop = linestor + MAXSTOR;

  nlines = 0;
  while((len = getln(line, MAXLEN)) > 0)
    if (nlines >= maxlines || p + len > linestop) {
      return -1;
    } else {
      line[len - 1] = '\0';
      strcpy(p, line);
      lineptr[nlines++] = p;
      p += len;
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

void writelines(char *lineptr[], int nlines) {
  while (nlines-- > 0)
    printf("%s\n", *lineptr++);
}

void qqsort(char *v[], int left, int right) {
  int i, last;
  void swap(char *v[], int i, int j);

  if (left >= right)
    return;
  swap(v, left, (left + right) / 2);
  last = left;
  for (i = left + 1; i <= right; i++)
    if (strcmp(v[i], v[left]) < 0)
      swap(v, ++last, i);
  swap(v, left, last);
  qqsort(v, left, last - 1);
  qqsort(v, last + 1, right);
}

void swap(char *v[], int i, int j) {
  char *temp;

  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}
