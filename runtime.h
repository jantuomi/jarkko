#pragma once
#include "value.h"
#include <vector>

class Runtime {
    private:
        std::vector<Value> m_values;
    public:
        Runtime();
        void run(std::vector<Token>& tokens);
};
