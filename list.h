#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>

typedef struct _list_char_node
{
  char value;
  struct _list_char_node *prev;
  struct _list_char_node *next;
} list_char_node;

typedef struct _list_char
{
  list_char_node *begin;
  list_char_node *end;
} list_char;

list_char_node *list_char_node_new(char value)
{
  list_char_node *new_node = (list_char_node *)malloc(sizeof(list_char_node));
  if (new_node == NULL)
  {
    printf("Failed to allocate new list node");
    exit(1);
  }

  new_node->value = value;
  new_node->prev = NULL;

  return new_node;
}

list_char *list_char_new()
{
  list_char *container = (list_char *)malloc(sizeof(list_char));
  container->begin = NULL;
  container->end = NULL;
  return container;
}

void list_char_destroy(list_char *container)
{
  list_char_node *begin = container->begin;

  while (begin != NULL)
  {
    list_char_node *next = begin->next;

    free(begin);
    begin = next;
  }

  free(container);
}

list_char_node *list_char_append(list_char *container, char value)
{
  list_char_node *new_node = list_char_node_new(value);

  if (container->begin == NULL)
  {
    container->begin = new_node;
    container->end = new_node;
    return new_node;
  }

  container->end->next = new_node;
  new_node->prev = container->end;
  container->end = new_node;

  return new_node;
}

int list_char_remove(list_char *container, char value)
{
  list_char_node *curr = container->begin;

  while (curr != NULL && curr->value != value)
  {
    curr = curr->next;
  }

  if (curr != NULL)
  {
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    free(curr);
    curr = NULL;

    return 1;
  }

  return 0;
}

list_char_node *list_char_find(list_char *container, char value)
{
  list_char_node *curr = container->begin;

  while (curr != NULL && curr->value != value)
  {
    curr = curr->next;
  }

  return curr;
}

void list_char_pprint(list_char *container, const char *separator)
{
  list_char_node *begin = container->begin;

  while (begin != NULL)
  {
    printf("%c%s", begin->value, separator);
    begin = begin->next;
  }
  printf("\n");
}

#endif
