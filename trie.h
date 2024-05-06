#ifndef TRIE_H
#define TRIE_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct _trie_int
{
  // value is needed for a key-value storage
  // char value;

  // Array of pointers
  struct _trie_int *keys[256];
} trie_int;

trie_int *trie_int_new();

trie_int *trie_int_insert(trie_int *root, const char *keyword);

int trie_int_exists(trie_int *root, const char *keyword);

trie_int *trie_int_delete(trie_int *root);

void trie_int_destroy(trie_int *root);

void trie_int_pprint(trie_int *root);

#endif
