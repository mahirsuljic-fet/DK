#include "environment.hpp"
#include "expression_tree.hpp"

#include <stdexcept>

Environment::Value& Environment::find(const Symbol& symbol)
{
  for (auto it = scopeStack.rbegin(); it != scopeStack.rend(); ++it)
  {
    SymbolMap& currentScope = *it;
    if (currentScope.find(symbol) != currentScope.end())
      return currentScope[symbol];
  }

  SymbolMap& globalScope = scopeStack.front();
  return globalScope[symbol];
}

void Environment::enterScope()
{
  scopeStack.push_back({});
}

void Environment::exitScope()
{
  if (!scopeStack.empty())
    scopeStack.pop_back();
  else
    throw std::runtime_error("Global scope can not be exited");
}

Environment::Environment() : scopeStack() { scopeStack.push_back({}); } // add global scope

Environment::~Environment()
{
  for (auto pair : functions)
    delete pair.second;
}
