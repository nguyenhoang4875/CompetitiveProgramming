#include <bits/stdc++.h>
using namespace std;

// pointer as function arguments - call by reference

void increment1(int &a) {
    a += 1;
    printf("Address of variable a in increment 1 = %d\n", &a);
}

void increment2(int *a) {
    *a += 1;
    printf("Address of variable a in increment 2 = %d\n", a);
}

int main() {
    int a;
    a = 10;
    increment1(a);
    printf("a = %d", a);
    increment2(&a);
    printf("a = %d", a);
    printf("Address of variable a in main = %d\n", &a);
    return 0;
}