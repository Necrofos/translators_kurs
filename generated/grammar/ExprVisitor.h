
// Generated from grammar/Expr.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExprParser.
 */
class  ExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExprParser.
   */
    virtual std::any visitProg(ExprParser::ProgContext *context) = 0;

    virtual std::any visitExpr(ExprParser::ExprContext *context) = 0;

    virtual std::any visitAddExpr(ExprParser::AddExprContext *context) = 0;

    virtual std::any visitCompOp(ExprParser::CompOpContext *context) = 0;


};

