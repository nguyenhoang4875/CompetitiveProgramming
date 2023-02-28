#include <bits/stdc++.h>
using namespace std;

// Stack vs heap


int main() {
    int n;
    printf("Enter size of array \n");
    scanf("%d", &n);
    // int *a = (int*) malloc(n * sizeof(int)); // dynamic allocated array using malloc, using random value
    int *a = (int*) calloc(n, sizeof(int)); // dynamic allocated array using calloc, fill all value = 0
    for (int i = 0; i < n ; i++) {
        a[i] = i + 1;
    }
    // free(a); // delete the block of a in the heap
    // a= NULL;

    // realloc
    int *b = (int*) realloc(a, 2 * n * sizeof(int));

    // int *a = (int*) realloc(a, 0) // same with to free(a)
    // int *b = (int*) realloc(NULL, n * sizeof(int)) // same with to malloc
    printf("Pre block address = %d, new address = %d\n", a, b);

    for (int i = 0; i < 2*n ; i++) {
        printf("%d ", b[i]);
    }

    return 0;
}