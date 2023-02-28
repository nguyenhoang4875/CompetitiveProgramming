#include<bits/stdc++.h>
using namespace std;

// pointer to pointer
int main() {
    int x = 5;
    int* p = &x;
    *p = 6;
    int** q = &p;
    int*** r = &q;
    printf("%d\n", *p); // value of x
    printf("%d\n", *q); // address of p
    printf("%d\n", **q); // value of x
    printf("%d\n", **r); // value of p
    printf("%d\n", ***r); // value of x
    ***r = 10;
    printf("x = %d\n", x); // x == 10
    **q = *p +2;
    printf("x = %d\n", x); // x == 12
   
    return 0;
}