#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std;

// Function to convert an assembly instruction to machine code
string assemble(const string& instruction) {
    // Define a map between assembly instructions and their machine code equivalents
    map<string, string> instructionSet;
    
    // Simple instruction set (you can expand this as needed)
    instructionSet["ADD"] = "0001";
    instructionSet["SUB"] = "0010";
    instructionSet["LOAD"] = "0100";
    instructionSet["STORE"] = "1000";
    instructionSet["MOV"] = "1100"; // Example MOV instruction

    // Parse the instruction (just the opcode part)
    string opcode;
    stringstream ss(instruction);
    ss >> opcode;

    // Check if the instruction exists in the map and return the corresponding machine code
    if (instructionSet.find(opcode) != instructionSet.end()) {
        return instructionSet[opcode]; // Return corresponding machine code
    } else {
        return "Invalid instruction"; // If instruction is not found
    }
}

int main() {
    string assemblyCode;

    // Display a simple prompt for user input
    cout << "Enter an assembly instruction (e.g., ADD, SUB, LOAD): ";
    getline(cin, assemblyCode);  // Get a line of input from the user

    // Convert the input assembly instruction to machine code
    string machineCode = assemble(assemblyCode);

    // Output the result
    cout << "Machine Code: " << machineCode << endl;

    return 0;
}
