#include "zjy_sql/parsing/tokenization.h"

#include <regex>
#include <unordered_set>

namespace zjy_sql::tokenization {
    constexpr unsigned int HEURISTIC_ESTIMATE_CHARS_PER_TOKEN = 6;
    const std::unordered_set<std::string> sql_keywords = {
        "SELECT", "FROM", "WHERE", "INSERT", "INTO", "VALUES",
        "UPDATE", "DELETE", "CREATE", "TABLE", "DROP", "ALTER"
    };

    bool isKeyword(const std::string_view word) {
        std::string upperWord(word);
        std::ranges::transform(upperWord, upperWord.begin(), ::toupper);
        return sql_keywords.contains(upperWord);
    }

    Token deriveTokenFromUnquotedString(const std::string_view unquotedString) {
        if (isKeyword(unquotedString))
            return Token(TokenType::KEYWORD, std::string(unquotedString));
        return Token(TokenType::IDENTIFIER, std::string(unquotedString));
    }

    std::vector<Token> tokenizeSQL(const std::string& query) {
        std::vector<Token> tokens;
        tokens.reserve(std::max(16UL, query.size() / HEURISTIC_ESTIMATE_CHARS_PER_TOKEN));

        std::regex regex(
            R"(\s+|(--.*?$)|(/\*[\s\S]*?\*/)|([A-Za-z_][A-Za-z0-9_]*)|(\d*\.\d+|\d+)|('[^']*(?:''[^']*)*')|(\<=|\>=|!=|<>|\|\||::|[=;,+\-*/%<>()[\]{}]))",
            std::regex::optimize | std::regex::multiline
        );

        std::sregex_iterator iter(query.begin(), query.end(), regex);
        std::sregex_iterator end;

        while (iter != end) {
            std::smatch match = *iter;
            if (match[1].matched || match[2].matched) {
                // Ignore comments
            } else if (match[3].matched) { // Identifier or Keyword
                tokens.push_back(deriveTokenFromUnquotedString(match[3].str()));
            } else if (match[4].matched) { // Number (integer or float)
                tokens.push_back({TokenType::NUMBER, match[4].str()});
            } else if (match[5].matched) { // String Literal with escaped quotes
                tokens.push_back({TokenType::STRING_LITERAL, match[5].str()});
            } else if (match[6].matched) { // Symbols and multi-character operators
                tokens.push_back({TokenType::SYMBOL, match[6].str()});
            }
            ++iter;
        }

        return tokens;
    }

}  // namespace zjy_sql::tokenization
