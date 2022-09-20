#pragma once

#include <fstream>
#include <vector>
#include "token.h"

namespace lexer
{

    Token *nextToken(std::fstream *file);
    std::vector<Token *> getTokens(std::fstream *file);
    bool isFloat(std::string num);
}