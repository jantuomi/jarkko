#include "value.h"
#include <string>

Value::Value(Token& token) {
    if (!token.isString())
        m_type = Value::Type::Integer;
        m_intData = std::stoi(token.getLexeme(), nullptr, 10);
    } else {
        m_type = Value::Type::String;
        m_strData = token.getLexeme();
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
