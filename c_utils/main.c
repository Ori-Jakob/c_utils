#include <stdio.h>
#include "DynamicArray.h"
#include "tests.h"

int main() {
    // Create a dynamic array for integers
    DynamicArray* intArray = dynamicArrayConstructor(5, INT);
    int values[] = { 10, 20, 30, 40, 50 };
    for (int i = 0; i < 5; i++) {
        intArray->push(intArray, &values[i]);
    }

    // Convert the array to a string
    char* arrayString = intArray->toString(intArray);
    printf("Integer Array: %s\n", arrayString);
    free(arrayString); // Free the string after use

    // Create a dynamic array for characters
    DynamicArray* charArray = dynamicArrayConstructor(5, CHAR);
    char str[] = "hello";
    for (int i = 0; i < strlen(str); i++) {
        charArray->push(charArray, &str[i]);
    }

    // Convert the character array to a string
    char* charArrayString = charArray->toString(charArray);
    printf("Character Array: %s\n", charArrayString);
    free(charArrayString); // Free the string after use

    // Clean up dynamic arrays
    dynamicArrayDeconstuctor(intArray);
    dynamicArrayDeconstuctor(charArray);

    return 0;
	return 1;
}
