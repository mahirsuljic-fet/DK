#include <iostream>
#include <vector>

#include "lex.yy.h"

#include "parser.hpp"
#include "token.hpp"

int main(void)
{
  std::vector<Token> tokens;
  int tok;

  while ((tok = yylex()))
    tokens.push_back(Token { tok, yytext });

  std::cout << "TOKENS:" << std::endl;
  for (auto i = 0ul; i < tokens.size(); i++)
    std::cout << i << ": " << tokens[i] << std::endl;

  std::cout << "\nparsing...\n"
            << std::endl;

  Parser p(tokens);
  if (p.Parse())
    std::cout << "Uneseni string je ispravan." << std::endl;
  else
    std::cout << "Uneseni string nije ispravan." << std::endl;

  return 0;
}
