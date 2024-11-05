### Instruction Set:
- **ADD**: Addition of two registers.
- **SUB**: Subtraction of two registers.
- **MOV**: Move data between registers.
- **JMP**: Jump to a specified instruction (control flow).
- **LOAD**: Load data from memory into a register.
- **STORE**: Store data from a register into memory.

### Registers:
- **General-purpose registers**: R0-R15.
- **Special-purpose registers**:
  - **Program Counter (PC)**: Tracks the address of the next instruction.
  - **Stack Pointer (SP)**: Points to the current top of the stack.
  - **Status Flags**: Includes Zero, Carry, Overflow flags for conditional operations.

### Memory:
- Simple array-based memory model to simulate RAM.
- Basic read and write operations for memory addresses.

### Clock Cycles:
- Simulate instruction execution with clock cycles, where each instruction takes one or more cycles to execute.

### Interrupts:
- Basic interrupt handling for simulating halting the CPU or triggering system calls.

### I/O Operations:
- Basic **input/output** operations:
  - **PRINT**: Output a value to the console.
  - **READ**: Input a value from the user.

---
