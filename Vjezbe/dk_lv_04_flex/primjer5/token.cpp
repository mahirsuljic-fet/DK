#include "token.hpp"

const char *to_string(TokenId id) {
  static const char *imena[] = {"",
                                "STRING",
                                "NUMBER",
                                "COLON",
                                "OPEN_BRACES",
                                "CLOSED_BRACES",
                                "OPEN_BRACKET",
                                "CLOSED_BRACKET",
                                "BOOLEAN",
                                "COMMA",
                                "NULLJSON"};
  return imena[id];
}

std::ostream &operator<<(std::ostream &out, const Token &token) {
  return out << to_string(static_cast<TokenId>(token.id)) << " - \""
             << token.lexeme << "\" at " << token.row << ":" << token.column;
}
