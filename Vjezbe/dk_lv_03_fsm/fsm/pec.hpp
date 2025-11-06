#pragma once

#include <cstdint>

namespace fsm {

// Minimal pec (Parser Error Code) enum
enum class pec : uint8_t {
  success = 0,
  trailing_character = 1,
  unexpected_eof,
  unexpected_character,
  unexpected_newline,
  integer_overflow,
  integer_underflow,
};

inline const char *to_string(fsm::pec code) {
  switch (code) {
  case fsm::pec::success:
    return "success";
  case fsm::pec::trailing_character:
    return "trailing_character";
  case fsm::pec::unexpected_eof:
    return "unexpected_eof";
  case fsm::pec::unexpected_character:
    return "unexpected_character";
  case fsm::pec::unexpected_newline:
    return "unexpected_newline";
  case fsm::pec::integer_overflow:
    return "integer_overflow";
  case fsm::pec::integer_underflow:
    return "integer_underflow";
  default:
    return "unknown";
  }
}

} // namespace fsm
