### Week 7: Advanced CPU Features

---

#### **Objective**:  
Enhance the virtual CPU by implementing advanced features to improve its functionality and performance.

---

### **Tasks**:

#### **1. Implement Branching and Control Flow Instructions**

- **Description**:  
Branching and control flow instructions allow the CPU to make decisions and alter the execution sequence based on conditions.  

- **Instructions to Implement**:  
  - **JUMP (JMP)**: Unconditional jump to a specific memory address.
  - **BRANCH IF ZERO (BZ)**: Branch to a specific address if a register value is zero.
  - **BRANCH IF NON-ZERO (BNZ)**: Branch to a specific address if a register value is non-zero.

- **Example Code**:
```cpp
void executeInstruction(int opcode, int reg, int address) {
    switch (opcode) {
        case JMP:
            pc = address; // Set the program counter to the target address
            break;
        case BZ:
            if (registers[reg] == 0) pc = address;
            break;
        case BNZ:
            if (registers[reg] != 0) pc = address;
            break;
        default:
            // Handle other instructions
            break;
    }
}
```

---

#### **2. Add Support for Subroutines and Interrupts**

- **Subroutines**:  
  - **Purpose**: Reusable code blocks that can be called from multiple places in the program.
  - **Instructions**: 
    - **CALL address**: Save the current program counter (PC) and jump to the subroutine.
    - **RET**: Restore the saved PC and return to the calling location.

- **Interrupts**:  
  - **Purpose**: Mechanism to handle asynchronous events.
  - **Implementation Steps**:
    - Define an interrupt vector table (IVT) for storing interrupt handlers.
    - Save the current CPU state and jump to the appropriate handler when an interrupt occurs.
    - Restore the CPU state after handling the interrupt.

- **Example Code**:
```cpp
void handleInterrupt(int interruptNumber) {
    // Save CPU state
    stack.push(pc);

    // Jump to the interrupt handler
    pc = interruptVectorTable[interruptNumber];

    // After handling, restore the state
    pc = stack.pop();
}
```

---

#### **3. Integrate a Simple Pipeline Mechanism**

- **Description**:  
Introduce a basic instruction pipeline to improve CPU performance by overlapping instruction fetch, decode, and execute stages.

- **Pipeline Stages**:  
  - **Fetch**: Read the next instruction from memory.
  - **Decode**: Interpret the instruction and determine operands.
  - **Execute**: Perform the instruction operation.

- **Example Code**:
```cpp
struct PipelineStage {
    int opcode;
    int reg;
    int address;
};

void pipelineExecution() {
    PipelineStage fetchStage, decodeStage, executeStage;

    while (true) {
        // Execute stage
        if (executeStage.opcode != NO_OP) {
            executeInstruction(executeStage.opcode, executeStage.reg, executeStage.address);
        }

        // Decode stage
        executeStage = decodeStage;

        // Fetch stage
        fetchStage.opcode = memory[pc];
        fetchStage.reg = memory[pc + 1];
        fetchStage.address = memory[pc + 2];
        decodeStage = fetchStage;

        pc += 3; // Move to the next instruction
    }
}
```

---

### **Example Program**

#### **Branching and Control Flow**  
```assembly
LOAD R1, 5      ; Load 5 into R1
DEC R1          ; Decrement R1
BNZ R1, LOOP    ; Branch to LOOP if R1 != 0
HALT            ; Stop execution
```

#### **Subroutines**  
```assembly
CALL ADD_FUNC   ; Call the ADD_FUNC subroutine
HALT            ; Stop execution

ADD_FUNC:
LOAD R1, 10     ; Load 10 into R1
LOAD R2, 20     ; Load 20 into R2
ADD R3, R1, R2  ; R3 = R1 + R2
RET             ; Return to caller
```

#### **Interrupt Handling**  
```assembly
ENABLE_INT      ; Enable interrupts
WAIT_EVENT      ; Wait for an event
HALT            ; Stop execution

INT_HANDLER:
LOAD R1, 100    ; Load interrupt data
RET             ; Return from interrupt
```

---

### **Testing and Verification**

1. **Branching and Control Flow**:
   - Write a program that uses conditional branching to create loops and test execution flow.
   - Verify the correctness of the program counter updates.

2. **Subroutines**:
   - Create reusable functions (e.g., addition, multiplication).
   - Test `CALL` and `RET` instructions for proper execution.

3. **Interrupts**:
   - Simulate interrupt signals and ensure the correct handler is invoked.
   - Verify the preservation and restoration of the CPU state.

4. **Pipeline Mechanism**:
   - Monitor instruction overlap in fetch-decode-execute cycles.
   - Check for pipeline hazards and ensure correct behavior.

---

### **Expected Output**

#### Example: Loop Program
**Input**: None  
**Output**:
```
R1 = 5
R1 = 4
R1 = 3
R1 = 2
R1 = 1
R1 = 0
```

---

### **Enhancements for Future Work**
1. Add more complex branching (e.g., nested conditions).
2. Implement advanced pipeline techniques (e.g., hazard detection, out-of-order execution).
3. Introduce additional interrupt types and prioritization mechanisms.