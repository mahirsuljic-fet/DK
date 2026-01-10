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

// first production rule
bool Parser::Start() {
  cout << currentIndex << " start" << endl;
  return false;
}

bool Parser::terminal(int t) {
  cout << currentIndex << " terminal: " << to_str(t) << endl;
  if (currentIndex >= bufferLength)
    return false;
  if (t == tokens[currentIndex].tag) {
    currentIndex++;
    return true;
  }
  return false;
}

bool Parser::pairs() {
  cout << currentIndex << " pairs" << endl;
  return false;
}

bool Parser::pairs_tail() {
  cout << currentIndex << " pairs tail" << endl;
  auto backtrackIndex = currentIndex;
  return false;
}

bool Parser::pair() {
  cout << currentIndex << " pair" << endl;
  return false;
}

bool Parser::epsilon() {
  cout << currentIndex << " epsilon" << endl;
  return true;
}

bool Parser::value() {
  cout << currentIndex << " value" << endl;
  return false;
}
