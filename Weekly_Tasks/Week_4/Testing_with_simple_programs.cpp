#include <iostream>
using namespace std;

// Registers
int R[4] = {0, 0, 0, 0}; // Registers R0, R1, R2, R3

// Memory (256 bytes)
int memory[256] = {0}; // Simulated memory

// Program Counter
int PC = 0; // Points to the next instruction

// Fetch the next instruction
int fetch() {
    return memory[PC++];
}

// Decode and execute the instruction
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

// Load a program into memory
void loadProgram(int program) {
    if (program == 1) {
        // Program 1: Add two numbers
        memory[0] = 1; memory[1] = 0; memory[2] = 10; // LOAD R0, 10
        memory[3] = 1; memory[4] = 1; memory[5] = 20; // LOAD R1, 20
        memory[6] = 2; memory[7] = 2; memory[8] = 0; memory[9] = 1; // ADD R2, R0, R1
        memory[10] = 99; // HALT
    } else if (program == 2) {
        // Program 2: Subtract two numbers
        memory[0] = 1; memory[1] = 0; memory[2] = 15; // LOAD R0, 15
        memory[3] = 1; memory[4] = 1; memory[5] = 25; // LOAD R1, 25
        memory[6] = 3; memory[7] = 2; memory[8] = 1; memory[9] = 0; // SUB R2, R1, R0
        memory[10] = 99; // HALT
    } else if (program == 3) {
        // Program 3: Chain operations
        memory[0] = 1; memory[1] = 0; memory[2] = 5;   // LOAD R0, 5
        memory[3] = 1; memory[4] = 1; memory[5] = 10;  // LOAD R1, 10
        memory[6] = 2; memory[7] = 2; memory[8] = 0; memory[9] = 1; // ADD R2, R0, R1
        memory[10] = 1; memory[11] = 3; memory[12] = 2; // LOAD R3, 2
        memory[13] = 3; memory[14] = 2; memory[15] = 2; memory[16] = 3; // SUB R2, R2, R3
        memory[17] = 99; // HALT
    }
}

// Run the CPU
void run() {
    while (true) {
        int instruction = fetch();
        decodeAndExecute(instruction);
    }
}

// Main function
int main() {
    int program = 1; // Change to 2 or 3 for different programs
    loadProgram(program);
    run();
    return 0;
}