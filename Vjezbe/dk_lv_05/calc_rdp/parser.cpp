#include "parser.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "token.hpp"

//  Gramatika iz fajla rules.txt

using namespace std;

Parser::Parser(std::vector<Token> t)
    : tokens{std::move(t)}, currentIndex{0ul}, bufferLength{tokens.size()} {}

// start of parsing
bool Parser::parse() {
  currentIndex = 0;
  return Start();
}

bool Parser::epsilon() {
  cout << currentIndex << " epsilon" << endl;
  return true;
}

bool Parser::terminal(int t) {
  cout << currentIndex << " terminal" << endl;
  if (currentIndex >= bufferLength)
    return false;
  if (t == tokens[currentIndex].tag) {
    currentIndex++;
    return true;
  }
  return false;
}

// first production rule
bool Parser::Start() {
  cout << currentIndex << " start" << endl;
  return false;
}

bool Parser::Start_tail() {
  cout << currentIndex << " start tail" << endl;
  return false;
}

bool Parser::term() {
  cout << currentIndex << " term" << endl;
  return false;
}

bool Parser::term_tail() {
  cout << currentIndex << " term tail" << endl;
  return false;
}

bool Parser::factor() {
  cout << currentIndex << " factor" << endl;
  auto backtrackIndex = currentIndex;
  return false;
}
