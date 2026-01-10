#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

union Foo {
  int a;
  float b;
  char *c;
  std::string *id;
  std::vector<int> *ints;
};

int main() {
  union Foo moja_struktura;
  printf("sizeof Foo %lu\n", sizeof(union Foo));
  moja_struktura.a = 5;
  printf("Foo.a = %d\n", moja_struktura.a);
  moja_struktura.b = 5.0;
  // .....

  printf("Foo.a = %d\n", moja_struktura.a);
  printf("Foo.b = %f\n", moja_struktura.b);
  moja_struktura.a = 10;
  free(moja_struktura.c);

  moja_struktura.id = new std::string{"samir"};
  delete moja_struktura.id;

  moja_struktura.ints = new std::vector<int>{};

  moja_struktura.ints->push_back(5);
  moja_struktura.ints->push_back(6);
  moja_struktura.ints->push_back(7);

  delete moja_struktura.ints;
}
