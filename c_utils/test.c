#include "DynamicArray.h"


int charTest() {
    printf("=== Dynamic Array String Tests ===\n");

    //Create
    printf("1. Creating dynamic array for characters...\n");
    DynamicArray* charArray = dynamicArrayConstructor(5, CHAR);
    if (charArray == NULL) {
        printf("ERROR: Failed to create dynamic array for characters.\n");
        return -1;
    }
    printf("Dynamic array created with initial capacity %d.\n", charArray->capacity);

    //Push
    printf("\n2. Adding characters to the array...\n");
    char* testString = "hello";
    for (int i = 0; i < strlen(testString); i++) {
        push_element(charArray, &testString[i]);
        printf("Added: %c\n", *(char*)get_element(charArray, i));
    }

    //Add
    printf("\n3. Adding more characters to trigger resize...\n");
    char additionalChars[] = " world!";
    for (int i = 0; i < strlen(additionalChars); i++) {
        push_element(charArray, &additionalChars[i]);
    }

    printf("Array contents after adding: ");
    for (int i = 0; i < charArray->size; i++) {
        printf("%c", *(char*)get_element(charArray, i));
    }
    printf("\nNew capacity after resize: %d\n", charArray->capacity);

    //Pop
    printf("\n4. Popping characters from the array...\n");
    for (int i = 0; i < 3; i++) {
        pop_element(charArray);
    }

    printf("Array contents after popping: ");
    for (int i = 0; i < charArray->size; i++) {
        printf("%c", *(char*)get_element(charArray, i));
    }
    printf("\nArray size after popping: %d\n", charArray->size);

    //Free
    printf("\n5. Freeing the dynamic array...\n");
    dynamicArrayDeconstuctor(charArray);
    printf("Dynamic array freed successfully.\n");

    return 1;
}

int intTest() {
    printf("=== Dynamic Array Tests ===\n");

    //Create
    printf("1. Creating dynamic array...\n");
    DynamicArray* d = dynamicArrayConstructor(2, INT);
    if (d == NULL) {
        printf("ERROR: Failed to create dynamic array.\n");
        return -1;
    }
    printf("Dynamic array created with initial capacity %d.\n", d->capacity);

    //Push
    int a = 10, b = 20, c = 30;
    printf("\n2. Adding elements...\n");
    push_element(d, &a);
    push_element(d, &b);
    printf("Added: %d, %d\n", *(int*)get_element(d, 0), *(int*)get_element(d, 1));

    //Test
    printf("\n3. Adding an element to trigger resize...\n");
    push_element(d, &c);
    printf("Added: %d\n", *(int*)get_element(d, 2));
    printf("New capacity after resize: %d\n", d->capacity);

    //Access
    printf("\n4. Accessing all elements...\n");
    for (int i = 0; i < d->size; i++) {
        printf("Element %d: %d\n", i, *(int*)get_element(d, i));
    }

    //Pop
    printf("\n5. Popping an element...\n");
    pop_element(d);
    printf("Array size after pop: %d\n", d->size);
    for (int i = 0; i < d->size; i++) {
        printf("Element %d: %d\n", i, *(int*)get_element(d, i));
    }

    //Test
    printf("\n6. Testing pop on an empty array...\n");
    pop_element(d);
    pop_element(d);
    pop_element(d); // Should print an error message

    //Free
    printf("\n7. Freeing the dynamic array...\n");
    dynamicArrayDeconstuctor(d);
    printf("Dynamic array freed successfully.\n");

    return 1;
}