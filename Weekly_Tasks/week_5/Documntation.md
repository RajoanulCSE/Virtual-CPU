# Week 5: Memory Management

## Objective
This project aims to simulate memory management for a virtual CPU. It involves setting up a simulated memory space, implementing memory read/write operations, and handling address mapping and memory segmentation.

## Tasks
### 1. Set Up a Simulated Memory Space
- **Goal**: Create a simulated memory space that can be divided into different segments (code, data, and stack).
- **Implementation**: A memory model was created using a vector of bytes (`std::vector<uint8_t>`) to represent the memory. Each byte in the vector represents one unit of memory.

### 2. Implement Memory Read/Write Operations
- **Goal**: Implement functions that allow reading from and writing to the simulated memory.
- **Implementation**: The functions `write()` and `read()` allow data to be written to or read from specific memory addresses. The memory is organized into three segments, and the address checks are done within the bounds of these segments.

### 3. Handle Address Mapping and Memory Segmentation
- **Goal**: Organize the memory into different segments and map addresses to these segments.
- **Implementation**: The memory is divided into three parts:
  - **Code Segment**: Stores the program code (addresses from 0 to 99).
  - **Data Segment**: Stores the variables/data (addresses from 100 to 199).
  - **Stack Segment**: Stores stack data (addresses from 200 to 299).

## Memory Layout
The memory is divided into three segments:
1. **Code Segment**:
   - Starts at address `0` and ends at address `99`.
2. **Data Segment**:
   - Starts at address `100` and ends at address `199`.
3. **Stack Segment**:
   - Starts at address `200` and ends at address `299`.

Each segment has a defined base address:
- **Code Base**: `0`
- **Data Base**: `100`
- **Stack Base**: `200`

## Memory Operations
### Write Operation
The `write()` function allows data to be written into the memory at a specific segment and address.

```cpp
void write(size_t base, size_t address, uint8_t value);
base: The starting address of the memory segment (code, data, stack).
address: The address within the segment to write the value to.
value: The value to be written at the specified address.
Read Operation
The read() function allows reading data from the memory at a specific segment and address.

cpp
Copy code
uint8_t read(size_t base, size_t address);
base: The starting address of the memory segment (code, data, stack).
address: The address within the segment to read from.
Display Memory
The displayMemory() function prints the contents of memory from a given range of addresses. It is used for debugging and observing memory content.

cpp
Copy code
void displayMemory(size_t start, size_t end);
start: The starting address to display.
end: The ending address to display.
Example
cpp
Copy code
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
Code Explanation
SimulatedMemory Class:

The class is used to manage memory operations. It uses a std::vector<uint8_t> to represent memory.
It contains methods to write to, read from, and display specific parts of memory.
Memory Segmentation:

Memory is divided into three main segments:
Code Segment: Holds the program code, starting from address 0.
Data Segment: Holds variables and data, starting from address 100.
Stack Segment: Holds temporary stack data, starting from address 200.
Write and Read Operations:

The write() function is used to place data in specific memory addresses.
The read() function retrieves data from specified addresses.
Memory Display:

The displayMemory() method prints the contents of memory from a specified range of addresses, helping with debugging and memory inspection.
Usage
You can create an instance of the SimulatedMemory class with a specified memory size.
The write() method writes values into the memory at specified segment addresses.
The read() method retrieves the data stored at a specific address in the memory.
The displayMemory() method helps display memory contents for debugging.
Future Improvements
Memory Protection: Implementing memory access protection mechanisms such as read-only or write-only segments.
Dynamic Memory Allocation: Implementing a system to allocate and deallocate memory dynamically.
Paging and Virtual Memory: Implementing a virtual memory system with page tables and address translation.
Conclusion
This project provides a basic simulation of memory management for a virtual CPU. It covers memory segmentation, address mapping, and basic memory operations like reading and writing. The implementation can be expanded with more advanced features like dynamic memory allocation, paging, and memory protection.

yaml
Copy code

---

You can save this content as a `.md` file in VS Code or any other text editor, and it will 