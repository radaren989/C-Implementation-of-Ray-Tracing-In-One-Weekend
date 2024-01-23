#include <stdlib.h>
#include <stdio.h>
#include "list.h"

struct node *createNode(void *data)
{
  struct node *newNode = NULL;
  newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL)
  {
    fprintf(stderr, "Memmory allocaiton error!\n");
    exit(EXIT_FAILURE);
  }
  newNode->ptr = data;
  newNode->next = NULL;

  return newNode;
}

void insertAtBeginning(struct node **head, void *data)
{
  struct node *newNode = createNode(data);
  newNode->next = *head;
  *head = newNode;
  return;
}

void freelist(struct node *head)
{
  struct node *current = head;
  while (current != NULL)
  {
    struct node *next = current->next;
    free(current);
    current = next;
  }
}