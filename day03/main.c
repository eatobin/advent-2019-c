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

//#include <malloc.h>
//
//int *myFunction() {
//    int *ptr;
//    ptr = malloc(sizeof(*ptr) * 3);
//    *ptr = 67;
//    *(ptr + 1) = 68;
//    printf("Hi! %d\n", *ptr);
//    printf("Hi again! %p\n", ptr);
//    printf("HiXX! %d\n", *(ptr + 1));
//    printf("Hi againP! %p\n", ptr + 1);
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
//    printf("Last one-not really! %d\n", *(ptrAddress + 1));
//    printf("The function has ended\n");
//    free(ptrAddress);
//    ptrAddress = NULL;
//    return 0;
//}

//#include <malloc.h>
//
//char *myFunction() {
//    char *ptr;
//    ptr = malloc(sizeof(char) * 3);
//    *(ptr + 0) = 60;
//    *(ptr + 1) = 61;
//    *(ptr + 2) = 62;
//    return ptr;
//}
//
//int main() {
//    char *ptrAddress;
//    ptrAddress = myFunction();
//    for (char i = 0; i < 3; ++i) {
//        printf("Contents: %d\n", *(ptrAddress + i));
//        printf("Address: %p\n", ptrAddress + i);
//    }
//    *(ptrAddress + 0) = *(ptrAddress + 0) * 2;
//    *(ptrAddress + 2) = *(ptrAddress + 2) * 2;
//    printf("0 times 2: %d\n", *(ptrAddress + 0));
//    printf("2 times 2: %d\n", *(ptrAddress + 2));
//    free(ptrAddress);
//    ptrAddress = NULL;
//    return 0;
//}

//#include <malloc.h>
//
//char *myFunction() {
//    char *ptr;
//    ptr = malloc(sizeof(char) * 4);
//    *(ptr + 0) = 78;
//    *(ptr + 1) = 111;
//    *(ptr + 2) = 0;
//    *(ptr + 3) = 0;
//    return ptr;
//}
//
//int main() {
//    char *ptrAddress;
//    ptrAddress = myFunction();
//    for (char i = 0; i < 4; ++i) {
//        printf("Contents: %c\n", *(ptrAddress + i));
//        printf("Address: %p\n", ptrAddress + i);
//    }
//    puts(ptrAddress);
//    printf("Again: %s\n", ptrAddress);
//    *(ptrAddress + 0) = 89;
//    *(ptrAddress + 1) = 101;
//    *(ptrAddress + 2) = 115;
//    for (char i = 0; i < 4; ++i) {
//        printf("Contents: %c\n", *(ptrAddress + i));
//        printf("Address: %p\n", ptrAddress + i);
//    }
//    puts(ptrAddress);
//    printf("Again: %s\n", ptrAddress);
//    for (char i = 0; i < 4; ++i) {
//        printf("Contents: %d\n", *(ptrAddress + i));
//        printf("Address: %p\n", ptrAddress + i);
//    }
//    free(ptrAddress);
//    ptrAddress = NULL;
//    return 0;
//}

//#include <malloc.h>
//
//double *myFunction() {
//    double *ptr;
//    ptr = malloc(sizeof(double) * 3);
//    *(ptr + 0) = 60.0;
//    *(ptr + 1) = 61.1;
//    *(ptr + 2) = 62.2;
//    return ptr;
//}
//
//int main() {
//    double *ptrAddress;
//    ptrAddress = myFunction();
//    for (char i = 0; i < 3; ++i) {
//        printf("Contents: %lf\n", *(ptrAddress + i));
//        printf("Address: %p\n", ptrAddress + i);
//    }
//    *(ptrAddress + 0) = *(ptrAddress + 0) * 2;
//    *(ptrAddress + 2) = *(ptrAddress + 2) * 2;
//    printf("0 times 2: %lf\n", *(ptrAddress + 0));
//    printf("2 times 2: %lf\n", *(ptrAddress + 2));
//    free(ptrAddress);
//    ptrAddress = NULL;
//    return 0;
//}

#include <malloc.h>

struct MyStructure {
    int myNum;
    char myChar;
    char *myThreeLetterWord;
};

struct MyStructure *myFunction() {
    char *threeLetterString1;
    char *threeLetterString2;

    threeLetterString1 = malloc(sizeof(char) * 4);
    *(threeLetterString1 + 0) = 89;
    *(threeLetterString1 + 1) = 101;
    *(threeLetterString1 + 2) = 115;
    *(threeLetterString1 + 3) = 0;

    threeLetterString2 = malloc(sizeof(char) * 4);
    *(threeLetterString2 + 0) = 84;
    *(threeLetterString2 + 1) = 105;
    *(threeLetterString2 + 2) = 109;
    *(threeLetterString2 + 3) = 0;

    struct MyStructure *ptr;
    struct MyStructure s0;
    s0.myNum = 0;
    s0.myChar = 'a';
    s0.myThreeLetterWord = threeLetterString1;
    struct MyStructure s1;
    s1.myNum = 1;
    s1.myChar = 'b';
    s1.myThreeLetterWord = threeLetterString2;
    ptr = malloc(sizeof(struct MyStructure) * 2);
    *(ptr + 0) = s0;
    *(ptr + 1) = s1;
    return ptr;
}

int main() {
    struct MyStructure *ptrAddress;
    ptrAddress = myFunction();
    for (char i = 0; i < 2; ++i) {
        printf("Contents: %d - %c - %s\n", (ptrAddress + i)->myNum, (ptrAddress + i)->myChar, (ptrAddress + i)->myThreeLetterWord);
        printf("Address: %p\n", ptrAddress + i);
    }
    (ptrAddress + 0)->myNum = 111;
    (ptrAddress + 1)->myChar = 'z';
    (ptrAddress + 0)->myThreeLetterWord[0] = 89;
    (ptrAddress + 0)->myThreeLetterWord[1] = 111;
    (ptrAddress + 0)->myThreeLetterWord[2] = 117;
    (ptrAddress + 1)->myThreeLetterWord[0] = 72;
    for (char i = 0; i < 2; ++i) {
        printf("Contents2: %d - %c - %s\n", (ptrAddress + i)->myNum, (ptrAddress + i)->myChar, (ptrAddress + i)->myThreeLetterWord);
        printf("Address2: %p\n", ptrAddress + i);
    }
    free(ptrAddress->myThreeLetterWord);
    ptrAddress->myThreeLetterWord = NULL;
    free(ptrAddress);
    ptrAddress = NULL;
    return 0;
}
