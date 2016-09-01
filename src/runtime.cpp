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
    const std::string lexeme = token.getLexeme();
    if (lexeme == "S") {
        doSum();
    }
    else if (lexeme == "o") {
        doPrint();
    }
    else if (lexeme == "O") {
        doPrintAscii();
    }
}

void Runtime::run(std::vector<Token>& tokens) {
    for (auto& token : tokens) {
        runCommand(token);
    }
}

void Runtime::doPrint() const {
    for (const int value : m_values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

void Runtime::doPrintAscii() const {
    for (const int value : m_values) {
        std::cout << static_cast<char>(value);
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
