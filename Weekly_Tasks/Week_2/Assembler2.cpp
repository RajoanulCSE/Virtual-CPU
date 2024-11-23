#include <iostream>
#include <map>
#include <sstream>
#include <vector>

using namespace std;

// Define opcode and register mappings
map<string, string> opcodeMap = {
    {"MOV", "0001"},
    {"ADD", "0010"},
    {"SUB", "0011"},
    {"JMP", "0100"}
};

map<string, string> registerMap = {
    {"R0", "000"},
    {"R1", "001"},
    {"R2", "010"},
    {"R3", "011"},
    {"R4", "100"},
    {"R5", "101"},
    {"R6", "110"},
    {"R7", "111"}
};

// Function to convert an assembly instruction to machine code
string convertAssemblyToMachineCode(const string &instructionLine) {
    istringstream instructionStream(instructionLine);
    string operation, operandA, operandB;
    instructionStream >> operation >> operandA >> operandB;

    // Check if the operation exists in opcodeMap
    if (opcodeMap.find(operation) == opcodeMap.end()) {
        return "Error: Unknown operation '" + operation + "'";
    }

    // Retrieve the binary opcode
    string binaryOpcode = opcodeMap[operation];

    // Retrieve the binary codes for registers
    string registerA = registerMap[operandA];
    string registerB = (operandB.empty()) ? "000" : registerMap[operandB];

    // Return the final machine code
    return binaryOpcode + registerA + registerB;
}

int main() {
    vector<string> assemblyInstructions = {
        "MOV R1 R2",
        "ADD R2 R3",
        "SUB R3 R1",
        "JMP R4"
    };

    cout << "Converting Assembly Code to Machine Code:\n";
    for (const string &instruction : assemblyInstructions) {
        string machineCode = convertAssemblyToMachineCode(instruction);
        // Output the result
        cout << instruction << " -> " << machineCode << endl;
    }

    return 0;
}
