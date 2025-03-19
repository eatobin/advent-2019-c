#include <string.h>

int candidates[120][5];
int currentPerm = 0;

void addAPerm(int perm[5]) {
    memcpy(candidates[currentPerm], perm, 5 * sizeof(int));
    currentPerm++;
}

void swap(int *x, int *y) {
    const int temp = *x;
    *x = *y;
    *y = temp;
}

void permutations(const int k, int A[]) {
    if (k == 1) {
        addAPerm(A);
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
    int A[] = {1, 2, 3, 4, 5};
    const int len = sizeof(A) / sizeof(A[0]);
    permutations(len, A);
    return 0;
}