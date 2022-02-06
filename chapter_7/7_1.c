#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  int c;

  if (strstr(*argv, "lower") != 0)
    while ((c = getchar()) != EOF)
      putchar(tolower(c));
  else
    while ((c = getchar()) != EOF)
      putchar(toupper(c));

  return 0;
}
