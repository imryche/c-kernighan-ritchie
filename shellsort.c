#include <stdio.h>

void print_array(int v[], int len);
void shellsort(int v[], int n);

int main() {
  int v[9] = {7, 6, 8, 9, 3, 2, 10, 5, 1};

  printf("initial:\n");
  print_array(v, 9);
  shellsort(v, 9);
  printf("shellsorted:\n");
  print_array(v, 9);
    
  return 0;
}

void print_array(int v[], int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", v[i]);
  printf("\n");
}

void shellsort(int v[], int n) {
  int gap, i, j, temp;

  for (gap = n / 2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap) {
        temp = v[j];
        v[j] = v[j + gap];
        v[j + gap] = temp;
      }
}
