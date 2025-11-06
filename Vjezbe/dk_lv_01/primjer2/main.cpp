#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

#include "automobil.hpp"
#include "vozac.hpp"

std::istream &operator>>(std::istream &in, Vozac &vozac) {
  std::string input;
  int godine;
  double vrijeme;
  Automobil automobil;

  in >> input;
  vozac.ime(input);

  in >> input;
  vozac.prezime(input);

  in >> godine;
  vozac.godine(godine);

  // unosimo automobil
  in >> input;
  automobil.model(input);
  in >> input;
  automobil.boja(input);
  in >> godine;
  automobil.godinaProizvodnje(godine);
  vozac.automobil(automobil);

  in >> godine;
  vozac.godineStaza(godine);

  in >> vrijeme;
  vozac.vrijeme(vrijeme);

  return in;
}

int main() {
  Vozac flojd;
  std::vector<Vozac> vozaci;
  while (std::cin >> flojd)
    vozaci.push_back(flojd);
  std::sort(vozaci.begin(), vozaci.end(),
            [](const Vozac &prvi, const Vozac &drugi) {
              return prvi.vrijeme() < drugi.vrijeme();
            });
  for (int i = 0; i < vozaci.size(); i++)
    std::cout << vozaci[i] << std::endl;
}
