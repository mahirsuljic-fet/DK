#include "parser.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "token.hpp"

//  Gramatika iz fajla rules.txt

using namespace std;

Parser::Parser(std::vector<Token> t)
  : tokens { std::move(t) }, currentIndex { 0ul }, bufferLength { tokens.size() } { }

// start of parsing
bool Parser::parse()
{
  currentIndex = 0;
  return Start() && currentIndex == bufferLength;
}

// first production rule
bool Parser::Start()
{
  cout << currentIndex << " start" << endl;
  auto backtrackIndex = currentIndex;
  return terminal(OPENBRACES) && pairs() && terminal(CLOSEDBRACES) || (currentIndex = backtrackIndex, list());
}

bool Parser::terminal(int t)
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

bool Parser::pairs()
{
  cout << currentIndex << " pairs" << endl;
  return pair() && pairs_tail();
}

bool Parser::pairs_tail()
{
  cout << currentIndex << " pairs tail" << endl;
  auto backtrackIndex = currentIndex;
  return (terminal(COMMA) && pair() && pairs_tail()) || (currentIndex = backtrackIndex, epsilon());
}

bool Parser::pair()
{
  cout << currentIndex << " pair" << endl;
  return (terminal(STRING) || terminal(IDENTIFIER)) && terminal(COLON) && value();
}

bool Parser::list()
{
  cout << currentIndex << " pairs" << endl;
  return terminal(OPENBRACKET) && list_value() && list_tail() && terminal(CLOSEDBRACKET);
}

bool Parser::list_value()
{
  cout << currentIndex << " pairs" << endl;
  auto backtrackIndex = currentIndex;
  return value() || (currentIndex = backtrackIndex, epsilon());
}

bool Parser::list_tail()
{
  cout << currentIndex << " pairs" << endl;
  auto backtrackIndex = currentIndex;
  return terminal(COMMA) && list_value() && list_tail() || (currentIndex = backtrackIndex, epsilon());
}

bool Parser::epsilon()
{
  cout << currentIndex << " epsilon" << endl;
  return true;
}

bool Parser::value()
{
  cout << currentIndex << " value" << endl;
  return terminal(STRING) || terminal(NUMBER) || terminal(TRUE) || terminal(FALSE) || terminal(NULLABLE) || list() || Start();
}
