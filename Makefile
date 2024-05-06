all:
	gcc -Wall main.c trie.c -o trie.o

debug:
	gcc -g main.c trie.c -o trie && sudo gdb trie
