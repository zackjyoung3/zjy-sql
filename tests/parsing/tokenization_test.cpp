#include "gtest/gtest.h"
#include "zjy_sql/parsing/tokenization.h"

TEST(SQLTokenizerTest, HanldesSimpleSelectWSymbolsAndIdentifier) {
    using namespace zjy_sql::tokenization;

    const std::string query = "SELECT * FROM users;";
    const std::vector<Token> tokens = tokenizeSQL(query);

    ASSERT_EQ(tokens.size(), 5);
    EXPECT_EQ(tokens[0].type, TokenType::KEYWORD);
    EXPECT_EQ(tokens[0].value, "SELECT");

    EXPECT_EQ(tokens[1].type, TokenType::SYMBOL);
    EXPECT_EQ(tokens[1].value, "*");

    EXPECT_EQ(tokens[2].type, TokenType::KEYWORD);
    EXPECT_EQ(tokens[2].value, "FROM");

    EXPECT_EQ(tokens[3].type, TokenType::IDENTIFIER);
    EXPECT_EQ(tokens[3].value, "users");

    EXPECT_EQ(tokens[4].type, TokenType::SYMBOL);
    EXPECT_EQ(tokens[4].value, ";");
}

TEST(SQLTokenizerTest, HanldeInsertStatementWLiteralVal) {
    using namespace zjy_sql::tokenization;

    const std::string query = "INSERT INTO users (name) VALUES ('Alice')";
    const std::vector<Token> tokens = tokenizeSQL(query);

    ASSERT_EQ(tokens.size(), 10);
    ASSERT_EQ(tokens[0].type, TokenType::KEYWORD);
    ASSERT_EQ(tokens[0].value, "INSERT");

    ASSERT_EQ(tokens[1].type, TokenType::KEYWORD);
    ASSERT_EQ(tokens[1].value, "INTO");

    ASSERT_EQ(tokens[2].type, TokenType::IDENTIFIER);
    ASSERT_EQ(tokens[2].value, "users");

    ASSERT_EQ(tokens[3].type, TokenType::SYMBOL);
    ASSERT_EQ(tokens[3].value, "(");

    ASSERT_EQ(tokens[4].type, TokenType::IDENTIFIER);
    ASSERT_EQ(tokens[4].value, "name");

    ASSERT_EQ(tokens[5].type, TokenType::SYMBOL);
    ASSERT_EQ(tokens[5].value, ")");

    ASSERT_EQ(tokens[6].type, TokenType::KEYWORD);
    ASSERT_EQ(tokens[6].value, "VALUES");

    ASSERT_EQ(tokens[7].type, TokenType::SYMBOL);
    ASSERT_EQ(tokens[7].value, "(");

    ASSERT_EQ(tokens[8].type, TokenType::STRING_LITERAL);
    ASSERT_EQ(tokens[8].value, "'Alice'");

    ASSERT_EQ(tokens[9].type, TokenType::SYMBOL);
    ASSERT_EQ(tokens[9].value, ")");
}


TEST(SQLTokenizerTest, HandlesSelectWithNumberInPredicate) {
    using namespace zjy_sql::tokenization;

    const std::string query = "SELECT age FROM users WHERE id = 42;";
    const std::vector<Token> tokens = tokenizeSQL(query);

    ASSERT_EQ(tokens.size(), 9);

    // Validate each token's type and value
    ASSERT_EQ(tokens[0].type, TokenType::KEYWORD);
    ASSERT_EQ(tokens[0].value, "SELECT");

    ASSERT_EQ(tokens[1].type, TokenType::IDENTIFIER);
    ASSERT_EQ(tokens[1].value, "age");

    ASSERT_EQ(tokens[2].type, TokenType::KEYWORD);
    ASSERT_EQ(tokens[2].value, "FROM");

    ASSERT_EQ(tokens[3].type, TokenType::IDENTIFIER);
    ASSERT_EQ(tokens[3].value, "users");

    ASSERT_EQ(tokens[4].type, TokenType::KEYWORD);
    ASSERT_EQ(tokens[4].value, "WHERE");

    ASSERT_EQ(tokens[5].type, TokenType::IDENTIFIER);
    ASSERT_EQ(tokens[5].value, "id");

    ASSERT_EQ(tokens[6].type, TokenType::SYMBOL);
    ASSERT_EQ(tokens[6].value, "=");

    ASSERT_EQ(tokens[7].type, TokenType::NUMBER);
    ASSERT_EQ(tokens[7].value, "42");

    ASSERT_EQ(tokens[8].type, TokenType::SYMBOL);
    ASSERT_EQ(tokens[8].value, ";");
}

