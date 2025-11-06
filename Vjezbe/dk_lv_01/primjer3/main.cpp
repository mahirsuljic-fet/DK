#include <iostream>
#include <vector>

extern "C" int sumiraj(int *, int);

int main() {
  std::vector<int> arr;
  int t;
  while (std::cin >> t)
    arr.push_back(t);
  int r = sumiraj(arr.data(), arr.size());
  printf("Suma elemenata: %d\n", r);
  return 0;
}
