# 🌲 Suffix Tree Implementation
> A sophisticated implementation of suffix trees with both standard and compressed variants, designed for efficient pattern matching and text analysis.

[![Academic Project](https://img.shields.io/badge/Academic-Project-blue.svg)](https://github.com)
[![Institution](https://img.shields.io/badge/UNSTPB-ACS-orange.svg)](https://github.com)
[![Language](https://img.shields.io/badge/Language-C-red.svg)](https://github.com)
[![Year](https://img.shields.io/badge/Year-2-green.svg)](https://github.com)

## 🎯 Project Overview
This implementation provides a comprehensive suffix tree solution featuring both standard and compressed variants. The project includes pattern matching capabilities, statistical analysis, and efficient tree traversal algorithms.

## 🏗️ Core Data Structures

### Standard Suffix Tree Node
```c
typedef struct node {
    char c;                    // Character stored in node
    struct node *children[27]; // Array for a-z + '$'
} node, *tree;
```

### Compressed Suffix Tree Node
```c
typedef struct nodeComp {
    char *label;              // Edge label string
    struct nodeComp *children[27];
} nodeC, *treeC;
```

## 🛠️ Implemented Operations

### Tree Construction Operations
| Operation | Description |
|-----------|-------------|
| `initTree()` | Initializes empty tree with root node |
| `createTree()` | Builds complete suffix tree from input |
| `insertWord()` | Inserts single suffix into tree |
| `decomposeWord()` | Generates all suffixes of input string |

### Analysis Operations
| Operation | Description |
|-----------|-------------|
| `calculateNumOfLeaves()` | Counts terminal nodes |
| `countNodesOnLevel()` | Analyzes nodes at specific depth |
| `maxNumOfDescendants()` | Finds maximum branching factor |
| `findSuffixes()` | Pattern matching in tree |

### Compression Operations
| Operation | Description |
|-----------|-------------|
| `astToCst()` | Converts to compressed format |
| `initTreeC()` | Initializes compressed tree |
| `isSingleChild()` | Checks for path compression opportunity |

## 📊 Task Implementations

### Task 1: Basic Construction
- BFS traversal output
- Complete suffix tree building
- Dynamic memory management

### Task 2: Statistical Analysis
```console
Output format:
<leaf_count>
<k_length_suffixes>
<max_descendants>
```

### Task 3: Pattern Matching
```console
Input: "banana", ["na", "ana"]
Output: 
1
1
```

### Task 4: Compressed Tree
- Path compression
- Space optimization
- Equivalent functionality

## ⚙️ Usage
```bash
./tema2 [-c1 | -c2 <K> | -c3 | -c4] [input_file] [output_file]
```

## 🔍 Implementation Details

### Memory Management
- Dynamic allocation for all nodes
- Proper initialization of pointers
- Fixed-size arrays (27) for alphabet
- Cleanup routines for all allocations

### Complexity Analysis
```
Construction: O(n²)
Pattern Match: O(m)
Space (Standard): O(n²)
Space (Compressed): O(n)
```

### Error Handling
- Null pointer validation
- Input file verification
- Memory allocation checks
- Index bounds verification

## 🚀 Build Instructions
```bash
make build  # Compiles the project
make clean  # Removes artifacts
```

## ⚠️ Important Notes
1. All suffixes are terminated with '$'
2. Input strings use lowercase English alphabet
3. Pattern matching returns binary results
4. Compressed tree maintains original functionality

---
*This project is part of the Data Structures and Algorithms curriculum at UNSTPB ACS Faculty, Computer Science Department.*