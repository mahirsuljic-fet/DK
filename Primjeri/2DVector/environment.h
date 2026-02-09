#pragma once

#include <string>
#include <unordered_map>

#include "vector.h"

union ASTNodeValue
{
    Vector2D vec;
    double num;

    ASTNodeValue() = default;
    ASTNodeValue(double num) : num(num) { }
    ASTNodeValue(Vector2D vec) : vec(vec) { }
};

class Environment
{
  public:
    ASTNodeValue getValue(const std::string& id) { return symbol_table_[id]; }
    ASTNodeValue setValue(const std::string& id, ASTNodeValue value) { return symbol_table_[id] = value; }

  private:
    std::unordered_map<std::string, ASTNodeValue> symbol_table_;
};
