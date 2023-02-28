#include <bits/stdc++.h>
using namespace std;

// Pointers and multiple-dimensional arrays
// Three dimensional array

int main() {
    int c[3][2][2] = {{{2, 5}, {7, 9}}, {{3, 4}, {6, 1}}, {{0, 8}, {11, 13}}};

    printf("%d\n", c);
    printf("%d\n", *c);
    printf("%d\n", c[0]);
    printf("%d\n", c[0][0]);
    printf("%d\n", &c[0][0]);
    printf("%d\n", &c[0][0][0]);

    printf("---------------\n");
    
    int i = 0, j = 0, k = 0;
    printf("%d\n", c[i][j][k]);
    printf("%d\n", *(*(c[i] + j) + k));
    printf("%d\n", *(*(*(c + i) + j) + k));

    return 0;
}