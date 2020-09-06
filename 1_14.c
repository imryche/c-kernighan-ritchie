#include <stdio.h>

#define ASCII_MIN 32
#define ASCII_MAX 126

int main() {
  int c, count, height, size;
  size = ASCII_MAX - ASCII_MIN;
  int ascii_num[size];

  count = 0;
  for (int i = 0; i < size; ++i)
    ascii_num[i] = 0;

  while ((c = getchar()) != EOF) {
    ++ascii_num[c - 32];
  }

  for (int i = 0; i < size; ++i)
    printf("%d ", ascii_num[i]);

  height = 0;
  for (int i = 0; i < size; ++i)
    if (ascii_num[i] > height)
      height = ascii_num[i];

  int row, col;
  for (row = height; row > 0; --row) {
    printf("%3d | ", row);
    for (col = 0; col < size; ++col) {
      if (row <= ascii_num[col]) {
        printf("*");
      } else {
        printf(" ");
      }
    }
    putchar('\n');
  }

  printf("      ");
  for (int i = 0; i < size; ++i)
    putchar('-');
  putchar('\n');
  printf("      ");

  for (int i = 0; i < size; i++)
    printf("%c", i + ASCII_MIN);

  putchar('\n');
}
