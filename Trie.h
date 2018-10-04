//	Name: Carlos Jimenez (u1200220) - 09/26/2018
// CS3505 - Assignment A3
#ifndef TRIE_H_
#define TRIE_H_

#include <string>

class Trie{
private:
    // ending indicates whether a trie node is the end of a word.
    bool ending;
    // branches holds an array to trie nodes for each letter of the alphabet.
    Trie* branches[26];

public:
    // Default constructor for empty and blank tries
    Trie();

    // Copy-constructor makes a deep copy of the input value.
    Trie(Trie&);

    // Destructor delets all nodes recursively.
    ~Trie();

    // Assignment operator makes a deep copy of the rhs.
    Trie& operator=(Trie);

    // addAword adds a word to the trie.
    void addAWord(std::string);

    // allWordsStartingWithPrefix returns a vector of all strings starting with the string input.
    std::vector<std::string> allWordsStartingWithPrefix(std::string);

    // isAWord returns true if string input is a word in the trie.
    bool isAWord(std::string);

   std::vector<std::string> wordsWithWildcardPrefix(std::string);
};

#endif
