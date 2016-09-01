#include "runtime.h"
#include <iostream>

Runtime::Runtime() {

}

void Runtime::initValues(const std::vector<int>& values) {
    for (const int i : values) {
        m_values.push_back(i);
    }
}

void Runtime::runCommand(const Token& token) {
    if (token.getLexeme() == "S") {
        doSum();
    }
}

void Runtime::run(std::vector<Token>& tokens) {
    for (auto& token : tokens) {
        runCommand(token);
    }
}

void Runtime::printValues() const {
    for (const int value : m_values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void Runtime::doSum() {
    int sum = 0;
    for (const int i : m_values) {
        sum += i;
    }

    m_values.push_back(sum);
}
