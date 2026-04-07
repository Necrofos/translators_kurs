#ifndef AST_H
#define AST_H

#include <string>
#include <memory>
#include <stdexcept>

class Node {
public:
    virtual ~Node() = default;
    virtual std::string toString() const = 0;
    virtual int eval() const = 0;
};

class IntNode : public Node {
public:
    int value;

    explicit IntNode(int v) : value(v) {}

    std::string toString() const override {
        return std::to_string(value);
    }

    int eval() const override {
        return value;
    }
};

class AddNode : public Node {
public:
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    AddNode(std::shared_ptr<Node> l, std::shared_ptr<Node> r)
        : left(std::move(l)), right(std::move(r)) {}

    std::string toString() const override {
        return "(" + left->toString() + " + " + right->toString() + ")";
    }

    int eval() const override {
        return left->eval() + right->eval();
    }
};

class CompareNode : public Node {
public:
    std::string op;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    CompareNode(const std::string& oper,
                std::shared_ptr<Node> l,
                std::shared_ptr<Node> r)
        : op(oper), left(std::move(l)), right(std::move(r)) {}

    std::string toString() const override {
        return "(" + left->toString() + " " + op + " " + right->toString() + ")";
    }

    int eval() const override {
        int l = left->eval();
        int r = right->eval();

        if (op == "<")  return l < r ? 1 : 0;
        if (op == ">")  return l > r ? 1 : 0;
        if (op == "=")  return l == r ? 1 : 0;
        if (op == "!=") return l != r ? 1 : 0;

        throw std::runtime_error("Unknown operator: " + op);
    }
};

#endif