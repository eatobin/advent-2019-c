#include <malloc.h>

void myFunction() {
    int *ptr;
    ptr = malloc(sizeof(*ptr));
    *ptr = 67;
    printf("Hi! %d\n", *ptr);
    printf("Hi again! %p\n", ptr);
    free(ptr);
    ptr = NULL;
}

int main() {
    myFunction();
    printf("The function has ended");
    return 0;
}
