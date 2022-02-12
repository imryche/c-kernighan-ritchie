#include <stdio.h>

#define is_upper_fast(c) (c >= 'A' && c <= 'Z')

int is_upper(char);

int main() {
  int c = 'x';
  printf("%c is %s\n", c, is_upper(c) ? "upper" : "lower");
  printf("%c is %s\n", c, is_upper_fast(c) ? "upper" : "lower");
}

int is_upper(char c) { return c >= 'A' && c <= 'Z'; }
