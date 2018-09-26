#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Trie.h"

using namespace std;

int main(int argc, char *argv[]){

    if (argc != 3){
        cout << "Error, incorrect number of line arguments.\n";
        return 1;
    }

    string word;
    string filename1 = argv[1];
    string filename2 = argv[2];

    ifstream file1;
    file1.open(filename1, ios::in);

    Trie first_tree;

    vector<string> word_list;

    while(file1){
        file1 >> word;
        first_tree.addAWord(word);
        word_list.push_back(word);
    }
    
    for(unsigned int i = 0; i < word_list.size(); i++){
        //cout << i+1 << endl;
        //cout << word_list[i] << " is " << boolalpha << first_tree.isAWord(word_list[i]) << endl;
    }

    vector<string> prefix_list = first_tree.allWordsStartingWithPrefix(filename2);

    for(unsigned int i = 0; i < prefix_list.size(); i++){
        cout << prefix_list[i] << "\n";
    }

    Trie second_tree = first_tree;

    cout << "\nAdding new word.\n\n";

    first_tree.addAWord("zanzibar");

    prefix_list = second_tree.allWordsStartingWithPrefix(filename2);

    for(unsigned int i = 0; i < prefix_list.size(); i++){
        cout << prefix_list[i] << "\n";
    }

    return 0; 
}
