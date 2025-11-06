// This file is part of CAF, the C++ Actor Framework. See the file LICENSE in
// the main distribution directory for license terms and copyright or visit
// https://github.com/actor-framework/actor-framework/blob/main/LICENSE.

#pragma once

namespace fsm {

struct any_char_t {};

constexpr any_char_t any_char = any_char_t{};

constexpr bool in_whitelist(any_char_t, char) noexcept { return true; }

constexpr bool in_whitelist(char whitelist, char ch) noexcept {
  return whitelist == ch;
}

inline bool in_whitelist(const char *whitelist, char ch) noexcept {
  // Note: using strchr breaks if `ch == '\0'`.
  for (char c = *whitelist++; c != '\0'; c = *whitelist++)
    if (c == ch)
      return true;
  return false;
}

inline bool in_whitelist(bool (*filter)(char), char ch) noexcept {
  return filter(ch);
}

constexpr char whitespace_chars[7] = " \f\n\r\t\v";

constexpr char alphanumeric_chars[63] = "0123456789"
                                        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                        "abcdefghijklmnopqrstuvwxyz";

constexpr char alphabetic_chars[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                      "abcdefghijklmnopqrstuvwxyz";

constexpr char hexadecimal_chars[23] = "0123456789ABCDEFabcdef";

constexpr char decimal_chars[11] = "0123456789";

constexpr char octal_chars[9] = "01234567";

constexpr char quote_marks[3] = "\"'";

constexpr bool is_digit(char c) { return c >= '0' && c <= '9'; }

} // namespace fsm
