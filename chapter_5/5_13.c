#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXSTOR 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], char *linestor, int nlines);
void writelines(char *lineptr[], int nlines, int nlast);

int main(int argc, char *argv[]) {
  int nlines, nlast = 0;
  char linestor[MAXSTOR];

  if (argc == 2 && *argv[1] == '-')
    nlast = atoi(&*(argv[1] + 1));
  else
    nlast = 10;

  if (nlast == 0) {
    printf("error: wrong number of lines\n");
    return 1;
  }

  if ((nlines = readlines(lineptr, linestor, MAXLINES)) >= 0) {
    writelines(lineptr, nlines, nlast);
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

void writelines(char *lineptr[], int nlines, int nlast) {
  lineptr += nlines - nlast;
  while (nlast-- > 0)
    printf("%s\n", *lineptr++);
}
