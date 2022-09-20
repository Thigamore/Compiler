#include "parser.h"
#include "ast.h"
#include "../lexer/token.h"
#include <iostream>
#include <vector>

Parser::Parser(std::vector<lexer::Token *> toks)
{
    this->toks = toks;
    this->ast = new AST();
}

AST *Parser::parseProgram()
{

    return this->ast;
}