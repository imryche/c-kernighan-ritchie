#include <stdio.h>
#include <unistd.h>

int get_char(void);

int main() {
  char c;

  while ((c = get_char()) != EOF)
    putchar(c);

  return 0;
}

int get_char(void) {
  char c;

  return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}
