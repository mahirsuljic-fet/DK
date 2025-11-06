#pragma once

#include "automobil.hpp"
#include <string>

class Vozac {
  public:
    Vozac() = default;
    Vozac(const std::string &ime, const std::string &prezime, int godine,
          const Automobil &automobil, int godineStaza, double vrijeme)
        : ime_{ime}, prezime_{prezime}, godine_{godine}, automobil_{automobil},
          godineStaza_{godineStaza}, vrijeme_{vrijeme} {}

    const std::string &ime() const { return ime_; }
    void ime(const std::string &ime) { ime_ = ime; }

    const std::string &prezime() const { return prezime_; }
    void prezime(const std::string &prezime) { prezime_ = prezime; }

    int godine() const { return godine_; }
    void godine(int godina) { godine_ = godina; }

    const Automobil &automobil() const { return automobil_; }
    void automobil(const Automobil &automobil) { automobil_ = automobil; }

    double vrijeme() const { return vrijeme_; }
    void vrijeme(double vrijeme) { vrijeme_ = vrijeme; }

    int godineStaza() const { return godineStaza_; }
    void godineStaza(int godineStaza) { godineStaza_ = godineStaza; }

  private:
    std::string ime_;
    std::string prezime_;
    int godine_;
    Automobil automobil_;
    int godineStaza_;
    double vrijeme_;
};

std::ostream &operator<<(std::ostream &out, const Vozac &vozac);
