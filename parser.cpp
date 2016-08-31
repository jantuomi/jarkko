#include "parser.h"
#include <string>
#include <vector>

Parser::Parser(std::string& input) {
    std::vector<std::string> result;

    bool isString = false;
    std::string tmp;
    for (auto& c : input) {
        if (c == '"' && !isString) {
            isString = true;
            continue;
        }

        if (c == '"' && isString) {
            result.push_back(tmp);
            tmp = "";
            isString = false;
            continue;
        }

        if (!isString) {
            std::string parsed(1, c);
            result.push_back(parsed);
        }
        else {
            tmp += c;
        }
    }
}
