#pragma once

#include <iostream>
#include <string>

enum TokenId {
  STRING = 1,
  NUMBER,
  COLON,
  OPEN_BRACES,
  CLOSED_BRACES,
  OPEN_BRACKET,
  CLOSED_BRACKET,
  BOOLEAN,
  COMMA,
  NULLJSON
};

const char *to_string(TokenId id);

struct Token {
  int id = 0;
  std::string lexeme;
  short unsigned int row = 0;
  short unsigned int column = 0;
};

std::ostream &operator<<(std::ostream &out, const Token &token);
