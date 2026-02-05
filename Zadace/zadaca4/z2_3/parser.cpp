#include "parser.hpp"

#include <iostream>
#include <vector>

#include "token.hpp"

using namespace std;

Parser::Parser(std::vector<Token> t)
  : tokens { std::move(t) }, currentIndex { 0ul }, bufferLength { tokens.size() } { }

bool Parser::Parse()
{
  currentIndex = 0;
  return Start() && currentIndex == bufferLength;
}

bool Parser::Terminal(int t)
{
  cout << currentIndex << " terminal: " << to_str(t) << endl;
  if (currentIndex >= bufferLength)
    return false;
  if (t == tokens[currentIndex].tag)
  {
    currentIndex++;
    return true;
  }
  return false;
}

RULE(Epsilon, true)

RULE(Start, StatementTail())

RULE(StatementTail,
  Statement() && StatementTail()
    || BACKTRACK(Epsilon()))

RULE(Statement,
  Terminal(FUN) && Terminal(IDENTIFIER) && Terminal(LEFT_PAREN) && FuncParams() && Terminal(RIGHT_PAREN) && Scope()
    || BACKTRACK(Terminal(IF) && Terminal(LEFT_PAREN) && Expr() && Terminal(RIGHT_PAREN) && Scope())
    || BACKTRACK(Terminal(VAR) && Terminal(IDENTIFIER) && Terminal(EQUAL) && Expr() && Terminal(SEMICOLON))
    || BACKTRACK(Terminal(VAR) && Terminal(IDENTIFIER) && Terminal(SEMICOLON))
    || BACKTRACK(Terminal(IDENTIFIER) && Terminal(EQUAL) && Expr() && Terminal(SEMICOLON))
    || BACKTRACK(Expr()) && Terminal(SEMICOLON))

RULE(Scope,
  Terminal(LEFT_BRACE) && StatementTail() && Terminal(RIGHT_BRACE))

RULE(FuncParams,
  Terminal(IDENTIFIER) && FuncParamTail()
    || BACKTRACK(Epsilon()))

RULE(FuncParamTail,
  Terminal(COMMA) && Terminal(IDENTIFIER) && FuncParamTail()
    || BACKTRACK(Epsilon()))

RULE(Expr,
  Terminal(IDENTIFIER) && Terminal(EQUAL) && Expr()
    || BACKTRACK(RelationalExpr()))

RULE(RelationalExpr,
  AdditiveExpr() && RelationalTail())

RULE(RelationalTail,
  Terminal(EQUAL_EQUAL) && AdditiveExpr() && RelationalTail()
    || BACKTRACK(Terminal(BANG_EQUAL) && AdditiveExpr() && RelationalTail())
    || BACKTRACK(Terminal(GREATER) && AdditiveExpr() && RelationalTail())
    || BACKTRACK(Terminal(LESS) && AdditiveExpr() && RelationalTail())
    || BACKTRACK(Epsilon()))

RULE(AdditiveExpr,
  MultiplicativeExpr() && AdditiveTail())

RULE(AdditiveTail,
  Terminal(PLUS) && MultiplicativeExpr() && AdditiveTail()
    || BACKTRACK(Terminal(MINUS) && MultiplicativeExpr() && AdditiveTail())
    || BACKTRACK(Epsilon()))

RULE(MultiplicativeExpr,
  BaseExpr() && MultiplicativeTail())

RULE(MultiplicativeTail,
  Terminal(STAR) && BaseExpr() && MultiplicativeTail()
    || BACKTRACK(Terminal(SLASH) && BaseExpr() && MultiplicativeTail())
    || BACKTRACK(Epsilon()))

RULE(BaseExpr,
  Terminal(LEFT_PAREN) && Expr() && Terminal(RIGHT_PAREN)
    || BACKTRACK(Terminal(NUMBER))
    || BACKTRACK(Terminal(IDENTIFIER)))
