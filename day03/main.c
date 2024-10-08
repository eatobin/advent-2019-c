//#include <malloc.h>
//
//void myFunction() {
//    int *ptr;
//    ptr = (int *) malloc(sizeof(int));
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
//    ptr = (int *) malloc(sizeof(int));
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
//    ptr = (int *) malloc(sizeof(int) * 3);
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
//    ptr = (char *) (char *) malloc(sizeof(char) * 3);
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
//    ptr = (char *) malloc(sizeof(char) * 4);
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
//    ptr = (double *) malloc(sizeof(double) * 4);
//    *(ptr + 0) = 60.0;
//    *(ptr + 1) = 61.1;
//    *(ptr + 2) = 62.2;
//    *(ptr + 3) = 63.3;
//    return ptr;
//}
//
//int main() {
//    double *ptrAddress;
//    ptrAddress = myFunction();
//    for (char i = 0; i < 4; ++i) {
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

//#include <malloc.h>
//
//struct MyStructure {
//    int myNum;
//    char myChar;
//    char *myThreeLetterWord;
//};
//
//struct MyStructure *myFunction() {
//    char *threeLetterString1;
//    char *threeLetterString2;
//
//    threeLetterString1 = (char *) malloc(sizeof(char) * 4);
//    *(threeLetterString1 + 0) = 89;
//    *(threeLetterString1 + 1) = 101;
//    *(threeLetterString1 + 2) = 115;
//    *(threeLetterString1 + 3) = 0;
//
//    threeLetterString2 = (char *) malloc(sizeof(char) * 4);
//    *(threeLetterString2 + 0) = 84;
//    *(threeLetterString2 + 1) = 105;
//    *(threeLetterString2 + 2) = 109;
//    *(threeLetterString2 + 3) = 0;
//
//    struct MyStructure *ptr;
//    struct MyStructure s0;
//    s0.myNum = 0;
//    s0.myChar = 'a';
//    s0.myThreeLetterWord = threeLetterString1;
//    struct MyStructure s1;
//    s1.myNum = 1;
//    s1.myChar = 'b';
//    s1.myThreeLetterWord = threeLetterString2;
//    ptr = malloc(sizeof(struct MyStructure) * 2);
//    *(ptr + 0) = s0;
//    *(ptr + 1) = s1;
//    return ptr;
//}
//
//int main() {
//    struct MyStructure *ptrAddress;
//    ptrAddress = myFunction();
//    for (char i = 0; i < 2; ++i) {
//        printf("Contents: %d - %c - %s\n", (ptrAddress + i)->myNum, (ptrAddress + i)->myChar, (ptrAddress + i)->myThreeLetterWord);
//        printf("Address: %p\n", ptrAddress + i);
//    }
//    (ptrAddress + 0)->myNum = 111;
//    (ptrAddress + 1)->myChar = 'z';
//    (ptrAddress + 0)->myThreeLetterWord[0] = 89;
//    (ptrAddress + 0)->myThreeLetterWord[1] = 111;
//    (ptrAddress + 0)->myThreeLetterWord[2] = 117;
//    (ptrAddress + 1)->myThreeLetterWord[0] = 72;
//    for (char i = 0; i < 2; ++i) {
//        printf("Contents2: %d - %c - %s\n", (ptrAddress + i)->myNum, (ptrAddress + i)->myChar, (ptrAddress + i)->myThreeLetterWord);
//        printf("Address2: %p\n", ptrAddress + i);
//    }
//    free(ptrAddress->myThreeLetterWord);
//    ptrAddress->myThreeLetterWord = NULL;
//    free(ptrAddress);
//    ptrAddress = NULL;
//    return 0;
//}

//#include <malloc.h>
//#include <string.h>
//
//struct Patient {
//    int number;
//    char *name;
//    char *address;
//    char *birthdate;
//    char gender;
//};
//
//struct Patient *createPatient(int s_number, char *s_name,
//                              char *s_addr, char *s_bd, char c_sex) {
//    struct Patient *patient;
//    patient = (struct Patient *) malloc(sizeof(struct Patient));
//
//    patient->number = s_number;
//    patient->name = strdup(s_name);
//    //    patient->name = malloc(strlen(s_name) + 1);
//    //    strcpy(patient->name, s_name);
//    patient->address = strdup(s_addr);
//    patient->birthdate = strdup(s_bd);
//    patient->gender = c_sex;
//
//    return patient;
//}
//
//int main() {
//    struct Patient *eric;
//    eric = createPatient(67, "Eric", "4910 N Via Velazquez", "none", 'M');
//    printf("Contents:\n%d\n%s\n%s\n%s\n%c\n", eric->number, eric->name, eric->address, eric->birthdate, eric->gender);
//    eric->number = 42;
//    eric->name = strdup("This is crazy how long my new name is!!! No overflow??? :-)");
//    eric->birthdate = strdup("11/01/1956");
//    eric->gender = 'F';
//    printf("Contents:\n%d\n%s\n%s\n%s\n%c\n", eric->number, eric->name, eric->address, eric->birthdate, eric->gender);
//    free(eric->name);
//    free(eric->address);
//    free(eric->birthdate);
//    free(eric);
//    return 0;
//}

#include <malloc.h>
#include <string.h>

typedef struct Patient {
    int number;
    char *name;
    char *address;
    char *birthdate;
    char gender;
} doggy;

doggy *createPatient(int s_number, char *s_name,
                     char *s_addr, char *s_bd, char c_sex) {
    doggy *patient;
    patient = (doggy *) malloc(sizeof(doggy));

    patient->number = s_number;
    //    patient->name = strdup(s_name);
    patient->name = (char *) malloc(strlen(s_name) + 1);
    strcpy(patient->name, s_name);
    patient->address = strdup(s_addr);
    patient->birthdate = strdup(s_bd);
    patient->gender = c_sex;

    return patient;
}

int main() {
    struct Patient *eric;
    eric = createPatient(67, "Eric", "4910 N Via Velazquez", "none", 'M');
    printf("Contents:\n%d\n%s\n%s\n%s\n%c\n", eric->number, eric->name, eric->address, eric->birthdate, eric->gender);
    eric->number = 42;
    eric->name = strdup("This is crazy how long my new name is!!! No overflow??? :-)");
    eric->birthdate = strdup("11/01/1956");
    eric->gender = 'F';
    printf("Contents:\n%d\n%s\n%s\n%s\n%c\n", eric->number, eric->name, eric->address, eric->birthdate, eric->gender);
    free(eric->name);
    free(eric->address);
    free(eric->birthdate);
    free(eric);
    return 0;
}

//// C program to demonstrate pointer to pointer
//#include <stdio.h>
//
//int main() {
//    int var = 789;
//
//    // pointer for var
//    int *ptr1;
//
//    // double pointer for ptr1
//    int **ptr2;
//
//    // storing address of var in ptr1
//    ptr1 = &var;
//
//    // Storing address of ptr1 in ptr2
//    ptr2 = &ptr1;
//
//    // Displaying value of var using
//    // both single and double pointers
//    printf("Value of var = %d\n", var);
//    printf("Value of var using single pointer = %d\n", *ptr1);
//    printf("Value of var using double pointer = %d\n\n", **ptr2);
//
//    char *me = "Eric";
//    char **ptr20;
//    ptr20 = &me;
//
//    printf("Value of me - a single pointer to begin with = %s\n", me);
//    printf("Value of me using double pointer = %s\n", *ptr20);
//
//    return 0;
//}
