#define NULL 0
#define EOF (-1)
#define BUFSIZ 1024
#define OPEN_MAX 20

typedef struct _iobuf {
  int cnt;
  char *ptr;
  char *base;
  int flag;
  int fd;
} FILE_;
FILE_ _iobb[OPEN_MAX];

#define std_in (&_iobb[0])
#define std_out (&_iobb[1])
#define std_err (&_iobb[2])

enum _flags { _READ = 01, _WRITE = 02, _UNBUF = 04, _EOF = 010, _ERR = 020 };

int _fillbuf(FILE_ *);
int _flushbuf(int, FILE_ *);

#define f_eof(p) (((p)->flag & _EOF) != 0)
#define f_error(p) (((p)->flag & _ERR) != 0)
#define file_no(p) (((p)->fd)

#define get_c(p) (--(p)->cnt >= 0 ? (unsigned char)*(p)->ptr++ : _fillbuf(p))
#define put_c(x, p) (--(p)->cnt >= 0 ? *(p)->ptr++ = (x) : _flushbuf((x), p))

#define get_char() get_c(stdin)
#define put_char(x) put_c((x), stdout)

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PERMS 0666

FILE_ *f_open(char *name, char *mode) {
  int fd;
  FILE_ *fp;

  if (*mode != 'r' && *mode != 'w' && *mode != 'a')
    return NULL;
  for (fp = _iobb; fp < _iobb + OPEN_MAX; fp++)
    if ((fp->flag & (_READ | _WRITE)) == 0)
      break;
  if (fp >= _iobb + OPEN_MAX)
    return NULL;

  if (*mode == 'w')
    fd = creat(name, PERMS);
  else if (*mode == 'a') {
    if ((fd = open(name, O_WRONLY, 0)) == -1)
      fd = creat(name, PERMS);
    lseek(fd, 0L, 2);
  } else
    fd = open(name, O_RDONLY, 0);
  if (fd == -1)
    return NULL;

  fp->fd = fd;
  fp->cnt = 0;
  fp->base = NULL;
  fp->flag = (*mode == 'r') ? _READ : _WRITE;

  return fp;
}

int _fillbuf(FILE_ *fp) {
  int bufsize;

  if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
    return EOF;

  bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
  if (fp->base == NULL)
    if ((fp->base = (char *)malloc(bufsize)) == NULL)
      return EOF;

  fp->ptr = fp->base;
  fp->cnt = read(fp->fd, fp->ptr, bufsize);

  if (--fp->cnt < 0) {
    if (fp->cnt == -1)
      fp->flag |= _EOF;
    else
      fp->flag |= _ERR;
    fp->cnt = 0;
    return EOF;
  }

  return (unsigned char)*fp->ptr++;
}

int f_seek(FILE_ *fp, long offset, int origin) {
  unsigned nc;
  long rc = 0;

  if (fp->flag & _READ) {
    if (origin == 1)
      offset -= fp->cnt;
    rc = lseek(fp->fd, offset, origin);
    fp->cnt = 0;
  } else if (fp->flag & _WRITE) {
    if ((nc = fp->ptr - fp->base) > 0)
      if (write(fp->fd, fp->base, nc) != nc)
        rc = -1;
    if (rc != -1)
      rc = lseek(fp->fd, offset, origin);
  }
  return (rc == -1) ? -1 : 0;
}

void filecopy(FILE_ *, FILE *);

int main(int argc, char *argv[]) {
  FILE_ *fp;

  if ((fp = f_open(*++argv, "r")) == NULL) {
    printf("cat: can't open %s\n", *argv);
    return 1;
  } else {
    filecopy(fp, stdout);
  }

  return 0;
}

void filecopy(FILE_ *ifp, FILE *ofp) {
  int c;

  while ((c = get_c(ifp)) != EOF)
    putc(c, ofp);
}
