#ifndef ASTBUILDER_H
#define ASTBUILDER_H

#include "ExprBaseVisitor.h"
#include "ExprParser.h"
#include "Ast.h"
#include <any>
#include <memory>
#include <string>

class AstBuilder : public ExprBaseVisitor {
public:
    std::any visitProg(ExprParser::ProgContext *ctx) override {
        return visit(ctx->expr());
    }

    std::any visitExpr(ExprParser::ExprContext *ctx) override {
        auto left = std::any_cast<std::shared_ptr<Node>>(visit(ctx->addExpr(0)));

        if (ctx->compOp() == nullptr) {
            return std::shared_ptr<Node>(left);
        }

        std::string op = ctx->compOp()->getText();
        auto right = std::any_cast<std::shared_ptr<Node>>(visit(ctx->addExpr(1)));

        return std::shared_ptr<Node>(
            std::make_shared<CompareNode>(op, left, right)
        );
    }

    std::any visitAddExpr(ExprParser::AddExprContext *ctx) override {
        auto ints = ctx->INT();

        std::shared_ptr<Node> current =
            std::make_shared<IntNode>(std::stoi(ints[0]->getText()));

        for (size_t i = 1; i < ints.size(); ++i) {
            auto next = std::make_shared<IntNode>(std::stoi(ints[i]->getText()));
            current = std::make_shared<AddNode>(current, next);
        }

        return std::shared_ptr<Node>(current);
    }
};

#endif