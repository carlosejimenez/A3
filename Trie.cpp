//	Name: Carlos Jimenez (u1200220) - 09/26/2018
// CS3505 - Assignment A3
#include <iostream>
#include <vector>
#include <string>

#include"Trie.h"

// Helper functions to convert char to acceptable int index.
int index(char letter){

    return (letter % 97);
}

// Helper functions to convert int index to an acceptable char.
char letter(int i){

    return (char(i+97));
}

Trie::Trie(){
    ending = false;
    for (int i = 0; i < 26; i++){
        branches[i] = nullptr;
    }
}

Trie::Trie(Trie& other) : ending(other.ending), branches(){
    for(int i = 0; i < 26; i++){
      if(other.branches[i] != nullptr){
        branches[i] = new Trie(*other.branches[i]);
      }
    }
}

Trie::~Trie(){
    for (int i = 0; i < 26; i++){
        delete branches[i];
        branches[i] = nullptr;
    }
}

Trie& Trie::operator=(Trie other){
    using std::swap;

    swap(this->ending, other.ending);
    for (int i = 0; i < 26; i++){
        swap(this->branches[i], other.branches[i]);
    }
    return *this;
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

std::vector<std::string> Trie::allWordsStartingWithPrefix(std::string word){
    // If word is empty, we want to add the current position to the return value, if this-> ending is true.
    // And continue adding all relevant words beneath this.
    if (word == ""){
        std::vector<std::string> word_vector;
        if (ending){
            word_vector.push_back("");
        }
        for (int i = 0; i < 26; i++){
            if (branches[i] != nullptr){
                std::vector<std::string> sub_vector = branches[i]->allWordsStartingWithPrefix("");
                for (unsigned int p = 0; p < sub_vector.size(); p++){
                    word_vector.push_back(std::string(1, letter(i)) + sub_vector[p]);
                }
            }
        }

        return word_vector;
    }
    else{

        // Else, we want to only add relevant words corresponding to the next value in the prefix.
        std::vector<std::string> word_vector;
        if(branches[index(word[0])] == nullptr){
            return word_vector;
        }

        std::vector<std::string> sub_vector = branches[index(word[0])]->allWordsStartingWithPrefix(word.substr(1, word.length()));
        for (unsigned int p = 0; p < sub_vector.size(); p++){
            std::string partial = word[0] + (sub_vector[p]);;
            word_vector.push_back(partial);
        }

        return word_vector;
    }
}

std::vector<std::string> wordsWithWildcardPrefix(std::string){
    return std::vector<std::string>();
}
