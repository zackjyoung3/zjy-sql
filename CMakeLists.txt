cmake_minimum_required(VERSION 3.15)
project(ZjySql)

enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(parser STATIC
        src/parsing/parser.cpp
        src/parsing/tokenization.cpp
)
target_include_directories(parser PUBLIC include)

add_executable(zjy_sql src/main.cpp)
target_link_libraries(zjy_sql PRIVATE parser)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(run_tests tests/parsing/tokenization_test.cpp)

find_package(GTest REQUIRED CONFIG)
target_link_libraries(run_tests PRIVATE GTest::gtest GTest::gtest_main parser)

add_test(NAME MyTests COMMAND run_tests)
