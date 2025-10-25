# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is an **Algorithms and Data Structures** learning repository containing lab assignments, practice problems, and data structure implementations in C++. The repository tracks progress through coursework and builds foundational computer science concepts.

## Build and Compilation

All code is written in **C++** with no build system or Makefile.

### Compile and Run
```bash
g++ filename.cpp && ./a.out
```

### Format Code
```bash
clang-format -i filename.cpp
```

## Repository Structure

The codebase is organized into several categories:

- **`labs/`** - Course lab assignments (lab1, lab2, lab3, lab6), each containing multiple problem solutions as individual `.cpp` files
- **`stack/`**, **`queue/`**, **`bst/`** - Data structure implementations and practice problems
  - Stack: LIFO operations, includes practice problems like character matching
  - Queue: Custom linked-list based queue implementation with FIFO operations
  - BST: Binary Search Tree with insertion, traversal, and path validation
- **`basicalgo/`** - Basic algorithm implementations (binary search, merge sort)
- **`prep/`** - Preparation and practice code
- **`midterm/`** - Midterm exam preparation
- **`labs_recap/`** - Lab review materials
- **`ll/`** - Linked list implementations
- **`binsea/`** - Binary search practice

## Code Patterns and Conventions

### Data Structure Implementations

Data structures follow a class-based pattern with:
- Node structs containing data and pointers
- Private helper methods for recursive operations
- Public interface methods
- Proper memory management in destructors

Example from BST (bst/bst.cpp:17-88):
- Private `insertRecursive()` for recursive insertion logic
- Private `destroyTree()` for cleanup
- Public `insert()` and `displayInOrder()` as the interface

### Problem-Solving Files

Most lab files are standalone competitive programming style solutions:
- Read input from stdin
- Process using appropriate data structure or algorithm
- Output to stdout
- Self-contained `main()` function

### Memory Management

Custom data structures implement proper RAII:
- Destructors free all allocated nodes
- Use `delete` for heap-allocated objects
- Queue implementation (queue/main.cpp:24-28) shows proper cleanup pattern

## Working with This Codebase

### Testing Changes
There is no formal test suite. Test by compiling and running individual files with sample inputs.

### Adding New Solutions
Create standalone `.cpp` files in the appropriate directory (labs/labN/ for assignments, or topical directories like stack/ or bst/ for practice).

### Common Patterns
- STL data structures (`std::stack`, `std::queue`) are used alongside custom implementations for learning comparison
- Template-based generic implementations (see queue/main.cpp:6-83)
- Recursive algorithms preferred for tree operations
- Comments often include algorithmic notes (e.g., "LIFO", "FIFO")
