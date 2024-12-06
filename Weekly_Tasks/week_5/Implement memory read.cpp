#include <iostream>
#include <vector>
#include <stdexcept>

class SimulatedMemory {
private:
    std::vector<uint8_t> memory; // Simulated memory space
    size_t size;                // Total size of the memory

public:
    // Constructor to initialize the memory space
    SimulatedMemory(size_t memorySize) : size(memorySize), memory(memorySize, 0) {}

    // Method to write a value to a specific address
    void write(size_t address, uint8_t value) {
        if (address >= size) {
            throw std::out_of_range("Invalid address for memory write");
        }
        memory[address] = value;
    }

    // Method to read a value from a specific address
    uint8_t read(size_t address) const {
        if (address >= size) {
            throw std::out_of_range("Invalid address for memory read");
        }
        return memory[address];
    }

    // Method to display the memory contents for debugging
    void displayMemory(size_t start, size_t end) const {
        if (start >= size || end >= size || start > end) {
            throw std::out_of_range("Invalid range for memory display");
        }
        std::cout << "Memory contents from address " << start << " to " << end << ":\n";
        for (size_t i = start; i <= end; ++i) {
            std::cout << "Address " << i << ": " << +memory[i] << "\n"; // +memory[i] ensures printing as int
        }
    }
};

int main() {
    try {
        // Initialize a simulated memory of 256 bytes
        SimulatedMemory memory(256);

        // Write some values to memory
        memory.write(10, 42);
        memory.write(20, 84);
        memory.write(30, 128);

        // Read and display values from memory
        std::cout << "Value at address 10: " << +memory.read(10) << "\n";
        std::cout << "Value at address 20: " << +memory.read(20) << "\n";
        std::cout << "Value at address 30: " << +memory.read(30) << "\n";

        // Display the state of memory from address 0 to 40
        memory.displayMemory(0, 40);

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}