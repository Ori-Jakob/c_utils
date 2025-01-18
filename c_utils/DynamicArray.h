#pragma once
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

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
}DynamicArray;

DynamicArray* dynamicArrayConstructor(int, TYPE);
void freeDynamicArray(DynamicArray*);
char* toString(DynamicArray*);
void* get(DynamicArray*, int);
void push(DynamicArray*, void*);
void pop(DynamicArray*);
bool resize(DynamicArray*);