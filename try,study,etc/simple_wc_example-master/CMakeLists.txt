set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-deprecated-register")

project(simple_wc_example CXX)

cmake_minimum_required(VERSION 3.1)

find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

BISON_TARGET(mc_parser
             mc_parser.yy
             ${CMAKE_CURRENT_BINARY_DIR}/mc_parser.tab.cc)
FLEX_TARGET(mc_lexer
            mc_lexer.l
            ${CMAKE_CURRENT_BINARY_DIR}/mc_lexer.yy.cc)
ADD_FLEX_BISON_DEPENDENCY(mc_lexer mc_parser)

add_executable(my_wc
    main.cpp
    mc_driver.cpp

    ${FLEX_mc_lexer_OUTPUTS}
    ${BISON_mc_parser_OUTPUTS}
)
target_include_directories(my_wc
    PRIVATE
        .
        ${CMAKE_CURRENT_BINARY_DIR})
set_property(TARGET my_wc
             PROPERTY CXX_STANDARD 14)

enable_testing()
add_test(NAME basic
         COMMAND ${CMAKE_SOURCE_DIR}/test/test0.pl
         WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
