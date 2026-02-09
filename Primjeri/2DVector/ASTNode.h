#pragma once

#include "environment.h"
#include "vector.h"
#include <functional>
#include <iostream>
#include <stdexcept>

struct ASTNode
{
    virtual ASTNodeValue eval(Environment&) = 0;
    virtual void print(Environment&) { std::cout << "> "; }
    virtual ~ASTNode() { }
};

class EmptyNode : public ASTNode
{
  public:
    ASTNodeValue eval(Environment& env) override { return {}; }
    void print(Environment& env) override { }
};

class NumberNode : public ASTNode
{
  public:
    NumberNode(double value) : value_(value) { }

    ASTNodeValue eval(Environment& env) override
    {
      return value_;
    }

    void print(Environment& env) override
    {
      ASTNode::print(env);
      std::cout << eval(env).num << std::endl;
    }

  private:
    double value_;
};

class IDNode : public ASTNode
{
  public:
    IDNode(std::string* id) : id_(id) { }

    ASTNodeValue eval(Environment& env) override
    {
      return env.getValue(*id_);
    }

    void print(Environment& env) override
    {
      ASTNode::print(env);
      std::cout << eval(env).vec << std::endl;
    }

    ~IDNode() { delete id_; }

  private:
    std::string* id_;
};

class VectorNode : public ASTNode
{
  public:
    VectorNode(ASTNode* x_node, ASTNode* y_node)
      : x_node_(x_node), y_node_(y_node) { }

    ASTNodeValue eval(Environment& env) override
    {
      return Vector2D { x_node_->eval(env).num, y_node_->eval(env).num };
    }

    void print(Environment& env) override
    {
      ASTNode::print(env);
      std::cout << eval(env).vec << std::endl;
    }

    ~VectorNode()
    {
      delete x_node_;
      delete y_node_;
    }

  private:
    ASTNode* x_node_;
    ASTNode* y_node_;
};

inline VectorNode* operateNodes(Environment& env, VectorNode* lhs, VectorNode* rhs, const std::function<Vector2D(Vector2D, Vector2D)>& op)
{
  auto result = op(lhs->eval(env).vec, rhs->eval(env).vec);
  auto* nodeX = new NumberNode(result.x);
  auto* nodeY = new NumberNode(result.y);
  delete lhs;
  delete rhs;
  return new VectorNode(nodeX, nodeY);
}

inline NumberNode* operateNodes(Environment& env, NumberNode* lhs, NumberNode* rhs, const std::function<double(double, double)>& op)
{
  auto result = op(lhs->eval(env).num, rhs->eval(env).num);
  delete lhs;
  delete rhs;
  return new NumberNode(result);
}

inline ASTNode* addNodes(Environment& env, ASTNode* lhs, ASTNode* rhs)
{
  auto* vlhs = dynamic_cast<VectorNode*>(lhs);
  auto* vrhs = dynamic_cast<VectorNode*>(rhs);
  if (vlhs && vrhs)
    return operateNodes(env, vlhs, vrhs, [](Vector2D vlhs, Vector2D vrhs) { return vlhs + vrhs; });

  auto* nlhs = dynamic_cast<NumberNode*>(lhs);
  auto* nrhs = dynamic_cast<NumberNode*>(rhs);
  if (nlhs && nrhs)
    return operateNodes(env, nlhs, nrhs, [](double nlhs, double nrhs) { return nlhs + nrhs; });

  throw std::runtime_error("Syntax error: addition is not defined for given types");
}

inline ASTNode* subtractNodes(Environment& env, ASTNode* lhs, ASTNode* rhs)
{
  auto* vlhs = dynamic_cast<VectorNode*>(lhs);
  auto* vrhs = dynamic_cast<VectorNode*>(rhs);
  if (vlhs && vrhs)
    return operateNodes(env, vlhs, vrhs, [](Vector2D vlhs, Vector2D vrhs) { return vlhs - vrhs; });

  auto* nlhs = dynamic_cast<NumberNode*>(lhs);
  auto* nrhs = dynamic_cast<NumberNode*>(rhs);
  if (nlhs && nrhs)
    return operateNodes(env, nlhs, nrhs, [](double nlhs, double nrhs) { return nlhs - nrhs; });

  throw std::runtime_error("Syntax error: subtraction is not defined for given types");
}
