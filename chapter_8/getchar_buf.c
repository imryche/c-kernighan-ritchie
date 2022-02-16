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
  static char buf[BUFSIZ];
  static char *bufp = buf;
  static int n = 0;

  if (n == 0) {
    n = read(0, buf, sizeof buf);
    bufp = buf;
  }
  return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
