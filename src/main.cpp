#include "../include/parser.hpp"
#include <iostream>
#include <memory>

int main() {
    std::string expression;
    Parser parser("");
    
    while (true) {
        std::cout << "Enter an expression (or 'quit' to exit): ";
        std::getline(std::cin, expression);
        
        if (expression == "quit") {
            break;
        }
        
        if (expression.empty()) {
            continue;
        }

        try {
            parser = Parser(expression);
            std::unique_ptr<Node> expressionTree(parser.parse());
            std::cout << "Parsed expression: " << expressionTree->print() << std::endl;
            std::cout << "Result: " << expressionTree->calculate() << std::endl;
            std::cout << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::cout << std::endl;
        }
    }

    std::cout << "Calculator terminated" << std::endl;
    return 0;
}