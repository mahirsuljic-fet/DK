#pragma once

#include "token.hpp"
#include <string>
#include <vector>

class Parser {
public:
  // Ctor
  Parser(std::vector<Token>);

  // Glavna funkcija
  bool parse();

private:
  std::vector<Token> tokens;
  size_t currentIndex;
  size_t bufferLength;

  // Pomocne funkcije za parse.
  bool Start();
  bool epsilon();
  bool terminal(int t);
  bool pairs();
  bool pair();
  bool pairs_tail();
  bool value();
};
