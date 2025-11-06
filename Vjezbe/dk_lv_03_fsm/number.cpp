// Test program demonstrating FSM usage to parse an integer

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

bool add_digit(int64_t& result, char ch) {
  result = result * 10 + ch - '0';
  return true;
}

// Parse a signed integer
void parse_integer(parser_state &ps, int64_t &result) {
  using pec = fsm::pec; // FSM macros expect pec in local scope

  // clang-format off
  start();
  state(init) {
    transition(has_number, fsm::is_digit, add_digit(result, ch), pec::integer_overflow)
    transition(has_plus,  "+")
    transition(has_minus, "-")
  }
  state(has_plus) {
    transition(has_number, fsm::is_digit, add_digit(result, ch), pec::integer_overflow)
  }
  state(has_minus) {
    transition(has_number, fsm::is_digit, add_digit(result, ch), pec::integer_overflow)
  }
  term_state(has_number) {
    transition(has_number, fsm::is_digit, add_digit(result, ch), pec::integer_overflow)
  }
  fin();
  }
// clang-format on

int main() {
  std::string input;

  std::cout << "Enter an integer to parse: ";
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
