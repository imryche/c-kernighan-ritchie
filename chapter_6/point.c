#include <stdio.h>

#define XMAX 10
#define YMAX 20
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

struct point {
  int x;
  int y;
};

struct rect {
  struct point pt1;
  struct point pt2;
};

int main() {
  struct rect screen;
  struct point pt1, pt2, pt3, middle, added;
  struct point makepoint(int, int);
  struct point addpoint(struct point, struct point);
  int pinrect(struct point, struct rect);
  struct rect canonrect(struct rect);

  pt1 = makepoint(5, 5);
  pt2 = makepoint(XMAX, YMAX);
  pt3 = makepoint(7, 7);

  screen.pt1 = pt2;
  screen.pt2 = pt1;
  printf("rect: %d %d, %d %d\n", screen.pt1.x, screen.pt1.y, screen.pt2.x, screen.pt2.y);

  screen = canonrect(screen);
  printf("canonrect: %d %d, %d %d\n", screen.pt1.x, screen.pt1.y, screen.pt2.x, screen.pt2.y);

  middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
                     (screen.pt1.y + screen.pt2.y) / 2);
  printf("middle: x is %d, y is %d\n", middle.x, middle.y);

  added = addpoint(pt1, pt2);
  printf("addpoint: x is %d, y is %d\n", added.x, added.y);

  printf("pinrect: %d\n", pinrect(pt3, screen));

  struct point p4 = makepoint(3, 9);
  struct point *p = &p4;
  printf("p4: x is %d, y is %d\n", (*p).x, (*p).y);
  printf("p4: x is %d, y is %d\n", p->x, p->y);
}

struct point makepoint(int x, int y) {
  struct point temp;

  temp.x = x;
  temp.y = y;
  return temp;
}

struct point addpoint(struct point p1, struct point p2) {
  p1.x += p2.x;
  p1.y += p2.y;
  return p1;
}

int pinrect(struct point p, struct rect r) {
  return p.x >= r.pt1.x && p.x < r.pt2.x
    && p.y >= r.pt1.y && p.y < r.pt2.y;
}

struct rect canonrect(struct rect r) {
  struct rect temp;

  temp.pt1.x = min(r.pt1.x, r.pt2.x);
  temp.pt1.y = min(r.pt1.y, r.pt2.y);
  temp.pt2.x = max(r.pt1.x, r.pt2.x);
  temp.pt2.y = max(r.pt1.y, r.pt2.y);
  return temp;
}
