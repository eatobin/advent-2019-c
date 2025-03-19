#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int index1 = 1;
    int index2 = 3;

    printf("Array before swap: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    swap(&arr[index1], &arr[index2]);

    printf("Array after swap: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
