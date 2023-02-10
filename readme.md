# linked_list
A simple library for using linked lists in C.

## Structure
An item is represented by a node instance and can point to any data.
``` struct Node{
	void *item; /* pointer to you data */
	struct Node *next;
	int _din;
};
```
The ``_din`` member indicates that a node is dynamically allocated should be freed.

To hold a varibable number of nodes a node list struct is used.
```
typedef struct {
	size_t count;
	Node *head;
	Node *tail;
	int _din;
} NodeList;
```
The ``_din`` member indicates that a node list is dynamically allocated should be freed.


## Available functions
Node *newNode(void *data);
void freeNode(Node *node);
NodeList *newList(Node *node);
void freeList(NodeList *list);
Node *appendList(NodeList *list,Node *node);
Node *insertList(NodeList *list,void *item);
Node *removeLast(NodeList *list);
Node *removeFirst(NodeList *list);
### newNode
Create a node instance that point to data.
### freeNode
Remove a node instance.
### newList
Create a node list instance that contain a list of nodes.
The parameter ``node`` is opcional and can be NULL.
### freeList
Remove a node list instance.
### appendList
Add to node list a new node previous created.
### insertList
Add to node list a new node.
### removeLast
Remove the last node added to node list.
### removeFirst
Remove the first node added to node list.

## Contributing
Report any errors to marlonslbr@gmail.com

## License
MIT Licence
