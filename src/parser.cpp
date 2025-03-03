#include "../include/parser.hpp"
#include "../include/arithmetic_operations.hpp"
#include <iostream>
#include <cctype>

Parser::Parser(const std::string& expr) 
    : expression_(expr), pos_(0) {
    // Initialize operator precedence levels
    operator_weights_ = {
        {'+', 1}, // Addition (lowest precedence)
        {'-', 1}, // Subtraction
        {'*', 2}, // Multiplication
        {'/', 2}  // Division (highest precedence)
    };
}

Node* Parser::parseNumber() {
    std::string num;
    
    // Handle unary minus
    if (pos_ < expression_.length() && expression_[pos_] == '-') {
        num += expression_[pos_++];
    }
    
    // Parse digits and decimal point
    while (pos_ < expression_.length() && 
           (std::isdigit(expression_[pos_]) || expression_[pos_] == '.')) {
        num += expression_[pos_++];
    }
    
    return new Value(std::stod(num));
}

Node* Parser::parseFactor() {
    // Handle parenthesized expressions
    if (expression_[pos_] == '(') {
        pos_++;
        Node* node = parseOperations(0);
        if (expression_[pos_] != ')') {
            throw std::runtime_error("Expected ')'");
        }
        pos_++;
        return node;
    } 
    // Handle variables
    else if (std::isalpha(expression_[pos_])) {
        char var = expression_[pos_++];
        auto operatorInfo = variables_.find(var);
        if (operatorInfo == variables_.end()) {
            std::cout << "Enter value for " << var << ": ";
            double value;
            std::cin >> value;
            
            /**
             * @brief Clears remaining characters until newline.
             * Implement due to the error of repeating twice(normally one, when the expression is only digits) "Enter the expression" promt occuring, when imputing variables: Enter an expression (or 'quit' to exit): Enter an expression (or 'quit' to exit):
             * The issue occured when handling variables due to leftover input in the buffer.
             */
            char c;
            while ((c = std::cin.get()) != '\n' && c != EOF) { }
            
            variables_[var] = value;
        }
        return new Value(variables_[var]);
    }
    // Handle numbers
    return parseNumber();
}

Node* Parser::parseOperations(int min_weight) {
    Node* left = parseFactor();
    
    while (pos_ < expression_.length()) {
        char currentOperator = expression_[pos_];
        
        // Check operator precedence
        auto operatorInfo = operator_weights_.find(currentOperator);
        if (operatorInfo == operator_weights_.end() || 
            operatorInfo->second < min_weight) {
            break;
        }
        
        pos_++;
        
        // Create appropriate operation node
        switch (currentOperator) {
            case '+':
                left = new Add(left, parseOperations(operator_weights_[currentOperator] + 1));
                break;
            case '-':
                left = new Subtract(left, parseOperations(operator_weights_[currentOperator] + 1));
                break;
            case '*':
                left = new Multiply(left, parseOperations(operator_weights_[currentOperator] + 1));
                break;
            case '/':
                left = new Divide(left, parseOperations(operator_weights_[currentOperator] + 1));
                break;
            default:
                throw std::runtime_error("Unknown operator");
        }
    }
    return left;
}

void Parser::clearVariables() {
    variables_.clear();
}

Node* Parser::parse() {
    return parseOperations(0);
}