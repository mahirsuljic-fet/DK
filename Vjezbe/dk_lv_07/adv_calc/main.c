#include <stdio.h>

union MojaUnija {
    int i;
    double d;
};

int main() {
  union MojaUnija d;
  d.i = 5;
  printf("%d\n", d.i);

  d.d = 5.10;
  printf("%lfd\n", d.d);

  d.d = 10.0;
  printf("%d\n", d.i);
}
