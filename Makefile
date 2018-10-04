#	Name: Carlos Jimenez (u1200220) - 09/26/2018
# CS3505 - Assignment A3
CC      = g++
FLAGS = -pedantic -Wall -fsanitize=address -fsanitize=undefined

TrieTest: TrieTest.o Trie.o
	$(CC) $(FLAGS) -o TrieTest.out TrieTest.o Trie.o

TrieTest.o: TrieTest.cpp
	$(CC) $(FLAGS) -c TrieTest.cpp

Trie.o: Trie.cpp Trie.h 
	$(CC) $(FLAGS) -c Trie.cpp

clean:
	rm -rf *.o
	rm -rf TrieTest.out