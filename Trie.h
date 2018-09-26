#ifndef TRIE_H_
#define TRIE_H_

#include <string>

class Trie{
private:
    Trie* branches[26];
    bool ending;

public:
    Trie();
    Trie(Trie&);
    ~Trie();

    Trie& operator=(Trie&);

    void addAWord(std::string);
    bool isAWord(std::string);
    std::vector<std::string> allWordsStartingWithPrefix(std::string);

};


#endif
