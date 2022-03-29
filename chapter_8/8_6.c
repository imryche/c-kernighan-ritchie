#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef long Align;

union header {
  struct {
    union header *ptr;
    unsigned size;
  } s;
  Align x;
};

typedef union header Header;

static Header base;
static Header *freep = NULL;

void *mymalloc(unsigned nbytes) {
  Header *p, *prevp;
  Header *morecore(unsigned);
  unsigned nunits;

  nunits = (nbytes + sizeof(Header) - 1) / sizeof(Header) + 1;
  if ((prevp = freep) == NULL) {
    base.s.ptr = freep = prevp = &base;
    base.s.size = 0;
  }
  for (p = prevp->s.ptr;; prevp = p, p = p->s.ptr) {
    if (p->s.size >= nunits) {
      if (p->s.size == nunits)
        prevp->s.ptr = p->s.ptr;
      else {
        p->s.size -= nunits;
        p += p->s.size;
        p->s.size = nunits;
      }
      freep = prevp;
      return (void *)(p + 1);
    }
    if (p == freep)
      if ((p = morecore(nunits)) == NULL)
        return NULL;
  }
}

#define NALLOC 1024

Header *morecore(unsigned nu) {
  char *cp;
  Header *up;
  void myfree(void *);

  if (nu < NALLOC)
    nu = NALLOC;
  cp = sbrk(nu * sizeof(Header));
  if (cp == (char *)-1)
    return NULL;
  up = (Header *)cp;
  up->s.size = nu;
  myfree((void *)(up + 1));

  return freep;
}

void *mycalloc(unsigned n, unsigned size) {
  unsigned i, nb;
  char *p, *q;

  nb = n * size;
  if ((p = q = mymalloc(nb)) != NULL)
    for (i = 0; i < nb; i++)
      *p++ = 0;
  return q;
}

void myfree(void *ap) {
  Header *bp, *p;

  bp = (Header *)ap - 1;
  for (p = freep; !(bp > p && bp < p->s.ptr); p = p->s.ptr)
    if (p >= p->s.ptr && (bp > p || bp < p->s.ptr))
      break;

  if (bp + bp->s.size == p->s.ptr) {
    bp->s.size += p->s.ptr->s.size;
    bp->s.ptr = p->s.ptr->s.ptr;
  } else
    bp->s.ptr = p->s.ptr;

  if (p + p->s.size == bp) {
    p->s.size += bp->s.size;
    p->s.ptr = bp->s.ptr;
  } else
    p->s.ptr = bp;
  freep = p;
}

int main() {
  int i, n;
  int *a;

  n = 10;
  a = (int *)mycalloc(n, sizeof(int));
  for (i = 0; i < n; i++)
    a[i] = i;

  myfree(a);
  return 0;
}
