# 🏗️ System Architecture

## 📖 Overview
The Monty project implements a complete stack and queue interpreter for the Monty 0.98 bytecode language, featuring dynamic mode switching, comprehensive arithmetic operations, and integrated Brainf*ck language support. The architecture emphasizes modularity, performance, and robust error handling through a clean separation of concerns between parsing, execution, and data management components.

---

## 🏛️ High-Level Architecture

```mermaid
graph TD
    A[Monty Interpreter] --> B[Command Line Interface]
    A --> C[File Processing Engine]
    A --> D[Instruction Parser]
    A --> E[Execution Engine]
    A --> F[Data Structure Manager]
    
    B --> G[Argument Validation]
    B --> H[Usage Information]
    
    C --> I[File Stream Handling]
    C --> J[Line Reading]
    C --> K[EOF Detection]
    
    D --> L[Instruction Tokenization]
    D --> M[Parameter Extraction]
    D --> N[Validation Engine]
    
    E --> O[Stack Operations]
    E --> P[Queue Operations] 
    E --> Q[Arithmetic Engine]
    E --> R[I/O Operations]
    
    F --> S[Linked List Management]
    F --> T[Memory Allocation]
    F --> U[Cleanup Operations]
    
    subgraph "Advanced Features"
        V[Brainf*ck Interpreter]
        W[Mode Switching]
        X[Error Recovery]
    end
    
    E --> V
    E --> W
    N --> X
```

The architecture follows a layered design where each component has clearly defined responsibilities, enabling maintainable code and efficient execution of bytecode instructions.

---

## 🧩 Core Components

### Command Line Interface & Initialization
- **Purpose**: Program entry point and initial setup
- **Technology**: Standard C main function with argument processing
- **Location**: `monty.c` (main function)
- **Responsibilities**:
  - Command line argument validation
  - File accessibility verification
  - Global state initialization
  - Error handling for startup failures

### File Processing Engine
- **Purpose**: Bytecode file reading and line management
- **Technology**: Standard C file I/O with stream processing
- **Location**: `monty.c` (file reading loop)
- **Responsibilities**:
  - File stream opening and management
  - Line-by-line reading with getline()
  - Memory management for line buffers
  - End-of-file detection and cleanup

### Instruction Parser & Dispatcher
- **Purpose**: Bytecode instruction parsing and execution dispatch
- **Technology**: String tokenization with function pointer dispatch
- **Location**: `monty.c` (instruction processing), `helpers.c`
- **Responsibilities**:
  - Instruction tokenization and parameter extraction
  - Instruction validation and error detection
  - Function pointer lookup and dispatch
  - Parameter conversion and validation

### Data Structure Manager
- **Purpose**: Stack and queue implementation with dynamic memory management
- **Technology**: Linked list with malloc/free memory management
- **Location**: `lists.c`, global data management
- **Responsibilities**:
  - Node creation and destruction
  - Stack and queue operations
  - Memory allocation and cleanup
  - Data structure integrity maintenance

---

## 💾 Data Architecture

### Core Data Structures
```mermaid
classDiagram
    class GlobalData {
        +char* arg
        +FILE* stream
        +char* line
        +int ret
        +int count
    }
    
    class StackNode {
        +int n
        +StackNode* prev
        +StackNode* next
        +create_node(value)
        +add_to_stack(head, value)
        +add_to_queue(head, value)
        +free_stack(head)
    }
    
    class InstructionSet {
        +char* opcode
        +void(*f)(stack_t**, unsigned int)
        +get_instruction(opcode)
        +execute_instruction(head, counter)
    }
    
    GlobalData --> StackNode : manages
    InstructionSet --> StackNode : operates_on
```

**Global State Management:**
- **data_t structure**: Centralized state for interpreter context
- **Stream handling**: File pointer for bytecode input
- **Mode tracking**: Stack vs queue operation mode
- **Error state**: Global error condition management

### Memory Layout Strategy
- **Doubly Linked List**: Efficient insertion/deletion at both ends
- **Dynamic Allocation**: Nodes allocated as needed with malloc
- **Memory Cleanup**: Automatic cleanup on errors and program termination
- **Pointer Safety**: Comprehensive null pointer checking

---

## 🔄 Execution Architecture

### Instruction Execution Flow
```mermaid
sequenceDiagram
    participant M as Main
    participant P as Parser
    participant D as Dispatcher
    participant S as Stack/Queue
    participant E as Error Handler
    
    M->>M: Open file
    loop For each line
        M->>P: Parse instruction
        P->>P: Tokenize line
        P->>D: Lookup instruction
        D->>D: Validate parameters
        
        alt Valid instruction
            D->>S: Execute operation
            S->>S: Modify data structure
            S-->>D: Success
        else Invalid instruction
            D->>E: Handle error
            E->>E: Print error message
            E->>M: Exit program
        end
    end
    M->>M: Cleanup and exit
```

### Instruction Dispatch System
```mermaid
graph LR
    A[Instruction String] --> B[Tokenization]
    B --> C[Instruction Lookup]
    C --> D{Valid Instruction?}
    
    D -->|Yes| E[Parameter Validation]
    D -->|No| F[Error: Unknown Instruction]
    
    E --> G{Valid Parameters?}
    G -->|Yes| H[Execute Function]
    G -->|No| I[Error: Invalid Parameters]
    
    H --> J[Update Data Structure]
    J --> K[Continue Execution]
    
    F --> L[Exit with Error]
    I --> L
```

---

## ⚙️ Instruction Set Architecture

### Core Stack Operations
```mermaid
graph TD
    A[Stack Operations] --> B[push: Add element]
    A --> C[pop: Remove top element]
    A --> D[pall: Print all elements]
    A --> E[pint: Print top element]
    A --> F[swap: Exchange top two]
    A --> G[nop: No operation]
    
    B --> H[Validate parameter]
    B --> I[Create new node]
    B --> J[Add to stack/queue]
    
    C --> K[Check stack not empty]
    C --> L[Remove top node]
    C --> M[Free memory]
```

### Arithmetic Operations
```mermaid
graph TD
    A[Arithmetic Engine] --> B[add: Addition]
    A --> C[sub: Subtraction]
    A --> D[mul: Multiplication]
    A --> E[div: Division]
    A --> F[mod: Modulo]
    
    B --> G[Pop two elements]
    C --> G
    D --> G
    E --> G
    F --> G
    
    G --> H[Perform operation]
    H --> I[Push result]
    
    E --> J[Check division by zero]
    F --> J
    J --> K[Error handling]
```

### I/O and Character Operations
```mermaid
graph TD
    A[I/O Operations] --> B[pchar: Print character]
    A --> C[pstr: Print string]
    
    B --> D[Validate ASCII range]
    B --> E[Print single character]
    
    C --> F[Print until null/zero]
    C --> G[Handle non-printable]
    
    D --> H[Error if out of range]
    G --> I[Skip non-printable chars]
```

---

## 🔀 Mode Switching Architecture

### Stack vs Queue Behavior
```mermaid
stateDiagram-v2
    [*] --> Stack_Mode
    Stack_Mode --> Queue_Mode: queue instruction
    Queue_Mode --> Stack_Mode: stack instruction
    
    Stack_Mode: LIFO Behavior
    Stack_Mode: Last In, First Out
    Stack_Mode: Add/Remove from top
    
    Queue_Mode: FIFO Behavior
    Queue_Mode: First In, First Out
    Queue_Mode: Add to rear, remove from front
```

**Mode Implementation:**
- **Global flag**: `data.ret` controls current mode
- **Dynamic switching**: Instructions can change mode at runtime
- **Consistent interface**: Same operations, different behavior
- **State persistence**: Mode maintained across instructions

---

## 🧠 Brainf*ck Integration Architecture

### Brainf*ck Interpreter Components
```mermaid
graph TD
    A[Brainf*ck Program] --> B[Memory Tape]
    A --> C[Instruction Pointer]
    A --> D[Data Pointer]
    
    B --> E[30000 byte array]
    B --> F[Zero-initialized]
    
    C --> G[Program counter]
    C --> H[Loop stack]
    
    D --> I[Current cell pointer]
    D --> J[Bounds checking]
    
    subgraph "Operations"
        K[> < + - . , [ ]]
        L[Memory navigation]
        M[Value modification]
        N[I/O operations]
        O[Loop control]
    end
    
    E --> K
    G --> K
    I --> K
```

**Brainf*ck Features:**
- **Memory model**: 30,000-cell byte array
- **Instruction set**: 8 basic operations
- **Loop handling**: Bracket matching with stack
- **I/O integration**: Character input/output

---

## 🔐 Error Handling Architecture

### Comprehensive Error Management
```mermaid
graph TD
    A[Error Detection] --> B[Syntax Errors]
    A --> C[Runtime Errors]
    A --> D[System Errors]
    
    B --> E[Invalid instructions]
    B --> F[Invalid parameters]
    B --> G[Malformed input]
    
    C --> H[Stack underflow]
    C --> I[Division by zero]
    C --> J[Invalid character codes]
    
    D --> K[File access errors]
    D --> L[Memory allocation failures]
    D --> M[I/O errors]
    
    E --> N[Error reporting]
    F --> N
    G --> N
    H --> N
    I --> N
    J --> N
    K --> N
    L --> N
    M --> N
    
    N --> O[Cleanup resources]
    O --> P[Exit with appropriate code]
```

### Error Recovery Strategies
- **Graceful termination**: Clean resource cleanup on errors
- **Informative messages**: Clear error descriptions with line numbers
- **Resource management**: Automatic memory and file handle cleanup
- **Exit codes**: Appropriate program termination status

---

## 📊 Performance Architecture

### Memory Management Strategy
```mermaid
graph LR
    A[Memory Allocation] --> B[Node Creation]
    A --> C[Line Buffers]
    A --> D[File Streams]
    
    B --> E[malloc for nodes]
    B --> F[Zero initialization]
    
    C --> G[getline allocation]
    C --> H[Automatic resizing]
    
    D --> I[FILE* management]
    D --> J[Stream cleanup]
    
    E --> K[Memory tracking]
    F --> K
    G --> K
    H --> K
    I --> K
    J --> K
    
    K --> L[Cleanup on exit]
    K --> M[Error cleanup]
```

### Performance Optimizations
- **Efficient data structures**: Doubly linked list for O(1) operations
- **Memory pooling**: Reuse of allocated structures where possible
- **Stream processing**: Line-by-line processing for large files
- **Lazy evaluation**: Operations performed only when needed

---

## 🛠️ Build and Testing Architecture

### Compilation System
```bash
# Standard compilation
gcc -Wall -Wextra -Werror -pedantic -std=c90 *.c -o monty

# Debug compilation
gcc -g -Wall -Wextra -Werror -pedantic -std=c90 *.c -o monty

# Memory testing
valgrind --leak-check=full ./monty bytecode_file
```

### Testing Framework
```mermaid
graph TD
    A[Testing Suite] --> B[Unit Tests]
    A --> C[Integration Tests]
    A --> D[Performance Tests]
    A --> E[Memory Tests]
    
    B --> F[Individual instructions]
    B --> G[Error conditions]
    B --> H[Edge cases]
    
    C --> I[Complete programs]
    C --> J[Mode switching]
    C --> K[Complex operations]
    
    D --> L[Large files]
    D --> M[Memory usage]
    D --> N[Execution speed]
    
    E --> O[Valgrind analysis]
    E --> P[Leak detection]
    E --> Q[Bounds checking]
```

---

## 📁 Module Organization

### File Structure and Responsibilities
```
monty/
├── monty.h              # Global definitions and structures
├── monty.c              # Main interpreter and file processing
├── builtins1.c          # Core stack operations (push, pop, pall, pint)
├── builtins2.c          # Stack manipulation (swap, add, nop, sub)
├── builtins3.c          # Arithmetic operations (div, mul, mod)
├── builtins4.c          # I/O operations (pchar, pstr, rotl, rotr, queue, stack)
├── helpers.c            # Utility functions and validation
├── lists.c              # Data structure management
├── bf/                  # Brainf*ck interpreter implementation
├── checker/             # Test cases and validation
└── tester/              # Additional testing utilities
```

**Modular Design Benefits:**
- **Separation of concerns**: Each module has distinct responsibilities
- **Maintainability**: Easy to modify and extend individual components
- **Testability**: Independent testing of module functionality
- **Reusability**: Components can be reused in other projects

---

*This architecture documentation provides a comprehensive overview of the Monty interpreter system design, emphasizing the systematic approach to language implementation, data structure management, and software engineering excellence in systems programming.*
