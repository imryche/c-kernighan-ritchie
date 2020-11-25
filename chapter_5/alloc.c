#include <stdio.h>

#define ALLOCSIZE 10000

char *alloc(int);
void afree(char *);

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

int main() {
  char *s;
  s = alloc(9999);
  /* s = alloc(100); */
  if (s) {
    printf("memory was allocated\n");
  } else
    printf("out of memory\n");
  return 0;
}

char *alloc(int n) {
  if (allocbuf + ALLOCSIZE - allocp >= n) {
    allocp += n;
    return allocp - n;
  } else
    return 0;
}

void afree(char *p) {
  if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
    allocp = p;
}
