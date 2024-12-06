#include <iostream>
#include <cstdint>

constexpr size_t MEMORY_SIZE = 1024;
uint8_t memory[MEMORY_SIZE] = {0}; // Simulated memory space

// Simulated write function
void write(size_t address, uint8_t value) {
    if (address < MEMORY_SIZE) {
        memory[address] = value;
    } else {
        std::cerr << "Write out of bounds!\n";
    }
}

// Simulated read function
uint8_t read(size_t address) {
    if (address < MEMORY_SIZE) {
        return memory[address];
    } else {
        std::cerr << "Read out of bounds!\n";
        return 0;
    }
}

int main() {
    write(10, 0xAA);  // Write to address 10
    uint8_t value = read(10);  // Read from address 10
    std::cout << "Value at address 10: 0x" << std::hex << +value << "\n";
    return 0;
}
