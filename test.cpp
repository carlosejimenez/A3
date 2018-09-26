#include<iostream>
#include<vector>
#include<string>

#include"Trie.h"

using namespace std;

int main(){
    string my_str = "hello there";
    for(int i = 97; i < 107; i++){
        cout << (char(i)) << endl;
    }
    for(int i =0; i < my_str.length(); i++){
        cout << string(1, my_str[i]) << endl;
    }
    return 0;
}
