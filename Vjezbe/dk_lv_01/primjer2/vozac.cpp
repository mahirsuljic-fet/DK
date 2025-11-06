#include "vozac.hpp"
#include <iostream>

std::ostream &operator<<(std::ostream &out, const Vozac &vozac) {
  return out << vozac.ime() << " " << vozac.prezime() << " " << vozac.godine()
             << " " << vozac.automobil() << " " << vozac.godineStaza() << " "
             << vozac.vrijeme();
}
