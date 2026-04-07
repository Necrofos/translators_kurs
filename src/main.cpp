#include <iostream>
#include <memory>
#include <string>

#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"
#include "AstBuilder.h"
#include "Ast.h"

using namespace antlr4;

int main() {
    std::string input = "2+3 > 4";

    ANTLRInputStream inputStream(input);
    ExprLexer lexer(&inputStream);
    CommonTokenStream tokens(&lexer);
    ExprParser parser(&tokens);

    tree::ParseTree *tree = parser.prog();

    AstBuilder builder;
    auto ast = std::any_cast<std::shared_ptr<Node>>(builder.visit(tree));

    std::cout << "Input: " << input << std::endl;
    std::cout << "AST: " << ast->toString() << std::endl;
    std::cout << "Result: " << ast->eval() << std::endl;

    return 0;
}