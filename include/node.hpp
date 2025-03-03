#ifndef NODE_HPP
#define NODE_HPP

#include <string>

/**
 * @class Node
 * @brief Abstract base class representing a node in the expression tree.
 *
 * Defines the interface for all expression tree nodes. Each node must implement
 * methods to calculate its value and provide a string representation.
 */
class Node {
public:
    /**
     * @brief Virtual destructor for proper cleanup of derived classes.
     */
    virtual ~Node() = default;

    /**
     * @brief Pure virtual method to calculate node's value.
     * @return Result of the calculation.
     */
    virtual double calculate() const = 0;

    /**
     * @brief Pure virtual method to convert node to string.
     * @return String representation of the node.
     */
    virtual std::string print() const = 0;
};

/**
 * @class Value
 * @brief Represents a numeric value in the expression tree.
 *
 * Leaf node that stores a single numeric value and implements the Node interface.
 */
class Value : public Node {
private:
    double value_; /**< Stored numeric value */

public:
    /**
     * @brief Constructs a Value node.
     * @param v The numeric value to store.
     */
    explicit Value(double v);

    /**
     * @brief Returns the stored value.
     * @return The numeric value.
     */
    double calculate() const override;

    /**
     * @brief Converts value to string.
     * @return String representation of the value.
     */
    std::string print() const override;
};

#endif // NODE_HPP