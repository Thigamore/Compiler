#pragma once
#include "ast.h"
#include "../lexer/token.h"
#include <vector>

class Parser
{
public:
    Parser(std::vector<lexer::Token *> toks);
    AST *parseProgram();

private:
    AST *ast;
    std::vector<lexer::Token *> toks;
};