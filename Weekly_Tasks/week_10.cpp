#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <fstream>
#include <chrono>

// Instruction Set Definition
enum Instructions {
    LOAD = 0x01, STORE, ADD, SUB, JMP, CALL, RET, PUSH, POP, IN, OUT, INT, HALT = 0xFF
};

// Memory Class
class Memory {
private:
    std::vector<int> data;
public:
    Memory(size_t size) : data(size, 0) {}
    int read(int addr) { return (addr < data.size()) ? data[addr] : 0; }
    void write(int addr, int value) { if (addr < data.size()) data[addr] = value; }
    size_t size() { return data.size(); }
};

// I/O Device Class
class IODevice {
public:
    static int input() {
        int value;
        std::cout << "Input: ";
        std::cin >> value;
        return value;
    }
    static void output(int value) {
        std::cout << "Output: " << value << std::endl;
    }
};

// CPU Class
class CPU {
private:
    std::vector<int> registers;
    int programCounter;
    int instructionRegister;
    bool zeroFlag;
    Memory &memory;
    std::stack<int> callStack;
public:
    CPU(Memory &mem) : registers(4, 0), programCounter(0), instructionRegister(0), zeroFlag(false), memory(mem) {}
    void loadProgram(const std::vector<int> &program) {
        for (size_t i = 0; i < program.size(); i++) {
            memory.write(i, program[i]);
        }
    }
    void execute() {
        auto start = std::chrono::high_resolution_clock::now();
        while (programCounter < memory.size()) {
            instructionRegister = memory.read(programCounter++);
            switch (instructionRegister) {
                case LOAD: registers[memory.read(programCounter++)] = memory.read(programCounter++); break;
                case ADD: registers[0] += registers[1]; break;
                case SUB: registers[0] -= registers[1]; break;
                case STORE: memory.write(memory.read(programCounter++), registers[0]); break;
                case JMP: programCounter = memory.read(programCounter); break;
                case CALL: callStack.push(programCounter); programCounter = memory.read(programCounter); break;
                case RET: if (!callStack.empty()) programCounter = callStack.top(), callStack.pop(); break;
                case PUSH: callStack.push(registers[memory.read(programCounter++)]); break;
                case POP: if (!callStack.empty()) registers[memory.read(programCounter++)] = callStack.top(), callStack.pop(); break;
                case IN: registers[memory.read(programCounter++)] = IODevice::input(); break;
                case OUT: IODevice::output(registers[memory.read(programCounter++)]); break;
                case INT: std::cout << "Interrupt Triggered: " << memory.read(programCounter++) << std::endl; break;
                case HALT: goto END;
            }
        }
    END:
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Execution Time: " << elapsed.count() << " seconds" << std::endl;
    }
};

// Assembler Class
class Assembler {
private:
    std::unordered_map<std::string, int> opcode = {
        {"LOAD", 0x01}, {"STORE", 0x02}, {"ADD", 0x03}, {"SUB", 0x04}, 
        {"JMP", 0x05}, {"CALL", 0x06}, {"RET", 0x07}, {"PUSH", 0x08}, {"POP", 0x09},
        {"IN", 0x0A}, {"OUT", 0x0B}, {"INT", 0x0C}, {"HALT", 0xFF}
    };
public:
    void assemble(std::string filename) {
        std::ifstream input(filename);
        std::ofstream output("output.bin", std::ios::binary);
        std::string instruction;
        while (input >> instruction) {
            output.put(opcode[instruction]);
        }
        input.close();
        output.close();
    }
};

// Main Function
int main() {
    Memory memory(256);
    CPU cpu(memory);
    
    std::vector<int> program = {
        IN, 0, CALL, 10, OUT, 0, HALT,  // Main program
        10, LOAD, 1, 2, ADD, RET        // Subroutine at address 10
    };
    
    cpu.loadProgram(program);
    cpu.execute();
    
    return 0;
}
