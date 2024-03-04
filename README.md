#Code Execution Procedure
Requires C++ compiler (GCC recommended) to be Installed

Download / Clone the repository into your machine.

Compile the main.cpp file:

bash
Copy code
g++ main.cpp -o longest_compound_word_finder
Execute the compiled program with the input file path:

bash
Copy code
./longest_compound_word_finder 1.txt
Replace 1.txt with the path to your input file containing the list of words.

A Brief Study of the Problem
Compounded words are formed using one or more of the valid words from the selected file.
As the files are sorted alphabetically and contain one word per line, valid words composing the compounded words likely precede the compounded word itself.
A compounded word can be viewed as a combination of previously read words (prefix) and a suffix.
If a character not part of any valid word occurs within a word being read, it cannot be considered a compounded word.
Approach and Algorithm
The chosen approach is a modified Trie-based algorithm, known for its efficiency and simplicity in dealing with word-related problems.

Algorithm:

Build the Trie by reading each word from the selected file.
While building the Trie, create a deque containing <word, suffix> pairs relative to existing valid words in the Trie.
Initialize longest, second_longest, and max_length variables.
While the deque is not empty:
Pop <word, suffix> pairs from the deque.
Check if the suffix contains any valid word (prefix) from the Trie. If length(word) > max_length, update second_longest, longest, and max_length.
If no valid word is found in the suffix, generate new suffixes for each prefix length and append new <word, suffix> pairs to the deque.
Return the longest and second_longest words.
Results:
Machine Specifications

OS: Windows 10

CPU: Ryzen 3 2200G

RAM: 16 GB DDR4

Output for File: Input_01.txt
Output for File: Input_01.txt
