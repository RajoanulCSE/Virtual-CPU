
# Simple CPU Emulator in C++

This project demonstrates a simple CPU emulator implemented in C++. It includes an instruction fetch-decode-execute cycle, 
basic arithmetic operations, and test programs.

## Features
- **Registers:** Four general-purpose registers (`R0`, `R1`, `R2`, `R3`).
- **Memory:** Simulated memory with a size of 256 bytes.
- **Instruction Set:**
  - `LOAD`: Load a value into a register.
  - `ADD`: Add values from two registers and store the result in another register.
  - `SUB`: Subtract the value of one register from another and store the result.
  - `HALT`: Stop execution.

## Code Explanation

### Main Components

1. **Registers and Memory:**
   ```cpp
   int R[4] = {0, 0, 0, 0}; // Registers R0, R1, R2, R3
   int memory[256] = {0};   // Simulated memory
   int PC = 0;              // Program Counter
   ```

2. **Fetch-Decode-Execute Cycle:**
   - **Fetch:** Retrieves the next instruction from memory.
   - **Decode:** Interprets the instruction and determines what operation to perform.
   - **Execute:** Performs the operation (e.g., arithmetic or halting).

   ```cpp
   int fetch() {
       return memory[PC++];
   }

   void decodeAndExecute(int instruction) {
       if (instruction == 1) { // LOAD
           int reg = fetch();
           int value = fetch();
           R[reg] = value;
           cout << "LOAD R" << reg << " = " << value << endl;
       } else if (instruction == 2) { // ADD
           int reg1 = fetch(), reg2 = fetch(), reg3 = fetch();
           R[reg1] = R[reg2] + R[reg3];
           cout << "ADD R" << reg1 << " = R" << reg2 << " + R" << reg3 << endl;
       } else if (instruction == 3) { // SUB
           int reg1 = fetch(), reg2 = fetch(), reg3 = fetch();
           R[reg1] = R[reg2] - R[reg3];
           cout << "SUB R" << reg1 << " = R" << reg2 << " - R" << reg3 << endl;
       } else if (instruction == 99) { // HALT
           cout << "HALT. Execution complete." << endl;
           exit(0);
       }
   }
   ```

3. **Loading Programs:**
   Three simple programs are implemented to test the CPU:

   - **Program 1:** Add two numbers.
     ```cpp
     void loadProgram1() {
         memory[0] = 1; memory[1] = 0; memory[2] = 10; // LOAD R0, 10
         memory[3] = 1; memory[4] = 1; memory[5] = 20; // LOAD R1, 20
         memory[6] = 2; memory[7] = 2; memory[8] = 0; memory[9] = 1; // ADD R2, R0, R1
         memory[10] = 99; // HALT
     }
     ```

   - **Program 2:** Subtract two numbers.
     ```cpp
     void loadProgram2() {
         memory[0] = 1; memory[1] = 0; memory[2] = 15; // LOAD R0, 15
         memory[3] = 1; memory[4] = 1; memory[5] = 25; // LOAD R1, 25
         memory[6] = 3; memory[7] = 2; memory[8] = 1; memory[9] = 0; // SUB R2, R1, R0
         memory[10] = 99; // HALT
     }
     ```

   - **Program 3:** Chain operations (add then subtract).
     ```cpp
     void loadProgram3() {
         memory[0] = 1; memory[1] = 0; memory[2] = 5;   // LOAD R0, 5
         memory[3] = 1; memory[4] = 1; memory[5] = 10;  // LOAD R1, 10
         memory[6] = 2; memory[7] = 2; memory[8] = 0; memory[9] = 1; // ADD R2, R0, R1
         memory[10] = 1; memory[11] = 3; memory[12] = 2; // LOAD R3, 2
         memory[13] = 3; memory[14] = 2; memory[15] = 2; memory[16] = 3; // SUB R2, R2, R3
         memory[17] = 99; // HALT
     }
     ```

4. **Running the CPU:**
   The `run()` function executes the program step by step.
   ```cpp
   void run() {
       while (true) {
           int instruction = fetch();
           decodeAndExecute(instruction);
       }
   }
   ```

5. **Main Function:**
   ```cpp
   int main() {
       int program = 1; // Change to 2 or 3 for different programs
       if (program == 1) loadProgram1();
       else if (program == 2) loadProgram2();
       else if (program == 3) loadProgram3();

       run();
       return 0;
   }
   ```

## Example Output

### Program 1: Add Two Numbers
#### Code:
```cpp
loadProgram1();
run();
```

#### Output:
```
LOAD R0 = 10
LOAD R1 = 20
ADD R2 = R0 + R1
HALT. Execution complete.
```

#### Registers at the End:
```
R0: 10, R1: 20, R2: 30
```

### Program 2: Subtract Two Numbers
#### Output:
```
LOAD R0 = 15
LOAD R1 = 25
SUB R2 = R1 - R0
HALT. Execution complete.
```

#### Registers at the End:
```
R0: 15, R1: 25, R2: 10
```

### Program 3: Chain Operations
#### Output:
```
LOAD R0 = 5
LOAD R1 = 10
ADD R2 = R0 + R1
LOAD R3 = 2
SUB R2 = R2 - R3
HALT. Execution complete.
```

#### Registers at the End:
```
R0: 5, R1: 10, R2: 13, R3: 2
```

## How to Run
1. Compile the program using a C++ compiler (e.g., `g++`):
   ```bash
   g++ -o cpu_emulator cpu_emulator.cpp
   ```
2. Run the compiled program:
   ```bash
   ./cpu_emulator
   ```
3. Modify the `program` variable in the `main()` function to test different cases.

## Conclusion
This project demonstrates a simple implementation of a CPU's instruction execution cycle with three example programs. It showcases fundamental concepts like registers, memory, and instruction decoding.
