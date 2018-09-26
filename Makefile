CC      = g++
FLAGS = -pedantic -pedantic-errors -Wall -Wextra -fsanitize=address -fsanitize=undefined -g

TrieTest: TrieTest.o Trie.o
	$(CC) $(FLAGS) -o newtest.out TrieTest.o Trie.o

TrieTest.o: TrieTest.cpp Trie.h
	$(CC) $(FLAGS) -c TrieTest.cpp

Trie.o: Trie.cpp Trie.h 
	$(CC) $(FLAGS) -c Trie.cpp

clean:
	rm -rf *.o
	rm -rf newtest.out