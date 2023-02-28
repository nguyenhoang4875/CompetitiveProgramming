#include <bits/stdc++.h>
using namespace std;

// Stack vs heap


int main() {
    int a; // goes on stack
    int *p;
    p = new int; // declare a memory in heap syntax in C++
    *p = 10;
    delete p; // delete the memory for p in heap syntax in C++
    p = new int; // declare a memory in heap syntax in C++
    *p = 20;
    cout << *p << endl;

    return 0;
}