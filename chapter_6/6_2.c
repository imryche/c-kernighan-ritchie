#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define MATCH 1
#define NOMATCH 0

struct tnode *addtree(struct tnode *, char *, int);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *strdupp(char *);

struct tnode {
  char *word;
  int match;
  struct tnode *left;
  struct tnode *right;
};

int main(int argc, char *argv[]) {
  struct tnode *root;
  char word[MAXWORD];
  int symcount;

  if (argc == 1)
    symcount = 6;
  else if (argc == 2)
    symcount = atoi(argv[1]);
  else {
    printf("usage: treecount [n] < file\n");
    return 1;
  }
    
  root = NULL;
  while (getword(word, MAXWORD) != EOF)
    if (isalpha(word[0]))
      root = addtree(root, word, symcount);
  treeprint(root);

  return 0;
}

int getword(char *word, int lim) {
  int c, lastc, getch(void);
  void ungetch(int);
  char *w = word;

  while (isspace(c = getch()))
    ;

  if (c == '"')
    while ((c = getch()) != '"')
      ;

  if (c == '/') {
    if ((c = getch()) != '*')
      ungetch(c);
    else
      while((c = getch()) != '/' && lastc != '*')
        lastc = c;
  }

  if (c != EOF)
    *w++ = c;

  if (!isalpha(c)) {
    *w = '\0';
    return c;
  }

  for (; --lim > 0; w++)
    if (!isalnum(*w = getch())) {
      ungetch(*w);
      break;
    }

  *w = '\0';
  return word[0];
}

struct tnode *addtree(struct tnode *p, char *w, int symcount) {
  int cond;

  if (p == NULL) {
    p = talloc();
    p->word = strdupp(w);
    p->match = NOMATCH;
    p->left = p->right = NULL;
  } else if ((cond = strncmp(w, p->word, symcount)) == 0)
    p->match = MATCH;
  else if (cond < 0)
    p->left = addtree(p->left, w, symcount);
  else
    p->right = addtree(p->right, w, symcount);
  return p;
}

void treeprint(struct tnode *p) {
  if (p != NULL) {
    treeprint(p->left);
    if (p->match)
        printf("%s\n", p->word);
    treeprint(p->right);
  }
}

struct tnode *talloc(void) {
  return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdupp(char *s) {
  char *p;

  p = (char *) malloc(strlen(s) + 1);
  if (p != NULL)
    strcpy(p, s);
  return p;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}
