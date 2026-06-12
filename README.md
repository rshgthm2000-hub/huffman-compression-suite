# Huffman Coding System

A complete C++ implementation of a Huffman Coding–based data compression system, developed as part of a Programming and Data Structures lab project. The project covers encoding, decoding, optimization, and advanced variants of Huffman coding with strict correctness and complexity guarantees.

## Features

- **Frequency Table Construction** from input text
- **Optimal Huffman Tree Construction** with precise tie-breaking rules
- **Encoding & Decoding** of messages using prefix codes
- **Tree Reconstruction** from codebooks and Newick format
- **Linear-Time Huffman Tree Generation** for sorted frequencies (O(C))
- **Counting Distinct Optimal Huffman Trees** (O(C log C))
- **Length-Limited Huffman Coding** using the Package–Merge algorithm (O(C·D))

## Commands Implemented

- `BuildFrequencyTable`
- `BuildTreeFromFrequencyTable`
- `DeriveHuffmanTree`
- `DecodeMessage`
- `GenerateTreeEnhanced`
- `CountHuffmanTrees`
- `GenerateLengthLimitedHuffman`

## Technologies Used

- **Language:** C++
- **Data Structures:** Priority Queue, Queue, Hash Map, Binary Trees
- **Algorithms:** Huffman Coding, Package–Merge Algorithm, Canonical Codes

## Highlights

- Ensures optimal prefix codes under various constraints
- Strict adherence to time complexity requirements
- Supports Newick-format tree representation
- Handles large inputs efficiently
Author

RISHI GOUTHAM
IIT Madras


```bash
g++ -std=gnu++17 your_file.cpp -o huffman
