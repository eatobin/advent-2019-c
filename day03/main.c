//#include <malloc.h>
//
//void myFunction() {
//    int *ptr;
//    ptr = malloc(sizeof(*ptr));
//    *ptr = 67;
//    printf("Hi! %d\n", *ptr);
//    printf("Hi again! %p\n", ptr);
//    free(ptr);
//    ptr = NULL;
//}
//
//int main() {
//    myFunction();
//    printf("The function has ended");
//    return 0;
//}

//#include <malloc.h>
//
//int *myFunction() {
//    int *ptr;
//    ptr = malloc(sizeof(*ptr));
//    *ptr = 67;
//    printf("Hi! %d\n", *ptr);
//    printf("Hi again! %p\n", ptr);
//    return ptr;
//}
//
//int main() {
//    int *ptrAddress;
//    ptrAddress = myFunction();
//    printf("Hi #3! %d\n", *ptrAddress);
//    printf("Hi again#4! %p\n", ptrAddress);
//    *ptrAddress = *ptrAddress * 20;
//    printf("Last one! %d\n", *ptrAddress);
//    printf("The function has ended\n");
//    free(ptrAddress);
//    ptrAddress = NULL;
//    return 0;
//}

#include <malloc.h>

int *myFunction() {
    int *ptr;
    ptr = malloc(sizeof(*ptr) * 3);
    *ptr = 67;
    *(ptr + 1) = 68;
    printf("Hi! %d\n", *ptr);
    printf("Hi again! %p\n", ptr);
    printf("HiXX! %d\n", *(ptr + 1));
    printf("Hi againP! %p\n", ptr + 1);
    return ptr;
}

int main() {
    int *ptrAddress;
    ptrAddress = myFunction();
    printf("Hi #3! %d\n", *ptrAddress);
    printf("Hi again#4! %p\n", ptrAddress);
    *ptrAddress = *ptrAddress * 20;
    printf("Last one! %d\n", *ptrAddress);
    printf("Last one-not really! %d\n", *(ptrAddress + 1));
    printf("The function has ended\n");
    free(ptrAddress);
    ptrAddress = NULL;
    return 0;
}
