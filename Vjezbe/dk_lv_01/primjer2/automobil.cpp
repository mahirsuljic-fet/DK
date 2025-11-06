#include "automobil.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &out, const Automobil &automobil) {
  return out << automobil.model() << " " << automobil.boja() << " "
             << automobil.godinaProizvodnje();
}
