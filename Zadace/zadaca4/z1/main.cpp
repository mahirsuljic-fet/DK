#include <iostream>
#include <vector>

// Header file generisan u Makefile-u (potreban zbog deklaracija yylex, yytext)
#include "lex.yy.h"

#include "parser.hpp"
#include "token.hpp"

int main(void)
{
  std::vector<Token> tokens;
  int tok;
  // Ucitati sve tokene u vector
  while ((tok = yylex()))
    tokens.push_back(Token(tok, yytext));
  // Print all tokens
  std::cout << "TOKENS:" << std::endl;
  for (auto i = 0ul; i < tokens.size(); i++)
    std::cout << i << ": " << tokens[i] << std::endl;

  std::cout << "\nparsing...\n" << std::endl;

  Parser p(tokens);
  if (p.parse())
    std::cout << "Uneseni string je ispravan." << std::endl;
  else
    std::cout << "Uneseni string nije ispravan." << std::endl;

  return 0;
}
