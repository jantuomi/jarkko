#pragma once
#include "value.h"
#include <vector>
#include "token.h"

class Runtime {
    private:
        std::vector<Value> m_values;
        bool runCommand(const Token& token);

    public:
        Runtime();
        void run(std::vector<Token>& tokens);
};
