cmake_minimum_required(VERSION 3.10)
project(CalculatorApp VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.12.1
)
FetchContent_MakeAvailable(googletest)

include_directories(${PROJECT_SOURCE_DIR}/include)

set(COMMON_SOURCES
    src/node.cpp
    src/arithmetic_operations.cpp
    src/parser.cpp
)

add_executable(calculator 
    src/main.cpp
    ${COMMON_SOURCES}
)

add_executable(calculator_test
    tests/calculator_test.cpp
    ${COMMON_SOURCES}
)
target_link_libraries(calculator_test GTest::gtest_main)