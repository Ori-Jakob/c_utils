#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct Node {
	void* data;
	struct Node* nextNode;
	struct Node* previousNode;
}Node;


Node nodeConstructor(void*, uint64_t);
void nodeDeconstructor(Node*);