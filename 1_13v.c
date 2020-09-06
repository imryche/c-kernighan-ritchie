#include <stdio.h>

#define MAXLEN 20

int main() {
  int c, count, height;
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

  height = 0;
  for (int i = 0; i < MAXLEN; ++i)
    if (wordlen[i] > height)
      height = wordlen[i];

  int row, col;
  for (row = height; row > 0; --row) {
    printf("%3d | ", row);
    for (col = 0; col < MAXLEN; ++col) {
      if (row <= wordlen[col]) {
        printf(" * ");
      } else {
        printf("   ");
      }
    }
    putchar('\n');
  }

  printf("     ");

  for (int i = 1; i <= 20; i++)
    printf("---");

  putchar('\n');
  printf("     ");

  for (int i = 1; i <= 20; i++)
    printf("%3d", i);

  putchar('\n');
}
