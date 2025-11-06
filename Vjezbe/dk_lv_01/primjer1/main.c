#include <stdio.h>

#define ARRAY_SIZE(x) sizeof(x) / sizeof(*x)

int sumiraj(int *elements, int n) {
  int r = 0;
  for (int i = 0; i < n; i++)
    r += elements[i];
  return r;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
  printf("Niz sadrzi %lu elemenata\n", ARRAY_SIZE(arr));
  int r = sumiraj(arr, ARRAY_SIZE(arr));
  printf("Suma elemenata: %d\n", r);
  return 0;
}
