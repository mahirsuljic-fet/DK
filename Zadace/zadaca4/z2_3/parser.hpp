#pragma once

#include "token.hpp"
#include <vector>

class Parser
{
  public:
    Parser(std::vector<Token>);

    bool Parse();

  private:
    std::vector<Token> tokens;
    size_t currentIndex;
    size_t bufferLength;

    bool Start();
    bool Epsilon();
    bool Terminal(int t);
    bool StatementTail();
    bool Statement();
    bool Scope();
    bool FuncParams();
    bool FuncParamTail();
    bool Expr();
    bool RelationalExpr();
    bool RelationalTail();
    bool AdditiveExpr();
    bool AdditiveTail();
    bool MultiplicativeExpr();
    bool MultiplicativeTail();
    bool BaseExpr();
};

#define RULE(NAME, EXPR)                            \
  bool Parser::NAME()                               \
  {                                                 \
    auto backtrackIndex = currentIndex;             \
    std::cout << currentIndex << " " #NAME << endl; \
    return EXPR;                                    \
  }

#define BACKTRACK(EXPR) (currentIndex = backtrackIndex, EXPR)
