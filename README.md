# Calculator Application

A C++ expression parser and calculator that evaluates mathematical expressions using an abstract syntax tree approach with operator precedence.

## Project Structure

```
CalculatorApp/
├── include/              # Header files
│   ├── node.hpp         # Base node interface
│   ├── arithmetic_operations.hpp
│   └── parser.hpp       # Expression parser
├── src/                 # Implementation files
│   ├── main.cpp
│   ├── node.cpp
│   ├── arithmetic_operations.cpp
│   └── parser.cpp
├── tests/              # GTest tests
│   └── calculator_test.cpp
├── build/             # CMake build folder
└── CMakeLists.txt    # Build configuration
```

## Class Hierarchy

```
Node (Abstract Base)
├── Value (Leaf node)
└── ArithmeticOperation (Internal nodes)
    ├── Add
    ├── Subtract
    ├── Multiply
    └── Divide
```

## Parser Implementation (reference: https://youtu.be/WdlXBDHXqAs?si=9-02TWpi3O6qytvT)

### Operator Precedence System

The parser implements operator precedence using a weight-based system:

```cpp
std::map<char, int> operator_weights_ = {
    {'+', 1},  // Lower precedence
    {'-', 1},
    {'*', 2},  // Higher precedence
    {'/', 2}
};
```
This implements the standard mathematical order of operations:

1. Higher weights (2) for multiplication and division
2. Lower weights (1) for addition and subtraction
3. Parentheses handled separately for highest precedence

This weight system ensures:
- Multiplication/division happen before addition/subtraction
- Same-weight operators are evaluated left-to-right
- Parentheses override normal precedence

### Parsing Algorithm

The parser uses recursive descent with three main methods:

1. parseOperations:
- Entry point for parsing
- Handles operator precedence through weight comparison
- Example: For "2 + 3 * 4":
```
parseOperations(0)
├── parseFactor() -> Value(2)
├── sees '+' (weight 1)
└── parseOperations(2)
    ├── parseFactor() -> Value(3)
    ├── sees '*' (weight 2)
    └── parseFactor() -> Value(4)
```

2. parseFactor:
- Handles atomic elements (numbers, variables)
- Manages parenthesized expressions
- Example: For "(1 + 2)":
```
parseFactor()
├── sees '('
├── parseOperations(0)
│   ├── Value(1)
│   ├── '+'
│   └── Value(2)
└── sees ')'
```

### Expression Tree Building

Example of how "2 + 3 * 4" is parsed:

```
         +
        / \
       2   *
          / \
         3   4
```

1. First pass:
- Reads "2"
- Sees "+"
- Creates Add node
2. Second pass:
- Reads "3"
- Sees "*" (higher precedence)
- Creates Multiply node
- Reads "4"
3. Final structure:
- Add(Value(2), Multiply(Value(3), Value(4)))

## Building and running the calculator

!Command line app(./calculator) and testing sequences(./calculator_test) are alrere pre-build for LINUX, executables(./calculator and ./calculator_test) can be found in the build-linux folder!

### Prerequisites
- CMake 3.10+
- C++17 compliant compiler
- Google Test (for unit tests)
- -Git

### Build commands for LINUX(already pre-built in the repository)

```bash
mkdir build-linux
cd build-linux
cmake ..
make
```

#### Run Calculator

```bash
cd build-linux
./calculator
```

### Build commands for WINDOWS

```bash
mkdir build-windows
cd build-windows
cmake ..
cmake --build .
```

#### Run Calculator

```bash
cd build-windows
.\Debug\calculator.exe
```

### Usage Examples

```
> 2 + 3 * 4
Parsed: (2 + (3 * 4))
Result: 14

> (2 + 3) * 4
Parsed: ((2 + 3) * 4)
Result: 20

> x + 5
Enter value for x: 3
Parsed: (3 + 5)
Result: 8
```

## Testing

Tests cover:
- Basic arithmetic
- Complex expressions
- Error cases
- Variable handling
- Operator precedence

### Run Tests on LINUX

```bash
cd build-linux
./calculator_test
```

### Run Tests on WINDOWS

```bash
cd build-windows
.\Debug\calculator_test.exe
```

## Key Features

### Variable Support
- Single-letter variables (x, y, z)
- Values stored in std::map

### Memory Management
- Smart pointers (std::unique_ptr)
- Automatic cleanup

### Error Handling
- Division by zero detection
- Invalid syntax checks
- Parentheses matching
- Unknown operator detection
