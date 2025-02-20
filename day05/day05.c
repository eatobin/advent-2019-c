// C Program to return an array in C using Pointers
#include <stdio.h>
#include <stdlib.h>

int *createArray(int size);
int *doubleArray(int *array, int size);

int main() {
    // Define the size of the array
    const int size = 5;
    // Call the function to create the array and store the
    // returned pointer
    int *myArray = createArray(size);

    // Print the elements of the array
    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {

        printf("%d ", myArray[i]);
    }
    printf("\n");

    myArray[0] = 12;

    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {

        printf("%d ", myArray[i]);
    }
    printf("\n");

    myArray = doubleArray(myArray, size);

    printf("Array Elements: ");
    for (int i = 0; i < size; i++) {

        printf("%d ", myArray[i]);
    }
    printf("\n");

    // Free the allocated memory to avoid memory leaks
    free(myArray);

    return 0;
}

// Function to create and return an array using dynamic
// memory allocation
int *createArray(const int size) {
    // Allocate memory for the array
    int *array = malloc(size * sizeof(int));

    // Check if memory allocation was successful
    if (array == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);// Exit the program if allocation fails
    }

    // Initialize the array with example values
    for (int i = 0; i < size; i++) {
        array[i] = i * 2;
    }

    // Return the pointer to the allocated array
    return array;
}

int *doubleArray(int *array, const int size) {
    for (int i = 0; i < size; i++) {
        array[i] = array[i] * 2;
    }
    return array;
}
