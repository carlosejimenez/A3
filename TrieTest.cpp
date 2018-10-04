//	Name: Carlos Jimenez (u1200220) - 09/26/2018
// CS3505 - Assignment A3
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

#include "Trie.h"

int main(int argc, char *argv[]){

    // If there are not exactly 3 arguments, we do not want to continue.
    if (argc != 3){
        std::cout << "Error; incorrect number of line arguments.\n";
        return 1;
    }

    Trie test_trie;
    std::string word;
    std::vector<std::string> query_list;

    std::string filename1 = argv[1];
    std::string filename2 = argv[2];

    std::ifstream dictionary, queries;
    dictionary.open(filename1, std::ios::in);
    queries.open(filename2, std::ios::in);

    // If dictionary fails to open, tell user, and quit.
    if (!dictionary.is_open()){
        std::cout << "Error: dictionary cannot be opened.\n";
        return 1;
    }

    // If queries fails to open, tell user, and quit.
    if (!queries.is_open()){
        std::cout << "Error: query file cannot be opened.\n";
        return 1;
    }

    while(dictionary){
        dictionary >> word;
        test_trie.addAWord(word);
    }

    dictionary.close();

    while(queries){
        queries >> word;
        query_list.push_back(word);
    }

    queries.close();

    word = query_list.back();
    query_list.pop_back();

    if (word != query_list.back()){
        query_list.push_back(word);
    }

    // For the queries in the query file, we find out whether it is in the trie. Otherwise we output alternative words.
    for(std::string query : query_list){
        if(test_trie.isAWord(query)){
            std::cout << query << " is found.\n";
        }
        else{
            std::vector<std::string> option_list = test_trie.allWordsStartingWithPrefix(query);
            std::cout << query << " is not found. Did you mean: \n";
            if(option_list.size() == 0){
                std::cout << "   No alternatives found.\n";
            }
            else{
                for(std::string option : option_list){
                    std::cout << "   " << option << std::endl;
                }
            }
        }
    }

    // Copy constructor in action.
    Trie copy_trie = test_trie;

    // We demonstrate the deep copy of the copy constructor by adding a word to test_trie
    // and showing that it is not present in the copy_trie.
    test_trie.addAWord("notaword");
    std::cout << std::boolalpha << copy_trie.isAWord("notaword") << std::endl;

    // Assignment operator in action.
    Trie copy_trie_2;
    copy_trie_2.addAWord("notanotherword");
    copy_trie_2 = test_trie;

    // We demonstrate the deep copy of the assignment operator by adding a word to test_trie
    // and showing that it is not present in the copy_trie_2.
    test_trie.addAWord("notanotherword");
    std::cout << std::boolalpha << copy_trie_2.isAWord("notanotherword") << std::endl;

    // Of course the test_trie contains the newly added words.
    std::cout << std::boolalpha << test_trie.isAWord("notaword") << std::endl;
    std::cout << std::boolalpha << test_trie.isAWord("notanotherword") << std::endl;
    

    return 0;
}
