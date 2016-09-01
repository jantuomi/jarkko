#include "runtime.h"

Runtime::Runtime() {

}

void Runtime::initValues(const std::vector<int>& values) {
    for (const int i : values) {
        m_values.push(i);
    }
}

/* Returns false if token is not a command */
bool Runtime::runCommand(const Token& token) {
    // TODO
    return false;
}

void Runtime::run(std::vector<Token>& tokens) {
    for (auto& token : tokens) {
        if (!runCommand(token)) {

        }
    }
}
