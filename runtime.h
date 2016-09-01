#pragma once
#include <vector>
#include <stack>
#include "token.h"

class Runtime {
    private:
        std::stack<int> m_values;
        bool runCommand(const Token& token);

    public:
        Runtime();
        void run(std::vector<Token>& tokens);
};
