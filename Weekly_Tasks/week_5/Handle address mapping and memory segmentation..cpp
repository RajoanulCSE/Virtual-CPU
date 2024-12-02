#include <iostream>
#include <vector>

class SimulatedMemory {
private:
    std::vector<uint8_t> memory; // Simulated memory
    size_t segmentSize;          // Size of each segment

public:
    // Constructor to initialize the memory size and segment size
    SimulatedMemory(size_t size) : memory(size, 0), segmentSize(size / 3) {}

    // Write to memory (checks segment bounds)
    void write(size_t base, size_t address, uint8_t value) {
        if (address < segmentSize) {
            memory[base + address] = value;
        }
    }

    // Read from memory (checks segment bounds)
    uint8_t read(size_t base, size_t address) {
        if (address < segmentSize) {
            return memory[base + address];
        }
        return 0;  // Return 0 if the address is invalid
    }

    // Display a range of memory (useful for debugging)
    void displayMemory(size_t start, size_t end) {
        for (size_t i = start; i <= end; ++i) {
            std::cout << "Address " << i << ": " << +memory[i] << std::endl;
        }
    }
};

int main() {
    SimulatedMemory mem(300); // 300 bytes of memory

    // Base addresses for segments (Code, Data, Stack)
    size_t codeBase = 0;
    size_t dataBase = 100;
    size_t stackBase = 200;

    // Write values to different segments
    mem.write(codeBase, 10, 42);   // Code segment: address 10
    mem.write(dataBase, 50, 84);   // Data segment: address 50
    mem.write(stackBase, 20, 128); // Stack segment: address 20

    // Read and display values from memory
    std::cout << "Code[10]: " << (int)mem.read(codeBase, 10) << std::endl;
    std::cout << "Data[50]: " << (int)mem.read(dataBase, 50) << std::endl;
    std::cout << "Stack[20]: " << (int)mem.read(stackBase, 20) << std::endl;

    // Display memory contents from address 0 to 60
    mem.displayMemory(0, 60);

    return 0;
}
