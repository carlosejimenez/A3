#include <string>
#include <iostream>
#include <vector>

#include"Trie.h"

Trie::Trie(){
    ending = false;
    branches = new Trie*[26];
    for (int i = 0; i < 26; i++){
        branches[i] = nullptr;
    }
}

Trie::Trie(Trie& other){
    ;
}

Trie::~Trie(){
    delete [] branches;
}

int index(char letter){
    return (letter % 97);
}

char letter(int i){
    return (char(i+97));
}

Trie& Trie::operator=(Trie& other){

    return other;
}

void Trie::addAWord(std::string word){
    if (word == ""){
        ending = true;
        return;
    }

    char letter = word[0];

    if (branches[index(letter)] == nullptr){
        branches[index(letter)] = new Trie();
    }
    
    branches[index(letter)]->addAWord(word.substr(1, word.length()));
    return;
}

bool Trie::isAWord(std::string word){
    if (word == ""){
        return ending;
    }

    char letter = word[0];

    if (branches[index(letter)] == nullptr){
        return false;
    }
    else{
        return branches[index(letter)]->isAWord(word.substr(1, word.length()));
    }
}

std::vector<std::string>* Trie::allWordsStartingWithPrefix(std::string word){
    if (word == ""){
        std::vector<std::string>* word_vector = new std::vector<std::string>();
        if (ending){
            word_vector->push_back("");
        }
        for (int i = 0; i < 26; i++){
            if (branches[i] != nullptr){
                std::vector<std::string> sub_vector = *branches[i]->allWordsStartingWithPrefix("");
                for (unsigned int p = 0; p < sub_vector.size(); p++){
                    word_vector->push_back(std::string(1, letter(i)) + sub_vector[p]);
                }
            }
        }
        return word_vector;
    }
    else{
        std::vector<std::string>* word_vector = new std::vector<std::string>();
        if(branches[index(word[0])] == nullptr){
            return word_vector;
        }

        std::vector<std::string> sub_vector = *branches[index(word[0])]->allWordsStartingWithPrefix(word.substr(1, word.length()));
        for (unsigned int p = 0; p < sub_vector.size(); p++){
            std::string partial = word[0] + (sub_vector[p]);;
            word_vector->push_back(partial);
        }
        return word_vector;
    }
}
