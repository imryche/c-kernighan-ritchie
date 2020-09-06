#include <stdio.h>

int main() {
  int c, sc, tc;

  sc = 0;
  tc = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ')
      ++sc;
    if (c == '\t')
      ++tc;
  }

  printf("Spaces: %d\nTabs: %d\n", sc, tc);
}
