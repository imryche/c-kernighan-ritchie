#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned hash(char *);
struct nlist *lookup(char *);
struct nlist *install(char *, char *);
void undef(char *);

struct nlist {
  struct nlist *next;
  char *name;
  char *defn;
};

#define HASHSIZE 101

static struct nlist *hashtab[HASHSIZE];

int main() {
  install("foo", "bar");
  undef("foo");
  install("fizz", "buzz");

  struct nlist *value;
  value = lookup("foo");
  if (value == NULL)
    printf("value is empty\n");
  else
    printf("%s\n", value->defn);

  printf("%s\n", lookup("fizz")->defn);

  return 0;
}

unsigned hash(char *s) {
  unsigned hashval;

  for (hashval = 0; *s != '\0'; s++)
    hashval = *s + 31 * hashval;
  return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
  struct nlist *np;

  for (np = hashtab[hash(s)]; np != NULL; np = np->next)
    if (strcmp(s, np->name) == 0)
      return np;
  return NULL;
}

struct nlist *install(char *name, char *defn) {
  struct nlist *np;
  unsigned hashval;

  if ((np = lookup(name)) == NULL) {
    np = (struct nlist *) malloc(sizeof(*np));
    if (np == NULL || (np->name = strdup(name)) == NULL)
      return NULL;
    hashval = hash(name);
    np->next = NULL;
    hashtab[hashval] = np;
  } else
    free((void *) np->defn);
  if ((np->defn = strdup(defn)) == NULL)
    return NULL;
  return np;
}

void undef(char *name) {
  unsigned h;
  struct nlist *np, *prev;

  prev = NULL;
  h = hash(name);

  for (np = hashtab[h]; np != NULL; np = np->next) {
    if (strcmp(name, np->name) == 0)
      break;
    prev = np;
  }

  if (np != NULL) {
    if (prev == NULL)
      hashtab[h] = np->next;
    else
        prev->next = np->next;

    free((void *) np->name);
    free((void *) np->defn);
    free((void *) np);
  }
}
