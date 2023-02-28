#include <bits/stdc++.h>
using namespace std;

// Stack vs heap


int main() {
    int a; // goes on stack
    int *p;
    p = (int*)malloc(sizeof(int)); // declare a memory in heap syntax in C
    *p = 10;
    free(p); // delete the memory for p in heap syntax in C
    p = (int*)malloc(sizeof(int)); // declare a memory in heap syntax in C

    *p = 20;
    p = (int*)malloc(20 * sizeof(int)); // declare a memory in heap syntax in C
    cout << *p << endl;

    return 0;
}