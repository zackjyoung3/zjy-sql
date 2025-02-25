#pragma once
#include <vector>
#include <string>

namespace zjy_sql::tokenization {

    enum class TokenType {
        KEYWORD,
        IDENTIFIER,
        NUMBER,
        STRING_LITERAL,
        OPERATOR,
        SYMBOL,
        UNKNOWN
    };

    struct Token {
        TokenType type;
        std::string value;
    };

    std::vector<Token> tokenizeSQL(const std::string& query);

}  // namespace zjy_sql::parsing
