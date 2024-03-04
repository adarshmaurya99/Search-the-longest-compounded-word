# Word Composition Problem

## Overview
This repository contains a C++ solution for finding the longest compound word and the second-longest compound word from a list of words stored in a file. The solution utilizes a Trie data structure for efficient word storage and retrieval.
## Execution Steps
To execute the program:

- Clone the repository to your local machine.
- Compile the main.cpp file using a C++ compiler (GCC recommended).
- Run the compiled executable with the input file path as a command-line argument.
## Design Decisions and Approach
The program uses a Trie data structure to efficiently store the words read from the input file. The approach involves:

- Building a Trie by reading each word from the input file.
- During Trie construction, maintaining a deque of <word, suffix> pairs relative to existing valid words in the Trie.
- Iterating through the deque to find the longest compound word and its second longest:
  - Checking if the suffix of a word contains any valid word (prefix) from the Trie.
  - If the word is longer than the current longest word, updating the longest and second-longest words accordingly.
  - Generating new suffixes for each prefix length and appending new <word, suffix> pairs to the deque.
## Conclusion
The chosen approach efficiently solves the problem of finding the longest compound words. By leveraging the Trie data structure, the program achieves fast word storage, retrieval, and compound word detection. The concise design ensures simplicity and effectiveness in solving the problem at hand.