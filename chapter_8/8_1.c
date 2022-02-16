#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void filecopy(int, int);

int main(int argc, char *argv[]) {
  int fd;

  if (argc == 1)
    filecopy(0, 1);
  else
    while (--argc > 0)
      if ((fd = open(*++argv, O_RDONLY)) == -1) {
        printf("cat: can't open %s\n", *argv);
        return 1;
      } else {
        filecopy(fd, 1);
        close(fd);
      }

  return 0;
}

void filecopy(int ifd, int ofd) {
  int n;
  char buf[BUFSIZ];

  while ((n = read(ifd, buf, BUFSIZ)) > 0)
    if (write(ofd, buf, n) != n)
      printf("cat: write error");
}
