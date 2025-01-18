#include "DynamicArray.h"


DynamicArray* dynamicArrayConstructor(int size, TYPE T) {
	if (size < 1) {
		printf("ERROR: Size cannot be less than 1");
		return;
	}

	DynamicArray *d = (DynamicArray*)calloc(1, sizeof(DynamicArray));
	if (d == NULL) {
		printf("ERROR: Could not create dynamic array on the heap;\n");
		return;
	}

	d->size = 0;
	d->capacity = size;
	d->T = T;

	switch (d->T) {
		case CHAR:
			d->typeSize = sizeof(char);
			break;
		case INT:
			d->typeSize = sizeof(int);			
			break;
		case LONG:
			d->typeSize = sizeof(long long);
			break;
		case FLOAT:
			d->typeSize = sizeof(float);
			break;
		case DOUBLE:
			d->typeSize = sizeof(double);
			break;
	}

	d->data = calloc(size, d->typeSize);
	d->get = get_element;
	d->pop = pop_element;
	d->push = push_element;
	d->set = set_element;
	d->toString = toString;


	return d;
}

void dynamicArrayDeconstuctor(DynamicArray* d) {

	free(d->data);
	free(d);
	d = NULL;
}