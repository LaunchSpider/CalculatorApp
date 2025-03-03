#include "../include/node.hpp"

Value::Value(double v) : value_(v) {}

double Value::calculate() const {
    return value_;
}

std::string Value::print() const {
    return std::to_string(value_);
}