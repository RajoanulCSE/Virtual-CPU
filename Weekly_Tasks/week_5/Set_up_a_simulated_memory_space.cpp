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

    // Method to get the memory size
    size_t getSize() const {
        return size;
    }

    // Method to display the memory contents for debugging
    void displayMemory(size_t start, size_t end) const {
        if (start >= size || end >= size || start > end) {
            throw std::out_of_range("Invalid range for memory display");
        }

        std::cout << "Memory contents from address " << start << " to " << end << ":\n";
        for (size_t i = start; i <= end; ++i) {
            std::cout << "Address " << i << ": " << +memory[i] << "\n";
        }
    }
};

int main() {
    try {
        // Initialize a simulated memory of 256 bytes
        SimulatedMemory memory(256);

        // Display the initial state of memory from address 0 to 15
        memory.displayMemory(0, 15);

        // Output the size of the memory
        std::cout << "Total memory size: " << memory.getSize() << " bytes\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
