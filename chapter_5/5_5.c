#include <stdio.h>
#include <string.h>

int strncompare(char *, char *, int);
void strncopy(char *, char *, int);
void strnconcat(char *, char *, int);

int main() {
  char *s = "hello";
  char *t = "hello, world";
  printf("%d\n", strncompare(s, t, 3));

  char a[20];
  char *b;
  b = "hello, world";
  strncopy(a, b, 5);
  printf("%s\n", a);

  char src[50], dest[50];

  strcpy(src,  "This is source");
  strcpy(dest, "This is destination");

  strnconcat(dest, src, 3);
  printf("%s\n", dest);

  return 0;
}

int strncompare(char *s, char *t, int n) {
  for (; *s == *t; s++, t++)
    if (*s == '\0' || --n <= 0)
      return 0;
  return *s - *t;
}

void strncopy(char *s, char *t, int n) {
  while ((*s++ = *t++) && --n > 0)
    ;
}

void strnconcat(char *s, char *t, int n) {
  while(*s)
    s++;
  strncopy(s, t, n);
}

