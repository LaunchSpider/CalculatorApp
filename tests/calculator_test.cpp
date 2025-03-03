#include <gtest/gtest.h>
#include "../include/parser.hpp"
#include "../include/arithmetic_operations.hpp"

class CalculatorTest : public ::testing::Test {
protected:
    Parser parser{""};
};

// Basic arithmetic tests
TEST_F(CalculatorTest, Addition) {
    parser = Parser("2+3");
    std::unique_ptr<Node> expressionTree(parser.parse());
    EXPECT_EQ(expressionTree->calculate(), 5.0);
}

TEST_F(CalculatorTest, Subtraction) {
    parser = Parser("5-3");
    std::unique_ptr<Node> expressionTree(parser.parse());
    EXPECT_EQ(expressionTree->calculate(), 2.0);
}

TEST_F(CalculatorTest, Multiplication) {
    parser = Parser("4*3");
    std::unique_ptr<Node> expressionTree(parser.parse());
    EXPECT_EQ(expressionTree->calculate(), 12.0);
}

TEST_F(CalculatorTest, Division) {
    parser = Parser("8/2");
    std::unique_ptr<Node> expressionTree(parser.parse());
    EXPECT_EQ(expressionTree->calculate(), 4.0);
}

// Complex expression tests
TEST_F(CalculatorTest, ComplexExpression) {
    parser = Parser("2+3*4");
    std::unique_ptr<Node> expressionTree(parser.parse());
    EXPECT_EQ(expressionTree->calculate(), 14.0);
}

TEST_F(CalculatorTest, ParenthesesExpression) {
    parser = Parser("(2+3)*4");
    std::unique_ptr<Node> expressionTree(parser.parse());
    EXPECT_EQ(expressionTree->calculate(), 20.0);
}

// Error handling tests
TEST_F(CalculatorTest, DivisionByZero) {
    parser = Parser("5/0");
    std::unique_ptr<Node> expressionTree(parser.parse());
    EXPECT_THROW(expressionTree->calculate(), std::runtime_error);
}

TEST_F(CalculatorTest, InvalidExpression) {
    parser = Parser("2++3");
    EXPECT_THROW(parser.parse(), std::runtime_error);
}

// Negative number tests
TEST_F(CalculatorTest, NegativeNumbers) {
    parser = Parser("-2+3");
    std::unique_ptr<Node> expressionTree(parser.parse());
    EXPECT_EQ(expressionTree->calculate(), 1.0);
}

// Decimal number tests
TEST_F(CalculatorTest, DecimalNumbers) {
    parser = Parser("2.5*2");
    std::unique_ptr<Node> expressionTree(parser.parse());
    EXPECT_EQ(expressionTree->calculate(), 5.0);
}