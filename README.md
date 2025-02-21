# Virtual CPU in C++

This project implements a simple Virtual CPU in C++ that can parse and execute basic arithmetic and logical operations. The Virtual CPU consists of components such as an ALU, Control Unit, Registers, Memory, IO Devices, and a Pipeline for instruction parsing.

## Features

- Arithmetic Operations: Addition, Subtraction, Multiplication, Division
- Logical Operations: AND, OR, NOT
- Register and Memory Management
- Input and Output Handling
- Instruction Parsing for Different Formats

## Components

### 1. ALU (Arithmetic Logic Unit)

Handles execution of arithmetic and logical operations.

- **Operations Supported:**
  - `ADD(op1, op2)`: Addition
  - `SUB(op1, op2)`: Subtraction
  - `MUL(op1, op2)`: Multiplication
  - `DIV(op1, op2)`: Division (Handles division by zero)
  - `AND(op1, op2)`: Bitwise AND
  - `OR(op1, op2)`: Bitwise OR
  - `NOT(op1)`: Bitwise NOT

### 2. Control Unit

Manages execution control, program counter, and zero flag.

### 3. Registers

Stores temporary values used during computations.

- Default 4 registers (`R0` to `R3`), each storing an 8-bit binary value.

### 4. Memory

Simulates RAM, storing up to 256 memory locations.

### 5. IO Devices

Handles input and output operations.

- `IN`: Receives input
- `OUT`: Displays output

### 6. Pipeline

Parses and decodes user instructions in different formats:

- `10 + 20` (Infix format)
- `ADD(5,10)` (Function format)
- `R1 + R2` (Register-based operations)
- `ADD(R1, R2)` (Register function format)

## Installation & Usage

### Prerequisites

- C++ Compiler (G++/Clang/MSVC)
- VS Code (Recommended)

### Compilation

To compile the project, run:

```sh
 g++ -o virtual_cpu main.cpp
```

### Running the Program

Execute the compiled binary:

```sh
 ./virtual_cpu
```

### Sample Usage

```sh
 Enter input: ADD(10,20)
 Display: Result: 30
```

## Code Structure

- `main.cpp` - Main entry point
- `alu.cpp` - ALU operations
- `control_unit.cpp` - Control unit logic
- `registers.cpp` - Register operations
- `memory.cpp` - Memory operations
- `io_devices.cpp` - Input/Output handling
- `pipeline.cpp` - Instruction parsing

## Future Improvements

- Support for more complex instructions
- Improved error handling
- Enhanced memory management//



