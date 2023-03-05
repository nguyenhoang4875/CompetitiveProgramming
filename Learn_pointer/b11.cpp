#include <bits/stdc++.h>
using namespace std;

// Pointers as function returns

int addByValue(int a, int b) { // Called function by value
    printf("Address of a in add call by value: %d\n", &a);
    int sum = a + b;
    return sum;
}

void printHelloWord() {
    printf("Hello world\n");
}

int *addByRef(int *a, int *b, int *sum) { // Called function - returns pointer to integer
    printf("Address of a in add call by reference: %d\n", &a);
    sum = (int*) malloc(sizeof(int)); // save to heap
    *sum = *a + *b;
    return sum;
}

// int addByRef(int &a, int &b) { // Called function - returns pointer to integer
//     printf("Address of a in add call by reference: %d\n", &a);
//     int sum = a + b;
//     return sum;
// }

// called function - return val
/* int addByRef(int *a, int *b) { // Called function - returns pointer to integer
    printf("Address of a in add call by reference: %d\n", &a);
    int sum = *a + *b;
    return sum;
} */


int main() { // calling function
    int a = 2, b = 4;
    printf("Address of a in main: %d\n", &a);
    // call by value
    int c = addByValue(a, b); 
    // int d = addByRef(a, b);
    int *sum;
    addByRef(&a, &b, sum);
    printf("Sum by value = %d\n", c);
    printHelloWord();
    printf("Sum by reference = %d\n", *sum);

    return 0;
}
