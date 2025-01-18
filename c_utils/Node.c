#include "Node.h";

Node nodeConstructor(void* data, uint64_t size) {

	if (size < 1) {
		printf("ERROR: Invalid size for node.");
		exit(1);
	}

	Node n;

	n.data = calloc(1, size);
	if (n.data == NULL) {
		printf("ERROR: Could not allocate memory for data.");
		exit(1);
	}
	memcpy(n.data, data, size);

	n.nextNode = NULL;
	n.previousNode = NULL;
	

	return n;
}

void nodeDeconstructor(Node* n) {
	free(n->data);
	free(n);
}