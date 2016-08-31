#include "token.h"

Token::Token(std::string& lexeme, bool isString) :
    m_lexeme(lexeme), m_isString(isString) {

}

