#include <malloc.h>

void myFunction() {
    int *ptr;
    ptr = malloc(sizeof(*ptr));
    free(ptr);
    ptr = NULL;
}

int main() {
    myFunction();
    printf("The function has ended");
    return 0;
}
