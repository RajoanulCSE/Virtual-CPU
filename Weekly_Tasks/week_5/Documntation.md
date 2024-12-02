# Week 5: Memory Management

## Objective
The goal is to implement memory management for a virtual CPU, including setting up a simulated memory space, enabling read/write operations, and managing address mapping and memory segmentation.

---

## Tasks

### 1. Set Up Simulated Memory Space
- Create a memory model to simulate a fixed-size memory.
- Dynamically allocate memory and initialize it to zero.
- Ensure the memory space is divided logically into segments for better management.

### 2. Implement Memory Read/Write Operations
- Provide safe methods to read and write values at specific memory addresses.
- Implement boundary checks to avoid invalid memory access.
- Handle exceptions for out-of-range operations.

### 3. Address Mapping and Memory Segmentation
- Divide memory into logical segments (e.g., Code, Data, Stack).
- Define base addresses and segment sizes for each region.
- Ensure memory access respects segment boundaries.

---

## Features

### Memory Model
- Simulates a fixed-size memory using a `std::vector`.
- Supports initialization with a specific size.

### Operations
1. **Write Operation**:
   - Allows writing a byte value to a specific address.
   - Throws an exception for invalid addresses.
2. **Read Operation**:
   - Reads a byte value from a specific address.
   - Returns an exception for out-of-bounds access.
3. **Memory Segmentation**:
   - Logical segmentation of memory into regions for Code, Data, and Stack.
   - Ensures values are written and read within the defined boundaries.

---

## Implementation

### Example Code

```cpp
#include <iostream>
#include <vector>
#include <stdexcept>

class SimulatedMemory {
private:
    std::vector<uint8_t> memory;
    size_t segmentSize;

public:
    SimulatedMemory(size_t size) : memory(size, 0), segmentSize(size / 3) {}

    void write(size_t base, size_t address, uint8_t value) {
        if (address < segmentSize) {
            memory[base + address] = value;
        } else {
            throw std::out_of_range("Address out of segment bounds");
        }
    }

    uint8_t read(size_t base, size_t address) {
        if (address < segmentSize) {
            return memory[base + address];
        } else {
            throw std::out_of_range("Address out of segment bounds");
        }
    }

    void displayMemory(size_t start, size_t end) {
        for (size_t i = start; i <= end; ++i) {
            std::cout << "Address " << i << ": " << +memory[i] << std::endl;
        }
    }
};

int main() {
    SimulatedMemory mem(300);
    size_t codeBase = 0, dataBase = 100, stackBase = 200;

    mem.write(codeBase, 10, 42);
    mem.write(dataBase, 50, 84);
    mem.write(stackBase, 20, 128);

    std::cout << "Code[10]: " << (int)mem.read(codeBase, 10) << "\n";
    std::cout << "Data[50]: " << (int)mem.read(dataBase, 50) << "\n";
    std::cout << "Stack[20]: " << (int)mem.read(stackBase, 20) << "\n";

    mem.displayMemory(0, 60);

    return 0;
}

## Memory Segmentation

| Segment | Base Address       | Size            |
|---------|--------------------|-----------------|
| Code    | `0`                | `1/3 of memory` |
| Data    | `1/3 of memory`    | `1/3 of memory` |
| Stack   | `2/3 of memory`    | `1/3 of memory` |

## Conclusion

The implementation of a simulated memory model provides a practical approach to understanding memory management in a virtual CPU environment. By dividing memory into logical segments, performing safe read/write operations, and handling boundary checks, this project demonstrates key principles of memory organization. Future enhancements such as dynamic resizing, protection mechanisms, and advanced techniques like caching or paging can further extend its capabilities. This foundation serves as a valuable learning tool for exploring memory management concepts in system design.
