#include <bits/stdc++.h>
using namespace std;

// Pointer and arrays


int main() {
    int a[5];
    int *p, *q;
    p = a;
    printf("Address of a: %d\n",a);
    // int *q;
    q = &a[0];
    printf("Address of a[0]: %d\n",a);

    int A[] = {2, 4, 5, 8, 1};
    int i;
    int *pp = A;
    printf("Address of array a: %d\n", &A);
    pp+=5;
    printf("Address of array a: %d\n", &A);
    
    for (int i = 0; i < 5; i++) {
        printf("%d\n", &A[i]);
        printf("%d\n", A + i);
        printf("%d\n", A[i]);
        printf("%d\n", *(A + i));
    }

    return 0;
}