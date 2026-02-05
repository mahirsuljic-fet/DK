#pragma once

#include <string>
#include <unordered_map>
#include <vector>

struct FunctionNode;

struct Environment
{
    using Value = int;
    using Symbol = std::string;
    using SymbolMap = std::unordered_map<Symbol, Value>;
    using FunctionMap = std::unordered_map<Symbol, FunctionNode*>;
    using ScopeStack = std::vector<SymbolMap>;

    Value& find(const Symbol& symbol);
    void enterScope();
    void exitScope();
    Environment();
    ~Environment();

    ScopeStack scopeStack;
    FunctionMap functions;
};
