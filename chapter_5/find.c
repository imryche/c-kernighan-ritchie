#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getln(char *line, int max);

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;

  while (--argc > 0 && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      switch (c) {
      case 'x':
        except =  1;
        break;
      case 'n':
        number = 1;
        break;
      default:
        printf("find: illegal option %c\n", c);
        argc = 0;
        found = -1;
        break;
      }

  if (argc != 1)
    printf("Usage: find -x -n pattern\n");
  else
    while (getln(line, MAXLINE) > 0) {
      lineno++;
      if ((strstr(line, *argv) != NULL) != except) {
        if (number)
          printf("%ld:", lineno);
        printf("%s", line);
        found++;
      }
    }

  return found;
}

int getln(char *s, int max) {
  int c, i;
  char *t = s;

  for (; s - t  < max - 1 && (c = getchar()) != EOF && c != '\n'; s++)
    *s = c;

  if (c == '\n') 
    *s++ = c;

  *s = '\0';

  return s - t;
}
