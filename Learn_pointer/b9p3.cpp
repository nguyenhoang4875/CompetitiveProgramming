#include <bits/stdc++.h>
using namespace std;

// Pointers and multiple-dimensional arrays
// Three dimensional array

void funcA(int *A) { // or int A[] argument for 1-D array of integer
    printf("functionA: address of array A = %d \n", A);
}
void funcB(int (*B)[3]) { // or int B[][] argument for 2-D array of integer
    printf("functionA: address of array B = %d \n", B);

}
void funcC(int (*C)[2][2]) { // or int C[][][] argument for 3-D array of integer
    printf("functionA: address of array C = %d \n", C);

}

int main() {
    int a[2] = {1, 2};
    int c[3][2][2] = {{{2, 5}, {7, 9}}, {{3, 4}, {6, 1}}, {{0, 8}, {11, 13}}};
    int b[2][3] = {{2, 4, 6}, {3, 5, 7}};
    funcA(a);
    funcB(b);
    funcC(c);

    return 0;
}