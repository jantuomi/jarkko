#include "value.h"
#include <string>

Value::Value(std::string& lexeme) {
    if (lexeme.find_first_not_of("0123456789")) {
        m_type = Value::Type::Integer;
        m_intData = std::stoi(lexeme, nullptr, 10);
    }
    else {
        m_type = Value::Type::String;
        m_strData = lexeme;
    }
}


const Value::Type Value::getType() const {
    return m_type;
}

const int Value::getIntData() const {
    return m_intData;
}

const std::string& Value::getStrData() const {
    return m_strData;
}
