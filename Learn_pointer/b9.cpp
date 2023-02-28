#include <bits/stdc++.h>
using namespace std;

// Pointers and multiple-dimensional arrays
// Two dimensional array

int main() {
    int b[2][3] = {{2, 3, 6}, {4, 5, 8}};
    int *p[2] = {b[0], b[1]};

    int i = 0, j = 0;
    printf("%d\n", b);
    printf("%d\n", *b);
    printf("%d\n", b[0]);
    printf("%d\n", &b[0][0]);

    printf("---------------\n");
    
    printf("%d\n", b[i][j]); // same as *(b[i] + j) = *(*(b + i) + j)
    printf("%d\n", *(b[i] + j));
    printf("%d\n", *(*(b + i) + j));

    return 0;
}