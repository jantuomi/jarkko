#include "parser.h"
#include <string>
#include <vector>
#include "token.h"

Parser::Parser(std::string& input) {
    std::vector<Token> result;

    bool isString = false;
    std::string tmp;
    for (auto& c : input) {
        if (c == '"' && !isString) {
            isString = true;
            continue;
        }

        if (c == '"' && isString) {
            Token token(tmp, true);
            result.push_back(token);
            tmp = "";
            isString = false;
            continue;
        }

        if (!isString) {
            std::string parsed(1, c);
            Token token(parsed, false);
            result.push_back(token);
        }
        else {
            tmp += c;
        }
    }
}