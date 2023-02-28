#include <bits/stdc++.h>
using namespace std;

// Arrays as function argument

int sumOfElements(int *A, int size) { // *A same with A[]
    int sum = 0;
    printf("SOE- Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));
    for (int i = 0; i < size; i++) {
        sum+= A[i];

    }
    return sum;
}

void multipleTwo(int *A, int size)  {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        A[i] *= 2;
    }
}


int main() {
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A) / sizeof(A[0]);
    int total = sumOfElements(A, size);
    printf("Sum of elements = %d\n", total);
    printf("Main - Size of A = %d, size of A[0] = %d\n", sizeof(A), sizeof(A[0]));
    multipleTwo(A, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }

    return 0;
}