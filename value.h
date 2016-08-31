#pragma once
#include <string>

class Value {
    public:
        enum Type {
            Integer,
            String
        };

        Value(std::string& lexeme);
        const Value::Type getType() const;
        const int getIntData() const;
        const std::string& getStrData() const;

    private:
        int m_intData;
        std::string m_strData;

        Value::Type m_type;
};
