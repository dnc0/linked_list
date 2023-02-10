#include "liblinklist.h"

Node *newNode(void *data){
	Node *new = calloc(sizeof(Node),1);
	if (new == NULL){
		return NULL;
	}
	new->_din = 1;
	new->item = data;
	return new;
}
void freeNode(Node *node){
	if (node->_din) {
		free(node);
		node = NULL;
	}
}
NodeList *newList(Node *node){
	NodeList *new = calloc(sizeof(NodeList),1);
	if (new == NULL){
		return NULL;
	}
	new->_din = 1;
	if (node != NULL){
		new->head = node;
		new->count = 1;
	}
	return new;
}
void freeList(NodeList *list){
	if (list->_din){
		free(list);
		list = NULL;
	}
}
Node *insertList(NodeList *list,void *item){
	Node *node = newNode(item);
	if (node == NULL){
		return NULL;
	}
	Node *r = appendList(list,node);
	if (r == NULL){
		freeNode(node);
		return NULL;
	}
	return r;
}
Node *appendList(NodeList *list,Node *node){
	if (list->count >= 1){
		Node *last = list->tail;
		last->next = node;
		list->tail = node;
	}else{
		list->head = node;
		list->tail = node;
	}
	list->count++;
	return node;	
}
Node *removeLast(NodeList *list){
	Node *curr = list->head;
	Node *prev = NULL;
	while (curr->next != NULL){
		prev = curr;
		curr = curr->next;
	}
	prev->next = NULL;
	list->count--;
	return prev;
}
Node *removeFirst(NodeList *list){
	if (list->count == 0){
		return NULL;
	}
	Node *first = list->head;
	list->head = first->next;
	list->count--;
	return first;
}
