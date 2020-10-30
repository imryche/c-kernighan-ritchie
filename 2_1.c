#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
  printf("int min: %d, max: %d\n", INT_MIN, INT_MAX);
  printf("short min: %d, max: %d\n", SHRT_MIN, SHRT_MAX);
  printf("char min: %d\n", CHAR_MIN);
  printf("long min: %ld, max: %ld\n", LONG_MIN, LONG_MAX);
  return 0;
}
