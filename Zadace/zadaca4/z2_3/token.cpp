#include "token.hpp"

const char* to_str(int id)
{
  static const char* names[] = {
    "",
    "LEFT_PAREN",
    "RIGHT_PAREN",
    "LEFT_BRACE",
    "RIGHT_BRACE",
    "COMMA",
    "DOT",
    "MINUS",
    "PLUS",
    "SEMICOLON",
    "STAR",
    "SLASH",
    "BANG_EQUAL",
    "EQUAL_EQUAL",
    "LESS_EQUAL",
    "GREATER_EQUAL",
    "LESS",
    "GREATER",
    "BANG",
    "EQUAL",
    "STRING",
    "NUMBER",
    "IDENTIFIER",
    "AND",
    "CLASS",
    "ELSE",
    "FALSE",
    "FOR",
    "FUN",
    "IF",
    "NIL",
    "OR",
    "PRINT",
    "RETURN",
    "SUPER",
    "THIS",
    "TRUE",
    "VAR",
    "WHILE"
  };
  return names[id];
}

void printerr(char c)
{
  std::cout << "error: " << c << "\n";
}
