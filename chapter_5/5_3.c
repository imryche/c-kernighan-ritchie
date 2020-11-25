#include <stdio.h>
#include <string.h>

void strconcat(char *, char *);

int main() {
  char src[50], dest[50];

  strcpy(src,  "This is source");
  strcpy(dest, "This is destination");

  strconcat(dest, src);
  printf("%s\n", dest);
  return 0;
}

void strconcat(char *s, char *t) {
  while(*s)
    s++;
  while ((*s++ = *t++))
    ;
}
