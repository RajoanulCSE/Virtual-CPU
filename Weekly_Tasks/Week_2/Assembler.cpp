#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <bitset>

using namespace std;

// Instruction Set with binary opcodes
unordered_map<string, string> opcodeMap = {
    {"ADD", "0001"},
    {"SUB", "0010"},
    {"LOAD", "0011"},
    {"STORE", "0100"},
    {"JUMP", "0101"},
    {"JZ", "0110"},
    {"JNZ", "0111"},
    {"READ", "1000"},
    {"WRITE", "1001"}
};

// Register encoding (R0 to R7 as 3-bit binary)
unordered_map<string, string> registerEncoding = {
    {"R0", "000"},
    {"R1", "001"},
    {"R2", "010"},
    {"R3", "011"},
    {"R4", "100"},
    {"R5", "101"},
    {"R6", "110"},
    {"R7", "111"}
};

// Convert a string number (e.g., "100") to an 8-bit binary representation
string convertToBinary8(int num) {
    return bitset<8>(num).to_string();
}

// Function to check if a string is a valid register
bool checkIfRegister(const string& operand) {
    return registerEncoding.find(operand) != registerEncoding.end();
}

string generateMachineCode(const string &assemblyInstruction) {
    istringstream instructionStream(assemblyInstruction);
    string operation, operand1, operand2;
    instructionStream >> operation;

    // Check for valid opcode
    if (opcodeMap.find(operation) == opcodeMap.end()) {
        return "Error: Invalid Operation";
    }

    // Start with the opcode's binary representation
    string machineCode = opcodeMap[operation];

    // Handle ADD, SUB (two registers)
    if (operation == "ADD" || operation == "SUB") {
        instructionStream >> operand1 >> operand2;
        if (!checkIfRegister(operand1) || !checkIfRegister(operand2)) {
            return "Error: Invalid register in operands";
        }
        string reg1 = registerEncoding[operand1];
        string reg2 = registerEncoding[operand2];
        machineCode += " " + reg1 + " " + reg2;
    }
    // Handle LOAD, STORE (one register and one address)
    else if (operation == "LOAD" || operation == "STORE") {
        instructionStream >> operand1 >> operand2;
        if (!checkIfRegister(operand1)) {
            return "Error: Invalid register in operand";
        }
        string reg = registerEncoding[operand1];
        string address = convertToBinary8(stoi(operand2));  // Convert address to 8-bit binary
        machineCode += " " + reg + " " + address;
    }
    // Handle JUMP, JZ, JNZ (one address or register)
    else if (operation == "JUMP" || operation == "JZ" || operation == "JNZ") {
        instructionStream >> operand1;
        string address;
        // For JUMP, JZ, and JNZ, the operand could be a register or an address
        if (checkIfRegister(operand1)) {
            address = registerEncoding[operand1];
        } else {
            address = convertToBinary8(stoi(operand1));  // Convert address to 8-bit binary
        }
        machineCode += " " + address;
    }
    // Handle READ and WRITE (one register)
    else if (operation == "READ" || operation == "WRITE") {
        instructionStream >> operand1;
        if (!checkIfRegister(operand1)) {
            return "Error: Invalid register in operand";
        }
        string reg = registerEncoding[operand1];
        machineCode += " " + reg;
    }

    return machineCode;
}

int main() {
    vector<string> instructions = {
        "ADD R1 R2",
        "SUB R4 R5",
        "LOAD R1 100",
        "STORE R2 200",
        "JUMP 300",
        "JZ R1 400",
        "WRITE R2"
    };

    for (const auto &instruction : instructions) {
        cout << "Assembly: " << instruction << "\n";
        cout << "Machine Code: " << generateMachineCode(instruction) << "\n\n";
    }

    return 0;
}
