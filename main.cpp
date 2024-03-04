 #include <bits/stdc++.h>
#include <iomanip>
#include "Trie.cpp" // Assume this header file defines the Trie class similar to your Python implementation
using namespace std;

class Solution {
public:
    Trie trie;
    deque<pair<string, string>> queue;

    void buildTrie(const string& filePath) {
        ifstream file(filePath);
        string line;
        if (file.is_open()) {
            while (getline(file, line)) {
                // Remove potential carriage return for Windows files
                if (!line.empty() && line[line.size() - 1] == '\r') {
                    line.erase(line.size() - 1);
                }

                vector<string> prefixes = trie.getPrefixes(line);
                for (const auto& prefix : prefixes) {
                    queue.push_back(make_pair(line, line.substr(prefix.length())));
                }
                trie.insert(line);
            }
            file.close();
        } else {
            cerr << "There was some error with the file!" << endl;
            exit(1);
        }
    }

    pair<string, string> findLongestCompoundWords() {
        string longest_word = "";
        size_t longest_length = 0;
        string second_longest = "";
        while (!queue.empty()) {
            string word = queue.front().first;
            string suffix = queue.front().second;
            queue.pop_front();

            if (trie.contains(suffix) && word.length() > longest_length) {
                second_longest = longest_word;
                longest_word = word;
                longest_length = word.length();
            } else {
                vector<string> prefixes = trie.getPrefixes(suffix);
                for (const auto& prefix : prefixes) {
                    queue.push_back(make_pair(word, suffix.substr(prefix.length())));
                }
            }
        }
        return {longest_word, second_longest};
    }
};

int main() {
    Solution sol;
    auto start = chrono::high_resolution_clock::now();
    sol.buildTrie("2.txt");
    pair<string, string> result = sol.findLongestCompoundWords();
    auto end = chrono::high_resolution_clock::now();

    cout << "Longest Compound Word: " << result.first << endl;
    cout << "Second Longest Compound Word: " << result.second << endl;
    cout << fixed << setprecision(15);
    cout << "Time taken: "
         << chrono::duration_cast<chrono::duration<double>>(end - start).count()
         << " seconds" << endl;

    return 0;
}