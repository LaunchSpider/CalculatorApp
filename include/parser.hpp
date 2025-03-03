#ifndef PARSER_HPP
#define PARSER_HPP

#include "node.hpp"
#include <map>
#include <string>

/**
 * @class Parser
 * @brief Parses mathematical expressions into expression trees.
 *
 * Implements recursive descent parser with operator precedence handling
 * and variable support.
 */
class Parser {
private:
    std::string expression_;              /**< Input expression */
    size_t pos_;                          /**< Current parsing position */
    std::map<char, double> variables_;    /**< Variable storage */
    std::map<char, int> operator_weights_; /**< Operator precedence map */

    /**
     * @brief Parses numeric values.
     * @return Pointer to Value node.
     */
    Node* parseNumber();

    /**
     * @brief Parses factors (numbers, variables, parenthesized expressions).
     * @return Pointer to parsed node.
     * @throws std::runtime_error on parsing errors.
     */
    Node* parseFactor();

    /**
     * @brief Parses operations with precedence.
     * @param min_weight Minimum operator precedence to consider.
     * @return Pointer to expression tree node.
     */
    Node* parseOperations(int min_weight);

public:
    /**
     * @brief Constructs parser with expression.
     * @param expr Mathematical expression to parse.
     */
    explicit Parser(const std::string& expr);

    /**
     * @brief Clears stored variables.
     */
    void clearVariables();

    /**
     * @brief Parses complete expression.
     * @return Pointer to expression tree root.
     * @throws std::runtime_error on invalid expressions.
     */
    Node* parse();
};

#endif // PARSER_HPP