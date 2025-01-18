#include "DynamicArray.h"


int charTest() {
    printf("=== Dynamic Array String Tests ===\n");

    // 1. Create a dynamic array for characters
    printf("1. Creating dynamic array for characters...\n");
    DynamicArray* charArray = dynamicArrayConstructor(5, CHAR);
    if (charArray == NULL) {
        printf("ERROR: Failed to create dynamic array for characters.\n");
        return -1;
    }
    printf("Dynamic array created with initial capacity %d.\n", charArray->capacity);

    // 2. Push strings into the array one character at a time
    printf("\n2. Adding characters to the array...\n");
    char* testString = "hello";
    for (int i = 0; i < strlen(testString); i++) {
        push(charArray, &testString[i]);
        printf("Added: %c\n", *(char*)get(charArray, i));
    }

    // 3. Add more characters to trigger resizing
    printf("\n3. Adding more characters to trigger resize...\n");
    char additionalChars[] = " world!";
    for (int i = 0; i < strlen(additionalChars); i++) {
        push(charArray, &additionalChars[i]);
    }

    printf("Array contents after adding: ");
    for (int i = 0; i < charArray->size; i++) {
        printf("%c", *(char*)get(charArray, i));
    }
    printf("\nNew capacity after resize: %d\n", charArray->capacity);

    // 4. Pop characters and print the array
    printf("\n4. Popping characters from the array...\n");
    for (int i = 0; i < 3; i++) {
        pop(charArray);
    }

    printf("Array contents after popping: ");
    for (int i = 0; i < charArray->size; i++) {
        printf("%c", *(char*)get(charArray, i));
    }
    printf("\nArray size after popping: %d\n", charArray->size);

    // 5. Free the dynamic array
    printf("\n5. Freeing the dynamic array...\n");
    freeDynamicArray(charArray);
    printf("Dynamic array freed successfully.\n");

    return 1;
}

int intTest() {
    printf("=== Dynamic Array Tests ===\n");

    // 1. Create a dynamic array for integers
    printf("1. Creating dynamic array...\n");
    DynamicArray* d = dynamicArrayConstructor(2, INT);
    if (d == NULL) {
        printf("ERROR: Failed to create dynamic array.\n");
        return -1;
    }
    printf("Dynamic array created with initial capacity %d.\n", d->capacity);

    // 2. Push elements into the array
    int a = 10, b = 20, c = 30;
    printf("\n2. Adding elements...\n");
    push(d, &a);
    push(d, &b);
    printf("Added: %d, %d\n", *(int*)get(d, 0), *(int*)get(d, 1));

    // 3. Test resizing by adding more elements
    printf("\n3. Adding an element to trigger resize...\n");
    push(d, &c);
    printf("Added: %d\n", *(int*)get(d, 2));
    printf("New capacity after resize: %d\n", d->capacity);

    // 4. Access all elements
    printf("\n4. Accessing all elements...\n");
    for (int i = 0; i < d->size; i++) {
        printf("Element %d: %d\n", i, *(int*)get(d, i));
    }

    // 5. Pop elements
    printf("\n5. Popping an element...\n");
    pop(d);
    printf("Array size after pop: %d\n", d->size);
    for (int i = 0; i < d->size; i++) {
        printf("Element %d: %d\n", i, *(int*)get(d, i));
    }

    // 6. Test pop on empty array
    printf("\n6. Testing pop on an empty array...\n");
    pop(d);
    pop(d); // Pops remaining elements
    pop(d); // Should print an error message

    // 7. Free the dynamic array
    printf("\n7. Freeing the dynamic array...\n");
    freeDynamicArray(d);
    printf("Dynamic array freed successfully.\n");

    return 1;
}