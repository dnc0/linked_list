#ifndef LIBLINKLIST_H
#define LIBLINKLIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
	void *item;
	struct Node *next;
	int _din;
};
typedef struct Node Node;

typedef struct {
	size_t count;
	Node *head;
	Node *tail;
	int _din;
} NodeList;

/* functions */
Node *newNode(void *data);
void freeNode(Node *node);
NodeList *newList(Node *node);
void freeList(NodeList *list);
Node *appendList(NodeList *list,Node *node);
Node *insertList(NodeList *list,void *item);
Node *removeLast(NodeList *list);
Node *removeFirst(NodeList *list);
#endif
