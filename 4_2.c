#include <stdio.h>
#include <ctype.h>

double atof(char s[]);

int main() {
  printf("%.7f\n", atof("123.45e-6"));
  return 0;
}

double atof(char s[]) {
  double val, power, exp;
  int i, j, sign, esign;

  for (i = 0; isspace(s[i]); i++)
    ;

  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');

  if (s[i] == '.')
    i++;

  for (power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10;
  }

  if (tolower(s[i]) == 'e')
    i++;

  esign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-')
    i++;

  for (j = 0; isdigit(s[i]) && j < (s[i] - '0'); j++) {
    if (esign > 0)
      val *= 10;
    else
      val /= 10;
  }
  
  return sign * val / power;
}
