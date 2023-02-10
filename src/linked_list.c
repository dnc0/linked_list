/*
linked_list.c
Marlon Soares marlonslbr@gmail.com
2022
*/
//======= includes =======
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "liblinklist.h"
//======= defines =======
#define VERSION "0.1"
//======= functions prototypes ======= 
void dump(Node *n);
//======= start execution ======= 
int main(int argc,char *argv[]){
	NodeList *list = newList(NULL);
	if (list == NULL){
		perror("newList");
		exit(1);
	}
	for (int i=0; i<4; i++){
		char *s = calloc(sizeof(char),50);
		if (s == NULL){
			perror("calloc");
			exit(1);
		}
		sprintf(s,"data%d",i);
		if (insertList(list,s) == NULL){
			perror("insertList");
			exit(1);
		}
	}
	Node *n = removeFirst(list);
	while (n != NULL){
		dump(n);
		free(n->item);
		freeNode(n);
		n = removeFirst(list);
	}
}
//======= functions ======= 
void dump(Node *n){
	if (n == NULL){
		return;
	}
	printf("-> %s\n",(char*) n->item);
}
