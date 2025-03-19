#include <stdio.h>
#include <string.h>

int candidates[6][3];
int currentPerm = 0;

void addAPerm(int perm[3]) {
    memcpy(candidates[currentPerm], perm, 3 * sizeof(int));
    currentPerm++;
}

void swap(int *x, int *y) {
    const int temp = *x;
    *x = *y;
    *y = temp;
}

// Funtion that takes 2d array as parameter
void print(int arr[6][3]) {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
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
    int A[] = {1, 2, 3};
    const int len = sizeof(A) / sizeof(A[0]);
    permutations(len, A);
    print(candidates);

    return 0;
}

// #include <stdio.h>
// #include <string.h>

// int main() {
//     int arr1[] = {1, 2, 3, 4, 5};
//     int n = sizeof(arr1) / sizeof(arr1[0]);
//     int arr2[n];

//     // Use memcpy to copy arr1 to arr2
//     memcpy(arr2, arr1, n * sizeof(arr1[0]));

//     for (int i = 0; i < n; i++)
//         printf("%d ", arr2[i]);
//     return 0;
// }

// #include <stdio.h>


// int main() {
//     int arr[3][3] = {{1, 2, 3},
//                      {40, 50, 60},
//                      {700, 800, 900}};

//     // Passing the array along with the
//     // size of rows and columns
//     // print(arr, 3, 3);
//     addAPerm(arr[0]);
//     addAPerm(arr[1]);
//     addAPerm(arr[2]);
//     print(candidates, 3, 3);

//     return 0;
// }
