#include <string>

#include <zjy_sql/parsing/tokenization.h>

int main() {
    const std::string test = "select * FROM test where 'hello'";
    zjy_sql::tokenization::tokenizeSQL(test);
}