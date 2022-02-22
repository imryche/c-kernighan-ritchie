#define NAME_MAX 14

typedef struct {
  long ino;
  char name[NAME_MAX + 1];
} Dirent;

typedef struct {
  int fd;
  Dirent d;
} DIR_;

DIR_ *open_dir(char *dirname);
Dirent *read_dir(DIR_ *dfd);
void close_dir(DIR_ *dfd);

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void fsize(char *);

int main(int argc, char **argv) {
  if (argc == 1)
    fsize(".");
  else
    while (--argc > 0)
      fsize(*++argv);
  return 0;
}

void dirwalk(char *, void (*fcn)(char *));

void fsize(char *name) {
  struct stat stbuf;

  if (stat(name, &stbuf) == -1) {
    fprintf(stderr, "fsize: can't access %s\n", name);
    return;
  }
  if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
    dirwalk(name, fsize);
  printf("%8ld %s\n", (long)stbuf.st_size, name);
}

#define MAX_PATH 1024

void dirwalk(char *dir, void (*fcn)(char *)) {
  char name[MAX_PATH];
  Dirent *dp;
  DIR_ *dfd;

  if ((dfd = open_dir(dir)) == NULL) {
    fprintf(stderr, "dirwalk: can't open %s\n", dir);
    return;
  }
  while ((dp = read_dir(dfd)) != NULL) {
    if (strcmp(dp->name, ".") == 0 || strcmp(dp->name, "..") == 0)
      continue;
    if (strlen(dir) + strlen(dp->name) + 2 > sizeof(name))
      fprintf(stderr, "dirwalk: name %s %s too long\n", dir, dp->name);
    else {
      sprintf(name, "%s/%s", dir, dp->name);
      (*fcn)(name);
    }
  }
  close_dir(dfd);
}

#ifndef DIR_SIZ
#define DIR_SIZ 14
#endif
struct direct {
  ino_t d_ino;
  char d_name[DIR_SIZ];
};

int fstat(int fd, struct stat *);

DIR_ *open_dir(char *dirname) {
  int fd;
  struct stat stbuf;
  DIR_ *dp;

  if ((fd = open(dirname, O_RDONLY, 0)) == -1 || fstat(fd, &stbuf) == -1 ||
      (stbuf.st_mode & S_IFMT) != S_IFDIR ||
      (dp = (DIR_ *)malloc(sizeof(DIR_))) == NULL)
    return NULL;
  dp->fd = fd;
  return dp;
}

void close_dir(DIR_ *dp) {
  if (dp) {
    close(dp->fd);
    free(dp);
  }
}

#include <sys/dir.h>

Dirent *read_dir(DIR_ *dp) {
  struct direct dirbuf;
  static Dirent d;

  while (read(dp->fd, (char *) &dirbuf, sizeof(dirbuf)) == sizeof(dirbuf)) {
    if (dirbuf.d_ino == 0)
      continue;
    d.ino = dirbuf.d_ino;
    strncpy(d.name, dirbuf.d_name, DIR_SIZ);
    d.name[DIR_SIZ] = '\0';
    return &d;
  }
  return NULL;
}
