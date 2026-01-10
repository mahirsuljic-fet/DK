#include <stdio.h>
#include <stdlib.h>

union Foo {
  int a;
  float b;
  char *c;
  std::string s;
};

int main() {
  union Foo moja_struktura;
  printf("sizeof Foo %lu\n", sizeof(union Foo));
  moja_struktura.a = 5;
  printf("Foo.a = %d\n", moja_struktura.a);
  moja_struktura.b = 5.0;
  printf("Foo.a = %d\n", moja_struktura.a);
  printf("Foo.b = %f\n", moja_struktura.b);
  moja_struktura.c = malloc(10);
  moja_struktura.a = 10;
  free(moja_struktura.c);
}
