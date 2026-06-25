# Huffman Coding System

## 📌 Overview

A complete C++ implementation of a Huffman Coding–based data compression system, developed as part of a Programming and Data Structures lab project. The project covers frequency analysis, optimal tree construction, encoding/decoding, and advanced tree counting variants.

Designed with strict adherence to time complexity requirements, this system evaluates different algorithmic approaches to prefix-free codes, from standard priority queues to optimized linear-time queue structures.

---

## 🚀 Features

* **Frequency Table Construction:** Parses input strings and calculates character frequencies map.
* **Optimal Huffman Tree Construction:** Builds trees using a standard minimum priority queue with precise, ID-based tie-breaking rules.
* **Prefix Code Verification:** Reconstructs binary trees directly from existing character codebooks.
* **Tree Parsing & Decoding:** Parses structural Newick format strings back into memory trees to decode binary message streams.
* **Enhanced Linear-Time Generation:** Implements the two-queue algorithmic optimization to build trees when input frequencies are already sorted.
* **Distinct Tree Combinatorics:** Mathematically computes the total number of distinct, structurally valid optimal Huffman trees possible for a given frequency distribution using modular arithmetic.
* ---

## 🎮 Supported Commands

The system reads from standard input and maps to the following execution paths:

* `BuildFrequencyTable [string]`
* `BuildTreeFromFrequencyTable [N] [char freq...]`
* `DeriveHuffmanTree [N] [char binary_string...]`
* `DecodeMessage [Newick_string] [Binary_message]`
* `GenerateTreeEnhanced [N] [char freq...]`
* `CountHuffmanTrees [N] [char freq...]`

---

## 🛠️ Technologies Used

* **Language:** C++
* **Paradigm:** Object-Oriented Tree Modeling
* **Data Structures:** Priority Queues, Queues, Maps, Unordered Maps, Binary Tree Nodes.
* **Algorithmic Concepts:** Greedy Algorithms, Combinatorics, Modular Exponentiation, Newick Tree Formatting.
* ---

## 📊 Compilation & Execution

Compile the source code using standard GNU C++17 flags:

    g++ -std=gnu++17 your_file.cpp -o huffman
    ./huffman

---

## Author

**RISHI GOUTHAM**
Indian Institute of Technology (IIT) Madras
*C++ | Systems Programming | Data Structures & Algorithms*

---

## License

This project is created for educational and academic simulation purposes under the advanced data structures and software systems curriculum tracks.
