#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

typedef enum {
	CHAR,
	INT,
	LONG,
	FLOAT,
	DOUBLE
}TYPE;

typedef struct DynamicArray 
{
	void *data;
	int size;
	int capacity;
	TYPE T;
	char typeSize;

	void (*push)(struct DynamicArray*, void*);
	void (*pop)(struct DynamicArray*);
	int (*set)(struct DynamicArray*, int);
	void * (*get)(struct DynamicArray*, int);
	char* (*toString)(struct DynamicArray*);
}DynamicArray;

DynamicArray* dynamicArrayConstructor(int, TYPE);
void dynamicArrayDeconstuctor(DynamicArray*);
static char* toString(DynamicArray*);
static void* get_element(DynamicArray*, int);
static void push_element(DynamicArray*, void*);
static void pop_element(DynamicArray*);
static int set_element(DynamicArray*, int, void*);
static int resize(DynamicArray*);



static void* get_element(DynamicArray* d, int position) {
	if (d == NULL || position < 0 || position >= d->size) {
		printf("ERROR: Invalid range or array was null.\n");
		return NULL;
	}
	return (char*)d->data + (position * d->typeSize);
}


static void push_element(DynamicArray* d, void* data) {
	if (d->size == d->capacity) {
		if (resize(d) == -1) return;
	}

	memcpy((char*)d->data + (d->size++ * d->typeSize), data, d->typeSize);
}


static void pop_element(DynamicArray* d) {

	if (d == NULL || d->size == 0) {
		printf("ERROR: Cannot pop from an empty or null array.\n");
		return;
	}

	d->size--;
}

static int set_element(DynamicArray* d, int position, void* data) {
	if (d == NULL || position < 0 || position >= d->capacity) {
		printf("ERROR: Trying to set an invalid position in the array.");
		return -1;
	}
	memcpy((char*)d->data + (position * d->typeSize), data, d->typeSize);
	return 0;
}


static int resize(DynamicArray* d) {
	d->capacity *= 2;

	void* data = calloc(d->capacity, d->typeSize);
	if (data == NULL) {
		printf("ERROR: Memory allocation failed during resize.\n");
		return -1;
	}

	memcpy(data, d->data, (d->size * d->typeSize));

	free(d->data);
	d->data = data;

	return 0;
}


static char* toString(DynamicArray* d) {
	if (d == NULL || d->data == NULL) {
		return _strdup("DynamicArray is NULL or uninitialized.");
	}

	size_t bufferSize = d->size * 20 + 3;
	char* result = (char*)calloc(1, bufferSize);
	if (result == NULL) {
		return _strdup("Memory allocation failed.");
	}

	char* str = result;
	*str++ = '[';


	for (int i = 0; i < d->size; i++) {
		switch (d->T) {
		case CHAR:
			str += snprintf(str, bufferSize - (str - result), "'%c'", *(char*)((char*)d->data + i * d->typeSize));
			break;
		case INT:
			str += snprintf(str, bufferSize - (str - result), "%d", *(int*)((char*)d->data + i * d->typeSize));
			break;
		case LONG:
			str += snprintf(str, bufferSize - (str - result), "%lld", *(long long*)((char*)d->data + i * d->typeSize));
			break;
		case FLOAT:
			str += snprintf(str, bufferSize - (str - result), "%.2f", *(float*)((char*)d->data + i * d->typeSize));
			break;
		case DOUBLE:
			str += snprintf(str, bufferSize - (str - result), "%.2lf", *(double*)((char*)d->data + i * d->typeSize));
			break;
		}

		if (i < d->size - 1) {
			*str++ = ',';
			*str++ = ' ';
		}
	}

	*str++ = ']';
	*str = '\0';

	return result;
}