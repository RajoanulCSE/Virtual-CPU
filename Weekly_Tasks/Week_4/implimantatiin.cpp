#include <iostream>
#include <vector>

using namespace std;

// Memory to hold instructions and data
vector<int> memory(256, 0); // Simulated memory of 256 locations

// Program Counter (PC)
int PC = 0; // Points to the address of the next instruction

// Fetch function to retrieve an instruction from memory
int fetch() {
    if (PC >= memory.size()) {
        cout << "Error: Program Counter out of bounds!" << endl;
        exit(1); // Halt the program if PC exceeds memory bounds
    }
    return memory[PC++]; // Fetch instruction and increment PC
}

// Function to load a program into memory
void loadProgram() {
    // Example program:
    // LOAD R0, 10
    // LOAD R1, 20
    // HALT
    memory[0] = 1;  // LOAD opcode
    memory[1] = 0;  // R0
    memory[2] = 10; // Value 10
    memory[3] = 1;  // LOAD opcode
    memory[4] = 1;  // R1
    memory[5] = 20; // Value 20
    memory[6] = 99; // HALT opcode
}

// Test the fetching mechanism
int main() {
    loadProgram(); // Load instructions into memory

    cout << "Instruction Fetching:" << endl;

    // Simulate the fetch process
    while (PC < memory.size()) {
        int instruction = fetch();
        cout << "Fetched Instruction: " << instruction << endl;

        if (instruction == 99) { // HALT opcode
            cout << "HALT encountered. Stopping execution." << endl;
            break;
        }
    }

    return 0;
}
