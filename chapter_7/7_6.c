#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXFILES 2
#define MAXLINE 500

int main(int argc, char *argv[]) {
  FILE *files[MAXFILES];
  char og[MAXLINE], cmp[MAXLINE];
  char *prog = argv[0];
  int i;

  if (argc != 3) {
    fprintf(stderr, "usage: %s file1 file2\n", prog);
    exit(1);
  }

  for (i = 0; i < MAXFILES; i++)
    if ((files[i] = fopen(*++argv, "r")) == NULL)
      fprintf(stderr, "%s: can't open %s\n", prog, *argv);

  while ((fgets(og, MAXLINE, files[0])) != NULL &&
         (fgets(cmp, MAXLINE, files[1])) != NULL) {
    if (strcmp(og, cmp) != 0) {
      printf("%s", og);
      break;
    }
  }

  exit(0);
}
