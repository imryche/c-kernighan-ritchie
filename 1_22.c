/*
this text should be folded
*/

#include <stdio.h>

#define FOLD 10
#define MAXBUF 100

int main() {
  int c, pos, bufpos;
  char buf[MAXBUF];

  pos = bufpos = 0;
  while ((c = getchar()) != EOF) {
    ++pos;

    if (c == ' ' || c == '\t') {
      buf[bufpos] = c;
      ++bufpos;
    } 

    if (bufpos > 0 && pos <= FOLD) {
      for (int i = 0; i < bufpos; ++i) {
        putchar(buf[i]);
      }
      bufpos = 0;
    }

    if (c != ' ' && c != '\t')
      putchar(c);

    if (pos == FOLD) {
      putchar('\n');
      pos = 0;
    }
  }

  return 0;
}
