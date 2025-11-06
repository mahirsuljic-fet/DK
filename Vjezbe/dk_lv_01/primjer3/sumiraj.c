
int sumiraj(int *elements, int n) {
  int r = 0;
  for (int i = 0; i < n; i++)
    r += elements[i];
  return r;
}
