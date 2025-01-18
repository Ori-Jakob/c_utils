#pragma once
#include "Node.h"

typedef struct LinkedList {
	Node* head;
	Node* tail;
	int length;
}LinkedList;

LinkedList linkedListConstructor();
void linkedListDeconstructor(LinkedList*);