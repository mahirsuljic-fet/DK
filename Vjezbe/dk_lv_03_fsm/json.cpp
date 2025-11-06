// Test program demonstrating FSM usage to parse an integer

#include "fsm/chars.hpp"
#include <fsm/pec.hpp>

#include <cstdint>
#include <iostream>
#include <string>

// Include FSM DSL
#include <fsm/fsm.hpp>

// Parser state
struct parser_state {
  const char *pos;
  fsm::pec code = fsm::pec::success;

  parser_state(const char *input) : pos(input) {}

  char current() const { return *pos; }

  char next() {
    if (*pos != '\0')
      ++pos;
    return *pos;
  }
};

// Parse a simple JSON format
void parse_integer(parser_state &ps, int64_t &result) {
  using pec = fsm::pec; // FSM macros expect pec in local scope

  // clang-format off
  start();
  state(init) {
    transition(init, fsm::whitespace_chars)
    transition(brace, '{')
  }
  state(brace) {
    transition(brace, fsm::whitespace_chars)
    transition(quote, '\"')
  }
  state(quote) {
    transition(word, fsm::alphanumeric_chars)
  }
  state(word) {
    transition(word, fsm::alphanumeric_chars)
    transition(after_quote, '\"')
  }
  state(after_quote) {
    transition(after_quote, fsm::whitespace_chars)
    transition(colon, ':')
  }
  state(colon) {
    transition(colon, fsm::whitespace_chars)
    transition(digit, fsm::is_digit)
  }
  state(digit) {
    transition(await_brace, fsm::whitespace_chars)
    transition(digit, fsm::is_digit)
    transition(abrace, '}')
  }
  state(await_brace) {
    transition(await_brace, fsm::whitespace_chars)
    transition(abrace, '}')
  }
  term_state(abrace) {
    transition(abrace, fsm::whitespace_chars)
  }
  fin();
  }
// clang-format on

int main() {
  std::string input;

  std::cout << "Enter a JSON expression to parse: ";
  std::getline(std::cin, input);

  parser_state ps(input.c_str());
  int64_t result = 0;

  parse_integer(ps, result);

  if (ps.code == fsm::pec::success) {
    std::cout << "Successfully parsed: " << result << std::endl;
  } else {
    std::cout << "Parse error: " << to_string(ps.code) << std::endl;
  }

  return 0;
}
