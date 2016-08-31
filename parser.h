#pragma once
#include <string>
#include "token.h"
#include <vector>

class Parser {
    private:
        std::vector<Token> m_tokens;
    public:
        Parser(std::string&);
        std::vector<Token>& getTokens();
        void printTokens();
};
