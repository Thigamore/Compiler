#include "token.h"
#include <string>

namespace lexer
{
    Token::Token(TokenType type, std::string literal)
    {
        this->type = type;
        this->literal = literal;
    }
    TokenType Token::getType()
    {
        return this->type;
    }
    std::string Token::getLiteral()
    {
        return this->literal;
    }
}
