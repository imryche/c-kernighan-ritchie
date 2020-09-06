#include <stdio.h>

#define MAXLEN 1000

int main() {
  int c, count;
  int wordlen[MAXLEN];

  count = 0;
  for (int i = 0; i < MAXLEN; ++i)
    wordlen[i] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (count <= MAXLEN)
        ++wordlen[count - 1];
      count = 0;
    } else {
      ++count;
    }
  }


  for (int i = 0; i < MAXLEN; ++i) {
    if (wordlen[i] > 0) {
      printf("%2d|", i + 1);
      for (int j = 0; j < wordlen[i]; ++j) {
        printf("*");
      }
      putchar('\n');
    }
  }
}
