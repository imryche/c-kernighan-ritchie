#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = -40;
  upper = 40;
  step = 5;

  printf("%3s%6s\n", "C", "F");

  celsius = lower;
  while (celsius <= upper) {
    fahr = celsius * (9.0 / 5.0) + 32.0;
    printf("%3.0f\t%6.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
