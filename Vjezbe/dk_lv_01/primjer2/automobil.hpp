#pragma once

#include <string>

class Automobil {
  public:
    Automobil() = default;
    Automobil(const std::string model, const std::string &boja,
              int godinaProizvodnje)
        : model_{model}, boja_{boja}, godinaProizvodnje_{godinaProizvodnje} {}

    const std::string &model() const { return model_; }
    void model(const std::string &model) { model_ = model; }

    const std::string &boja() const { return boja_; }
    void boja(const std::string &boja) { boja_ = boja; }

    int godinaProizvodnje() const { return godinaProizvodnje_; }
    void godinaProizvodnje(int godinaProizvodnje) {
      godinaProizvodnje_ = godinaProizvodnje;
    }

  private:
    std::string model_;
    std::string boja_;
    int godinaProizvodnje_ = 2000;
};

std::ostream &operator<<(std::ostream &out, const Automobil &automobil);
