#include "parser.h"
#include <string>
#include <vector>

Parser::Parser(std::string& input) {
    std::vector<std::string> result;

    for (auto& c : input) {
        std::string parsed(1, c);
        result.push_back(parsed);
    }
}
