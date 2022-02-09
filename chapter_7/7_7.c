#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  long lineno = 0;
  int c, except = 0, number = 0, found = 0;
  char *pattern;

  while (--argc > 0 && (*++argv)[0] == '-')
    while ((c = *++argv[0]))
      switch (c) {
      case 'x':
        except = 1;
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

  if (argc == 0) {
    printf("Usage: find -x -n pattern file1 file2\n");
    exit(1);
  }

  pattern = *argv++;
  argc--;

  struct File {
    char *name;
    FILE *file;
  };

  struct File files[argc + 1];
  int filesc = argc;

  if (argc == 0) {
    files[0].file = stdin;
    files[0].name = "stdin";
    filesc++;
  } else {
    while (argc-- > 0) {
      files[argc].file = fopen(*argv, "r");
      files[argc].name = *argv++;
    }
  }

  int multiple = filesc > 1 ? 1 : 0;
  while (filesc-- > 0) {
    while (fgets(line, MAXLINE, files[filesc].file)) {
      lineno++;
      if ((strstr(line, pattern) != NULL) != except) {
        if (multiple)
          printf("%s:", files[filesc].name);
        if (number)
          printf("%ld:", lineno);
        printf("%s", line);
        found++;
      }
    }
  }

  return 0;
}
