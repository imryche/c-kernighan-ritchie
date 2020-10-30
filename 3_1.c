#include <stdio.h>

int binsearch(int x, int v[], int n);

int main() {
  int arr[] = {1, 2, 3, 5, 6, 7};
  printf("%d", binsearch(5, arr, 7));
  return 0;
}

int binsearch(int x, int v[], int n) {
  int low, high, mid;

  low = 0;
  high = n - 1;

  mid = (low + high) / 2;

  while (low <= high && x != v[mid]) {
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid + 1;

    mid = (low + high) / 2;
  }

  if (x == v[mid])
    return mid;

  return -1;
}
