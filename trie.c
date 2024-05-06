#include "trie.h"

#include <stdio.h>

trie_int *trie_int_new()
{
  trie_int *root = (trie_int *)malloc(sizeof(struct _trie_int));
  // value is needed for a key-value storage
  // root->value = 0;

  for (size_t i = 0; i < 256; i++)
  {
    root->keys[i] = NULL;
  }

  return root;
}

void trie_int_destroy(trie_int *root)
{
  for (size_t i = 0; i < 256; i++)
  {
    if (root->keys[i] != NULL)
    {
      trie_int_destroy(root->keys[i]);
      free(root->keys[i]);
    }
  }
}

trie_int *trie_int_insert(trie_int *root, const char *keyword)
{
  if (keyword == NULL)
  {
    return NULL;
  }

  for (size_t i = 0; keyword[i] != '\0'; i++)
  {
    unsigned char ch = keyword[i];

    trie_int *next = root->keys[ch];

    if (next == NULL)
    {
      next = trie_int_new();
      root->keys[ch] = next;
    }

    root = next;
  }

  return root;
}

int trie_int_exists(trie_int *root, const char *keyword)
{
  if (keyword == NULL)
  {
    return 0;
  }

  for (size_t i = 0; keyword[i] != '\0'; i++)
  {
    unsigned char ch = keyword[i];
    trie_int *next = root->keys[ch];

    if (next == NULL)
    {
      return 0;
    }

    root = next;
  }

  return 1;
}

void _trie_int_pprint(trie_int *root, int level)
{
  if (root == NULL)
  {
    return;
  }

  for (size_t i = 0; i < 256; i++)
  {
    if (root->keys[i] != NULL)
    {
      for (int i = 0; i < level; i++)
      {
        printf("|   ");
      }
      printf("| - %c\n", (char)i);
      _trie_int_pprint(root->keys[i], level + 1);
    }
  }
}

void trie_int_pprint(trie_int *root)
{
  _trie_int_pprint(root, 0);
  printf("\n");
}
