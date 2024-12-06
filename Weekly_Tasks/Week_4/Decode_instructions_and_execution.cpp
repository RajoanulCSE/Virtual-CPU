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
    return memory[PC++]; // Return the instruction and increment the Program Counter
}

// Decode and execute the instruction
void decodeAndExecute(int instruction) {
    if (instruction == 1) { // LOAD
        int reg = fetch(); // Get register number
        int value = fetch(); // Get value
        R[reg] = value; // Load value into the register
        cout << "LOAD R" << reg << " = " << value << endl;
    } else if (instruction == 2) { // ADD
        int reg1 = fetch(); // Destination register
        int reg2 = fetch(); // Source register 1
        int reg3 = fetch(); // Source register 2
        R[reg1] = R[reg2] + R[reg3]; // Add values and store in destination
        cout << "ADD R" << reg1 << " = R" << reg2 << " + R" << reg3 << endl;
    } else if (instruction == 99) { // HALT
        cout << "HALT. Stopping execution." << endl;
        exit(0); // Stop the program
    } else {
        cout << "Unknown instruction!" << endl;
    }
}

// Load a simple program into memory
void loadProgram() {
    // Program: LOAD R0, 10; LOAD R1, 20; ADD R2, R0, R1; HALT
    memory[0] = 1; memory[1] = 0; memory[2] = 10; // LOAD R0, 10
    memory[3] = 1; memory[4] = 1; memory[5] = 20; // LOAD R1, 20
    memory[6] = 2; memory[7] = 2; memory[8] = 0; memory[9] = 1; // ADD R2, R0, R1
    memory[10] = 99; // HALT
}

// Run the CPU
void run() {
    while (true) {
        int instruction = fetch(); // Fetch next instruction
        decodeAndExecute(instruction); // Decode and execute it
    }
}

// Main function
int main() {
    loadProgram(); // Load program into memory
    run(); // Start the CPU
    return 0;
}