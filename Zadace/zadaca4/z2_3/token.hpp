#pragma once

#include <iostream>
#include <string>

enum TokenID
{
  LEFT_PAREN = 1,
  RIGHT_PAREN,
  LEFT_BRACE,
  RIGHT_BRACE,
  COMMA,
  DOT,
  MINUS,
  PLUS,
  SEMICOLON,
  STAR,
  SLASH,
  BANG_EQUAL,
  EQUAL_EQUAL,
  LESS_EQUAL,
  GREATER_EQUAL,
  LESS,
  GREATER,
  BANG,
  EQUAL,
  STRING,
  NUMBER,
  IDENTIFIER,
  AND,
  CLASS,
  ELSE,
  FALSE,
  FOR,
  FUN,
  IF,
  NIL,
  OR,
  PRINT,
  RETURN,
  SUPER,
  THIS,
  TRUE,
  VAR,
  WHILE
};

struct Token
{
    int tag = 0;
    std::string lexeme;
};

void printerr(char c);
const char* to_str(int id);

inline std::ostream& operator<<(std::ostream& out, const Token& tok)
{
  return out << "<" << to_str(tok.tag) << "," << tok.lexeme << ">";
}
