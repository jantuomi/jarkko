#pragma once
#include <string>

class Token {
    private:
        std::string m_lexeme;
        bool m_isString;

    public:
        Token(std::string& lexeme, bool isString);
};
