#pragma once

#include <iostream>
#include <string>

enum TokenClass {
  NUMBER = 1,
  STRING,
  OPENPAREN,
  CLOSEDPAREN,
  PLUS,
  MINUS,
  TIMES,
  DIVISION,
};

struct Token {
  int tag;
  std::string lexeme;

  Token(int t = 0, std::string const &s = "") : tag(t), lexeme(s) {}
};

inline std::ostream &operator<<(std::ostream &out, const Token &tok) {
  return out << "<" << tok.tag << "," << tok.lexeme << ">";
}
