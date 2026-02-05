#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <stdexcept>
#include <string>
#include <vector>

#include "environment.hpp"

struct ExpressionNode
{
    virtual ~ExpressionNode() { };
    virtual int evaluate(Environment& env) = 0;
};

struct PrintNode : public ExpressionNode
{
    PrintNode(ExpressionNode* value) : value { value } { }

    ~PrintNode() { delete value; }

    int evaluate(Environment& env) override
    {
      printf("%d\n", value->evaluate(env));
      return 0;
    }

    ExpressionNode* value = nullptr;
};

struct NumberNode : public ExpressionNode
{
    NumberNode(int v) : value { v } { }

    int evaluate(Environment& env) override { return value; }

    int value;
};

struct IDNode : public ExpressionNode
{
    IDNode(std::string* symbol) : symbol { symbol } { }

    ~IDNode() { delete symbol; }

    int evaluate(Environment& env) override { return env.find(*symbol); }

    std::string* symbol;
};

struct ExprValueNode : public ExpressionNode
{
    ExprValueNode(ExpressionNode* node) : node { node } { }

    ~ExprValueNode() { delete node; }

    int evaluate(Environment& env) override { return node->evaluate(env); }

    ExpressionNode* node;
};

struct PlusNode : public ExpressionNode
{
    PlusNode(ExpressionNode* lhs, ExpressionNode* rhs)
      : left { lhs }, right { rhs } { }

    ~PlusNode()
    {
      delete left;
      delete right;
    }

    int evaluate(Environment& env) override
    {
      return left->evaluate(env) + right->evaluate(env);
    }

  private:
    ExpressionNode* left;
    ExpressionNode* right;
};

struct MinusNode : public ExpressionNode
{
    MinusNode(ExpressionNode* lhs, ExpressionNode* rhs)
      : left { lhs }, right { rhs } { }

    ~MinusNode()
    {
      delete left;
      delete right;
    }

    int evaluate(Environment& env) override
    {
      return left->evaluate(env) - right->evaluate(env);
    }

  private:
    ExpressionNode* left;
    ExpressionNode* right;
};

struct UnaryMinusNode : public ExpressionNode
{
    UnaryMinusNode(ExpressionNode* operand)
      : operand { operand } { }

    ~UnaryMinusNode()
    {
      delete operand;
    }

    int evaluate(Environment& env) override
    {
      return -operand->evaluate(env);
    }

  private:
    ExpressionNode* operand;
};

struct TimesNode : public ExpressionNode
{
    TimesNode(ExpressionNode* lhs, ExpressionNode* rhs)
      : left { lhs }, right { rhs } { }

    ~TimesNode()
    {
      delete left;
      delete right;
    }

    int evaluate(Environment& env) override
    {
      return left->evaluate(env) * right->evaluate(env);
    }

  private:
    ExpressionNode* left;
    ExpressionNode* right;
};

struct DivideNode : public ExpressionNode
{
    DivideNode(ExpressionNode* lhs, ExpressionNode* rhs)
      : left { lhs }, right { rhs } { }

    ~DivideNode()
    {
      delete left;
      delete right;
    }

    int evaluate(Environment& env) override
    {
      return left->evaluate(env) / right->evaluate(env);
    }

  private:
    ExpressionNode* left;
    ExpressionNode* right;
};

struct EqualNode : public ExpressionNode
{
    EqualNode(ExpressionNode* lhs, ExpressionNode* rhs)
      : left { lhs }, right { rhs } { }

    ~EqualNode()
    {
      delete left;
      delete right;
    }

    int evaluate(Environment& env) override
    {
      return left->evaluate(env) == right->evaluate(env);
    }

  private:
    ExpressionNode* left;
    ExpressionNode* right;
};

struct NotEqualNode : public ExpressionNode
{
    NotEqualNode(ExpressionNode* lhs, ExpressionNode* rhs)
      : left { lhs }, right { rhs } { }

    ~NotEqualNode()
    {
      delete left;
      delete right;
    }

    int evaluate(Environment& env) override
    {
      return left->evaluate(env) != right->evaluate(env);
    }

  private:
    ExpressionNode* left;
    ExpressionNode* right;
};

struct GreaterNode : public ExpressionNode
{
    GreaterNode(ExpressionNode* lhs, ExpressionNode* rhs)
      : left { lhs }, right { rhs } { }

    ~GreaterNode()
    {
      delete left;
      delete right;
    }

    int evaluate(Environment& env) override
    {
      return left->evaluate(env) > right->evaluate(env);
    }

  private:
    ExpressionNode* left;
    ExpressionNode* right;
};

struct LessNode : public ExpressionNode
{
    LessNode(ExpressionNode* lhs, ExpressionNode* rhs)
      : left { lhs }, right { rhs } { }

    ~LessNode()
    {
      delete left;
      delete right;
    }

    int evaluate(Environment& env) override
    {
      return left->evaluate(env) < right->evaluate(env);
    }

  private:
    ExpressionNode* left;
    ExpressionNode* right;
};

struct GreaterEqualNode : public ExpressionNode
{
    GreaterEqualNode(ExpressionNode* lhs, ExpressionNode* rhs)
      : left { lhs }, right { rhs } { }

    ~GreaterEqualNode()
    {
      delete left;
      delete right;
    }

    int evaluate(Environment& env) override
    {
      return left->evaluate(env) >= right->evaluate(env);
    }

  private:
    ExpressionNode* left;
    ExpressionNode* right;
};

struct LessEqualNode : public ExpressionNode
{
    LessEqualNode(ExpressionNode* lhs, ExpressionNode* rhs)
      : left { lhs }, right { rhs } { }

    ~LessEqualNode()
    {
      delete left;
      delete right;
    }

    int evaluate(Environment& env) override
    {
      return left->evaluate(env) <= right->evaluate(env);
    }

  private:
    ExpressionNode* left;
    ExpressionNode* right;
};

struct AssignNode : public ExpressionNode
{
    AssignNode(std::string* symbol, ExpressionNode* valueNode)
      : symbol { symbol }, valueNode { valueNode } { }

    ~AssignNode()
    {
      delete symbol;
      delete valueNode;
    }

    int evaluate(Environment& env) override
    {
      return env.find(*symbol) = valueNode->evaluate(env);
    }

  private:
    std::string* symbol;
    ExpressionNode* valueNode;
};

struct IfNode : public ExpressionNode
{
    IfNode(ExpressionNode* condition, ExpressionNode* body)
      : condition { condition }, body { body } { }

    ~IfNode()
    {
      delete condition;
      delete body;
    }

    int evaluate(Environment& env) override
    {
      if (condition->evaluate(env))
        body->evaluate(env);
      return 0;
    }

  private:
    ExpressionNode* condition;
    ExpressionNode* body;
};

struct IfElseNode : public ExpressionNode
{
    IfElseNode(ExpressionNode* condition, ExpressionNode* ifBody, ExpressionNode* elseBody)
      : condition { condition }, ifBody { ifBody }, elseBody { elseBody } { }

    ~IfElseNode()
    {
      delete condition;
      delete ifBody;
      delete elseBody;
    }

    int evaluate(Environment& env) override
    {
      if (condition->evaluate(env))
        ifBody->evaluate(env);
      else
        elseBody->evaluate(env);
      return 0;
    }

  private:
    ExpressionNode* condition;
    ExpressionNode* ifBody;
    ExpressionNode* elseBody;
};

struct WhileNode : public ExpressionNode
{
    WhileNode(ExpressionNode* condition, ExpressionNode* body)
      : condition { condition }, body { body } { }

    ~WhileNode()
    {
      delete condition;
      delete body;
    }

    int evaluate(Environment& env) override
    {
      while (condition->evaluate(env))
        body->evaluate(env);
      return 0;
    }

  private:
    ExpressionNode* condition;
    ExpressionNode* body;
};

struct ScopeNode : public ExpressionNode
{
    ScopeNode(std::vector<ExpressionNode*>* statementList)
      : statementList { statementList } { }

    ~ScopeNode()
    {
      for (auto* node : *statementList)
        delete node;
      delete statementList;
    }

    int evaluate(Environment& env) override
    {
      env.enterScope();
      for (auto& statement : *statementList)
        statement->evaluate(env);
      env.exitScope();
      return 0;
    }

  private:
    std::vector<ExpressionNode*>* statementList;
};

struct ReturnNode : public ExpressionNode
{
    ReturnNode(ExpressionNode* expr)
      : expr { expr } { }

    ~ReturnNode() { delete expr; }

    int evaluate(Environment& env) override
    {
      return expr->evaluate(env);
    }

  private:
    ExpressionNode* expr;
};

struct FunctionNode : public ExpressionNode
{
    FunctionNode(std::vector<Environment::Symbol>* parameters, std::vector<ExpressionNode*>* statementList)
      : parameters { parameters }, statementList { statementList } { }

    ~FunctionNode()
    {
      for (auto* node : *statementList)
        delete node;
      delete statementList;
      delete parameters;
    }

    int evaluate(Environment& env) override
    {
      for (auto& statement : *statementList)
      {
        auto result = statement->evaluate(env);
        if (dynamic_cast<ReturnNode*>(statement))
          return result;
      }
      return 0;
    }

  private:
    std::vector<Environment::Symbol>* parameters;
    std::vector<ExpressionNode*>* statementList;

    friend struct FunctionCallNode;
};

struct FunctionDefinitionNode : public ExpressionNode
{
    FunctionDefinitionNode(Environment::Symbol* symbol, std::vector<Environment::Symbol>* parameters, std::vector<ExpressionNode*>* statementList)
      : symbol { symbol }, parameters { parameters }, statementList { statementList } { }

    ~FunctionDefinitionNode()
    {
      delete symbol;
    }

    int evaluate(Environment& env) override
    {
      env.functions[*symbol] = new FunctionNode(parameters, statementList);
      return 0;
    }

  private:
    Environment::Symbol* symbol;
    std::vector<Environment::Symbol>* parameters;
    std::vector<ExpressionNode*>* statementList;
};

struct FunctionCallNode : public ExpressionNode
{
    FunctionCallNode(Environment::Symbol* symbol, std::vector<ExpressionNode*>* arguments)
      : symbol { symbol }, arguments { arguments } { }

    ~FunctionCallNode()
    {
      for (auto* node : *arguments)
        delete node;
      delete arguments;
      delete symbol;
    }

    int evaluate(Environment& env) override
    {
      const auto& symbol = *this->symbol;
      const auto& functionIt = env.functions.find(symbol);

      if (functionIt == env.functions.end())
        throw std::runtime_error("Function " + symbol + " is not defined");

      const auto& function = functionIt->second;
      const auto& parameters = *function->parameters;
      const auto& arguments = *this->arguments;

      if (parameters.size() != arguments.size())
        throw std::runtime_error("Number of arguments does not match the number of parameters in call to " + symbol);

      env.enterScope();
      auto& functionScope = env.scopeStack.back();
      for (auto i = 0; i < parameters.size(); ++i)
      {
        const auto& parameter = parameters[i];
        const auto& argument = arguments[i]->evaluate(env);
        functionScope[parameter] = argument;
      }
      auto result = function->evaluate(env);
      env.exitScope();
      return result;
    }

  private:
    Environment::Symbol* symbol;
    std::vector<ExpressionNode*>* arguments;
};

#endif // EXPRESSION_TREE_H
