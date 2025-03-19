#include <stdio.h>

void swap(int *x, int *y) {
    const int temp = *x;
    *x = *y;
    *y = temp;
}

void permutations(const int k, int A[]) {
    if (k == 1) {
        printf("Array element: ");
        for (int i = 0; i < 3; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < k - 1; i++) {
            permutations(k - 1, A);
            if (k % 2 == 0) {
                swap(&A[i], &A[k - 1]);
            } else {
                swap(&A[0], &A[k - 1]);
            }
        }
        permutations(k - 1, A);
    }
}

int main() {
    int A[] = {1, 2, 3};
    const int len = sizeof(A) / sizeof(A[0]);
    permutations(len, A);
    return 0;
}
