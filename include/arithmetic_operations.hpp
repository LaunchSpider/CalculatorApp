#ifndef ARITHMETIC_OPERATIONS_HPP
#define ARITHMETIC_OPERATIONS_HPP

#include "node.hpp"
#include <memory>

/**
 * @class ArithmeticOperation
 * @brief Base class for binary arithmetic operations.
 *
 * Provides common functionality for operations that work with two operands.
 */
class ArithmeticOperation : public Node {
protected:
    std::unique_ptr<Node> left_;  /**< Left operand of the operation */
    std::unique_ptr<Node> right_; /**< Right operand of the operation */

    /**
     * @brief Protected constructor for arithmetic operations.
     * @param l Pointer to left operand node.
     * @param r Pointer to right operand node.
     */
    ArithmeticOperation(Node* l, Node* r);
};

/**
 * @class Add
 * @brief Represents addition operation.
 */
class Add : public ArithmeticOperation {
public:
    /**
     * @brief Constructs addition node.
     * @param l Left operand.
     * @param r Right operand.
     */
    Add(Node* l, Node* r);
    double calculate() const override;
    std::string print() const override;
};

/**
 * @class Subtract
 * @brief Represents subtraction operation.
 */
class Subtract : public ArithmeticOperation {
public:
    Subtract(Node* l, Node* r);
    double calculate() const override;
    std::string print() const override;
};

/**
 * @class Multiply
 * @brief Represents multiplication operation.
 */
class Multiply : public ArithmeticOperation {
public:
    Multiply(Node* l, Node* r);
    double calculate() const override;
    std::string print() const override;
};

/**
 * @class Divide
 * @brief Represents division operation.
 */
class Divide : public ArithmeticOperation {
public:
    Divide(Node* l, Node* r);
    /**
     * @brief Performs division.
     * @throws std::runtime_error on division by zero.
     */
    double calculate() const override;
    std::string print() const override;
};

#endif // ARITHMETIC_OPERATIONS_HPP