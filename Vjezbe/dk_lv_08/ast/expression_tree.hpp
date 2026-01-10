#ifndef EXPRESSION_TREE_H
#define EXPRESSION_TREE_H

#include <iostream>
#include <string>
#include <vector>

#include "environment.hpp"

struct ExpressionNode {
  virtual ~ExpressionNode(){};
  virtual int evaluate(Environment &env) = 0;
};

struct NumberNode : public ExpressionNode {
  NumberNode(int v) : value{v} {}

  int evaluate(Environment &env) override { return value; }

  int value;
};

struct VariableNode : public ExpressionNode {
  VariableNode(std::string s) : id{std::move(s)} {}

  int evaluate(Environment &env) override { return env[id]; }

  std::string id;
};

struct PlusNode : public ExpressionNode {
  PlusNode(ExpressionNode *lhs, ExpressionNode *rhs) : left{lhs}, right{rhs} {}
  int evaluate(Environment &env) override {
    return left->evaluate(env) + right->evaluate(env);
  }

private:
  ExpressionNode *left;
  ExpressionNode *right;
};

struct MinusNode : public ExpressionNode {
  MinusNode(ExpressionNode *lhs, ExpressionNode *rhs) : left{lhs}, right{rhs} {}
  int evaluate(Environment &env) override {
    return left->evaluate(env) - right->evaluate(env);
  }

private:
  ExpressionNode *left;
  ExpressionNode *right;
};

struct MultiplyNode : public ExpressionNode {
  MultiplyNode(ExpressionNode *lhs, ExpressionNode *rhs)
      : left{lhs}, right{rhs} {}
  int evaluate(Environment &env) override {
    return left->evaluate(env) * right->evaluate(env);
  }

private:
  ExpressionNode *left;
  ExpressionNode *right;
};

struct DivisionNode : public ExpressionNode {
  DivisionNode(ExpressionNode *lhs, ExpressionNode *rhs)
      : left{lhs}, right{rhs} {}
  int evaluate(Environment &env) override {
    return left->evaluate(env) / right->evaluate(env);
  }

private:
  ExpressionNode *left;
  ExpressionNode *right;
};

struct AssignmentNode : public ExpressionNode {
  AssignmentNode(const char *id, ExpressionNode *rhs) : id{id}, right{rhs} {}

  int evaluate(Environment &env) override {
    return env[id] = right->evaluate(env);
  }

  const char *id;
  ExpressionNode *right;
};

struct IfNode : public ExpressionNode {
  IfNode(ExpressionNode *cond, ExpressionNode *body)
      : condition{cond}, body{body} {}

  int evaluate(Environment &env) override {
    if (condition->evaluate(env))
      body->evaluate(env);
    return 0;
  }

  ExpressionNode *condition;
  ExpressionNode *body;
};

struct IfElseNode : public ExpressionNode {
  IfElseNode(ExpressionNode *cond, ExpressionNode *body_true,
             ExpressionNode *body_false)
      : condition{cond}, body_true{body_true}, body_false{body_false} {}

  int evaluate(Environment &env) override {
    if (condition->evaluate(env))
      body_true->evaluate(env);
    else
      body_false->evaluate(env);

    return 0;
  }

  ExpressionNode *condition;
  ExpressionNode *body_true;
  ExpressionNode *body_false;
};

#endif // EXPRESSION_TREE_H
