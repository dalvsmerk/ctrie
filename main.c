#include <stdio.h>

#include "trie.h"
#include "list.h"

void test_list()
{
  list_char *list = list_char_new();
  list_char_append(list, 'a');
  list_char_append(list, 'b');
  list_char_append(list, 'c');
  list_char_append(list, 'd');
  int removed = list_char_remove(list, 'c');
  printf("Removed %d chars\n", removed);
  list_char_pprint(list, ", ");

  list_char_node *d = list_char_find(list, 'd');
  if (d != NULL)
  {
    printf("Found d: %c\n", d->value);
  }

  list_char_node *c = list_char_find(list, 'c');
  if (c != NULL)
  {
    printf("Found c: %c\n", c->value);
  }

  printf("sizeof(char): %lu\n", sizeof(char));

  list_char_destroy(list);
}

int main(void)
{
  test_list();

  trie_int *root = trie_int_new();

  trie_int_insert(root, "hello");
  trie_int_insert(root, "gap");
  trie_int_insert(root, "gas");
  trie_int_insert(root, "hell");
  trie_int_insert(root, "gold");
  trie_int_insert(root, "nemesis");
  trie_int_insert(root, "nemo");
  trie_int_insert(root, "night");
  trie_int_insert(root, "negate");
  trie_int_pprint(root);

  printf("hell exists: %d\n", trie_int_exists(root, "hell"));

  trie_int_destroy(root);

  return 0;
}
