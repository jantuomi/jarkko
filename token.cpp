#include "token.h"

Token::Token(std::string& lexeme, bool isString) :
    m_lexeme(lexeme), m_isString(isString) {

}

const std::string& Token::getLexeme() const {
    return m_lexeme;
}

bool Token::isString() const {
    return m_isString;
}
