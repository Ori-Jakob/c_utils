#include "DynamicArray.h"


DynamicArray* dynamicArrayConstructor(int size, TYPE T) {
	if (size < 0) {
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

	return d;
}


void* get(DynamicArray* d, int position) {
	if (d == NULL || position < 0 || position >= d->size) {
		printf("ERROR: Invalid range or array was null.\n");
		return NULL;
	}
	return (char*)d->data + (position * d->typeSize);
}


void push(DynamicArray* d, void* data) {
	if (d->size == d->capacity) {
		if (resize(d) == false) return;
	}

	memcpy((char*)d->data + (d->size++ * d->typeSize), data, d->typeSize);
}


void pop(DynamicArray* d) {

	if (d == NULL || d->size == 0) {
		printf("ERROR: Cannot pop from an empty or null array.\n");
		return;
	}

	d->size--;
}


bool resize(DynamicArray* d) {
	d->capacity *= 2;

	void* data = calloc(d->capacity, d->typeSize);
	if (data == NULL) {
		printf("ERROR: Memory allocation failed during resize.\n");
		return false;
	}

	memcpy(data, d->data, (d->size * d->typeSize));

	free(d->data);
	d->data = data;

	return true;
}


void freeDynamicArray(DynamicArray* d) {

	free(d->data);
	free(d);
	d = NULL;
}


char* toString(DynamicArray* d) {
	return "TEST";
}