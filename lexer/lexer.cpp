#include "lexer.h"
#include "token.h"
#include <string>
#include <fstream>
#include <iostream>
#include <map>

namespace lexer
{

    // gets the next token
    Token *nextToken(std::fstream *file)
    {
        char lastChar = file->get();
        std::string identifierStr;
        std::string numStr;
        double numVal;

        // checks if the char is a space
        if (isspace(lastChar))
        {
            do
            {
                lastChar = file->get();
            } while (isspace(lastChar));
            file->putback(lastChar);
            return nextToken(file);
        }
        // checks if it is a comment
        if (lastChar == '/')
        {
            lastChar = file->get();
            if (lastChar == '/')
            {
                while (lastChar != '\n')
                {
                    lastChar = file->get();
                }
                return nextToken(file);
            }
        }
        // checks if it is an identifier/keyword
        if (isalpha(lastChar))
        {
            identifierStr = "";
            do
            {
                identifierStr += lastChar;
                lastChar = file->get();
            } while (isalnum(lastChar));
            file->putback(lastChar);
            // checks if keyword
            if (keywordMap.find(identifierStr) != keywordMap.end())
            {
                return new Token(keywordMap[identifierStr], identifierStr);
            }
            else
            {
                return new Token(tok_ident, identifierStr);
            }
        }
        // checks if it is a number
        if (isdigit(lastChar))
        {
            numStr = "";
            do
            {
                numStr += lastChar;
                lastChar = file->get();
            } while (isdigit(lastChar) || lastChar == '.');
            if (isFloat(numStr))
            {
                return new Token(tok_f32, numStr);
            }
            else
            {
                return new Token(tok_i32, numStr);
            }
        }
        // checks if it is a string
        if (lastChar == '"')
        {
            std::string str = "";
            lastChar = file->get();
            while (lastChar != '"')
            {
                str += lastChar;
                lastChar = file->get();
            }
            return new Token(tok_string, str);
        }
        if (opMap.find(lastChar) != opMap.end())
        {
            TokenType op = opMap[lastChar];
            switch (op)
            {
            case '=':
                lastChar = file->get();
                if (lastChar == '=')
                {
                    return new Token(tok_eq, "==");
                }
                else
                {
                    file->putback(lastChar);
                    return new Token(tok_assign, "=");
                }
            case '!':
                lastChar = file->get();
                if (lastChar == '=')
                {
                    return new Token(tok_notEq, "!=");
                }
                else
                {
                    file->putback(lastChar);
                    return new Token(tok_bang, "!");
                }
            case '<':
                lastChar = file->get();
                if (lastChar == '=')
                {
                    return new Token(tok_lessEq, "<=");
                }
                else
                {
                    file->putback(lastChar);
                    return new Token(tok_less, "<");
                }
            case '>':
                lastChar = file->get();
                if (lastChar == '=')
                {
                    return new Token(tok_greaterEq, ">=");
                }
                else
                {
                    file->putback(lastChar);
                    return new Token(tok_greater, ">");
                }
            default:
                return new Token(op, std::string(1, lastChar));
            }
        }
        // EOF
        if (lastChar == EOF)
        {
            return new Token(tok_eof, "eof");
        }
        return new Token(tok_illegal, "");
    }

    std::vector<Token *> getTokens(std::fstream *file)
    {
        std::vector<Token *> tokens;
        Token *token;
        do
        {
            token = nextToken(file);
            tokens.push_back(token);
        } while (token->getType() != tok_eof);
        return tokens;
    }

    bool isFloat(std::string num)
    {
        for (char ch : num)
        {
            if (ch == '.')
            {
                return true;
            }
        }
        return false;
    }

}