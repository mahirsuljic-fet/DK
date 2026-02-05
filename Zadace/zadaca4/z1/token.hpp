#pragma once

#include <iostream>
#include <string>

enum TokenClass
{
  CLOSEDBRACES = 1,
  COLON,
  COMMA,
  STRING,
  NUMBER,
  OPENBRACKET,
  OPENBRACES,
  CLOSEDBRACKET,
  TRUE,
  FALSE,
  NULLABLE,
  IDENTIFIER,
};

inline const char* to_str(int t)
{
  switch (t)
  {
  case CLOSEDBRACES:
    return "CLOSEDBRACES";
  case COLON:
    return "COLON";
  case COMMA:
    return "COMMA";
  case STRING:
    return "STRING";
  case NUMBER:
    return "NUMBER";
  case OPENBRACKET:
    return "OPENBRACKET";
  case OPENBRACES:
    return "OPENBRACES";
  case CLOSEDBRACKET:
    return "CLOSEDBRACKET";
  case TRUE:
    return "TRUE";
  case FALSE:
    return "FALSE";
  case NULLABLE:
    return "NULLABLE";
  case IDENTIFIER:
    return "IDENTIFIER";
  default:
    return "<unknown>";
  }
}

struct Token
{
    int tag;
    std::string lexeme;

    Token(int i = 0, std::string const& s = "") : tag(i), lexeme(s) { }
};

inline std::ostream& operator<<(std::ostream& out, const Token& tok)
{
  return out << "<" << to_str(tok.tag) << "," << tok.lexeme << ">";
}
