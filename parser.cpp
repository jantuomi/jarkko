#include "parser.h"
#include <iostream>
#include <string>
#include <vector>
#include "token.h"

Parser::Parser() { }

bool isNumber(const std::string& str) {
    for (const char& c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

std::vector<int> Parser::parseValues(const std::string& input) {
    std::vector<int> res;
    std::string tmp;
    for (const char& c : input) {
        if (!std::isspace(c)) {
            tmp += c;
        }
        else {
            if (isNumber(tmp)) {
                res.push_back(std::stoi(tmp));
            } else {
                for (const char& c : tmp) {
                    res.push_back( static_cast<int>(c) );
                }
            }

            tmp = "";
        }           
    }     
    return res;           
}

std::vector<Token> Parser::parseCode(const std::string& input) {
    std::vector<Token> result;

    bool isString = false;
    std::string tmp;
    for (auto& c : input) {
        if (std::isspace(c)) {
            continue;
        }

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

    return result;
}

void Parser::printTokens(const std::vector<Token>& tokens) {
    for (auto& token : tokens) {
        std::cout << "Token[" << token.getLexeme() << "] ";
    }
    std::cout << std::endl;
}

void Parser::printValues(const std::vector<int>& values) {
    for (auto& value : values) {
        std::cout << "Value[" << value << "] ";
    }
    std::cout << std::endl;
}
