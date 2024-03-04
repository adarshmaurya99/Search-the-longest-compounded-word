// Trie.cpp

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    char character;
    bool isTerminal;
    unordered_map<char, Node*> children;

    Node(char character = '\0', bool isTerminal = false) : character(character), isTerminal(isTerminal) {}
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    ~Trie() {
        // Destructor to delete allocated nodes
        clear(root);
    }

    void clear(Node* node) {
        for (auto& child : node->children) {
            clear(child.second);
        }
        delete node;
    }

    void insert(const string& word) {
        Node* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                curr->children[ch] = new Node(ch);
            }
            curr = curr->children[ch];
        }
        curr->isTerminal = true;
    }

    bool contains(const string& word) const {
        Node* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                return false;
            }
            curr = curr->children[ch];
        }
        return curr->isTerminal;
    }

    vector<string> getPrefixes(const string& word) const {
        vector<string> prefixes;
        string prefix;
        Node* curr = root;
        for (char ch : word) {
            if (curr->children.find(ch) == curr->children.end()) {
                break;
            }
            curr = curr->children[ch];
            prefix += ch;
            if (curr->isTerminal) {
                prefixes.push_back(prefix);
            }
        }
        return prefixes;
    }
};