#pragma once

struct node
{
  void *ptr;
  struct node *next;
};

struct node *createNode(void *data);
void insertAtBeginning(struct node **head, void *data);
void freelist(struct node *head);