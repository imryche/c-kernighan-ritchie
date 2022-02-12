#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000
#define PAGELINES 10

int main(int argc, char *argv[]) {
  char line[MAXLINE];
  long lineno = 0;
  int page;

  if (argc == 1) {
    printf("Usage: page file1 file2\n");
    exit(1);
  }

  struct File {
    char *name;
    FILE *file;
  };

  int filesc = --argc;
  struct File files[filesc];

  while (argc-- > 0) {
    files[argc].file = fopen(*++argv, "r");
    files[argc].name = *argv;
  }

  while (filesc-- > 0) {
    page = 0;
    lineno = 0;
    printf("%s:", files[filesc].name);

    while (fgets(line, MAXLINE, files[filesc].file) != NULL) {
      if (lineno % PAGELINES == 0)
        printf("page: %d\n", page++);
      lineno++;
      printf("%s", line);
    }
  }

  return 0;
}
