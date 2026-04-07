cmake_minimum_required(VERSION 3.10)
project(ExprParser)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    /usr/include/antlr4-runtime
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/generated/grammar
)

link_directories(/usr/lib64)

add_executable(ExprParser
    ${CMAKE_SOURCE_DIR}/src/main.cpp
    ${CMAKE_SOURCE_DIR}/generated/grammar/ExprLexer.cpp
    ${CMAKE_SOURCE_DIR}/generated/grammar/ExprParser.cpp
    ${CMAKE_SOURCE_DIR}/generated/grammar/ExprBaseVisitor.cpp
)

target_link_libraries(ExprParser antlr4-runtime)