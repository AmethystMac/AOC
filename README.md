# Advent of Code Solutions

A collection of solutions for Advent of Code challenges implemented in C++.

## Project Structure

```
.
├── CMakeLists.txt              # Main CMake configuration
├── README.md                   # This file
├── Day3Part1.cpp              # Day 3 Part 1 solution
├── test1.cpp                  # Test file
├── input.txt                  # Input data for testing
├── input2.txt                 # Additional input data
├── 2024/                      # 2024 Challenge solutions
│   ├── D2_2.cpp              # Day 2 Part 2
│   ├── D3_1.cpp              # Day 3 Part 1
│   └── D3_2.cpp              # Day 3 Part 2
└── Utility/                   # Shared utility functions
    ├── CMakeLists.txt        # Utility module CMake configuration
    ├── IntOperations.cpp     # Integer operations implementation
    ├── IntOperations.h       # Integer operations header
    ├── StringOperations.cpp  # String operations implementation
    └── StringOperations.h    # String operations header
```

## Getting Started

### Prerequisites
- C++ compiler (C++17 or later)
- CMake 3.10 or higher

### Building the Project

1. **Create a build directory:**
   ```bash
   mkdir build
   cd build
   ```

2. **Build the project:**
   ```bash
   cmake ..
   make
   ```

### Running Solutions

After building, you can run individual solutions:

```bash
./Day3Part1
./2024/D2_2
./2024/D3_1
./2024/D3_2
```

Or run tests:
```bash
./test1
```

## Notes

- All solutions are written in C++
- Input files are located in the root directory
- Shared utilities are in the `Utility/` subdirectory
- Each challenge can be built and run independently
