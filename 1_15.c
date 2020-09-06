#include <stdio.h>

float f_to_c(int f);

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  while (fahr <= upper) {
    celsius = f_to_c(fahr);
    printf("%3.0f\t%6.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

float f_to_c(int f) {
  return (5.0 / 9.0) * (f - 32.0);
}
