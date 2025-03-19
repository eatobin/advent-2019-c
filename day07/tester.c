#include <stdio.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void pemutations(int k, int A[]) {
    if (k == 1) {
        printf("Array element: ");
        for (int i = 0; i < 3; i++) {
            printf("%d ", A[i]);
        }
        printf("\n");
    } else {
        for (int i = 0; i < k - 1; ++i) {
            pemutations(k - 1, A);
            if (k % 2 == 0) {
                swap(&A[i], &A[k - 1]);
            } else {
                swap(&A[0], &A[k - 1]);
            }
        }
        pemutations(k - 1, A);
    }
}

int main() {
    int A[] = {1, 2, 3};
    int len = sizeof(A) / sizeof(A[0]);
    pemutations(len, A);
    return 0;
}
