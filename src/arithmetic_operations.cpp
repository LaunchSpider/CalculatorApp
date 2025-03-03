#include "../include/arithmetic_operations.hpp"
#include <stdexcept>

// Base class implementation
ArithmeticOperation::ArithmeticOperation(Node* l, Node* r) 
    : left_(l), right_(r) {}

// Addition implementation
Add::Add(Node* l, Node* r) : ArithmeticOperation(l, r) {}

double Add::calculate() const {
    return left_->calculate() + right_->calculate();
}

std::string Add::print() const {
    return "(" + left_->print() + " + " + right_->print() + ")";
}

// Subtraction implementation
Subtract::Subtract(Node* l, Node* r) : ArithmeticOperation(l, r) {}

double Subtract::calculate() const {
    return left_->calculate() - right_->calculate();
}

std::string Subtract::print() const {
    return "(" + left_->print() + " - " + right_->print() + ")";
}

// Multiplication implementation
Multiply::Multiply(Node* l, Node* r) : ArithmeticOperation(l, r) {}

double Multiply::calculate() const {
    return left_->calculate() * right_->calculate();
}

std::string Multiply::print() const {
    return "(" + left_->print() + " * " + right_->print() + ")";
}

// Division implementation
Divide::Divide(Node* l, Node* r) : ArithmeticOperation(l, r) {}

double Divide::calculate() const {
    double denominator = right_->calculate();
    if (denominator == 0) {
        throw std::runtime_error("Division by zero");
    }
    return left_->calculate() / denominator;
}

std::string Divide::print() const {
    return "(" + left_->print() + " / " + right_->print() + ")";
}