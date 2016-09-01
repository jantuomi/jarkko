#pragma once
#include <string>
#include "token.h"
#include <vector>

class Parser {
    public:
        Parser();

        std::vector<int> parseValues(const std::string&);
        std::vector<Token> parseCode(const std::string&);

        static void printTokens(const std::vector<Token>&);
        static void printValues(const std::vector<int>&);
};
