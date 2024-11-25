# Basic Instructions (ADD, SUB, LOAD, STORE)

## 1. ADD (Addition)
The `ADD` instruction performs addition on two operands and stores the result in a destination register or memory location. The operands can be constants, registers, or memory values.

This will add the contents of registers `R2` and `R3`, and store the result in register `R1`.

## 2. SUB (Subtraction)
The `SUB` instruction performs subtraction between two operands and stores the result in a destination register or memory location.

This will subtract the contents of register `R3` from `R2` and store the result in register `R1`.

## 3. LOAD (Load)
The `LOAD` instruction is used to load data from memory into a register. The operand can be a memory address or a constant.

This will load the data at memory address `1000` into register `R1`.

## 4. STORE (Store)
The `STORE` instruction stores the data from a register into a memory location.

This will store the contents of register `R1` into memory location `1000`.

## Example Problem

Let’s say we need to perform the following sequence of operations using these instructions:

1. Load data from memory address `1000` into register `R1`.
2. Load data from memory address `1004` into register `R2`.
3. Add the contents of registers `R1` and `R2`, and store the result in register `R3`.
4. Subtract the contents of register `R2` from `R1`, and store the result in register `R4`.
5. Store the result of `R3` into memory location `2000`.
6. Store the result of `R4` into memory location `2004`.

## Solution

```assembly
LOAD R1, 1000      ; Load data from memory address 1000 into R1
LOAD R2, 1004      ; Load data from memory address 1004 into R2
ADD R3, R1, R2     ; Add contents of R1 and R2, store result in R3
SUB R4, R1, R2     ; Subtract contents of R2 from R1, store result in R4
STORE R3, 2000     ; Store contents of R3 into memory address 2000
STORE R4, 2004     ; Store contents of R4 into memory address 2004
