#include "runtime.h"
#include "value.h"

Runtime::Runtime() {

}

/* Returns false if token is not a command */
bool Runtime::runCommand(const Token& token) {
    // TODO
    return false;
}

void Runtime::run(std::vector<Token>& tokens) {
    for (auto& token : tokens) {
        if (!runCommand(token)) {
            Value value(token);
        }
    }
}
