#pragma once
#include <vector>
#include <stack>
#include "token.h"

class Runtime {
    private:
        std::vector<int> m_values;
        void runCommand(const Token& token);

        void doSum();
        void doPrint() const;
        void doPrintAscii() const;
        void doSplice();

    public:
        Runtime();
        void initValues(const std::vector<int>& values);
        void run(std::vector<Token>& tokens);
};
