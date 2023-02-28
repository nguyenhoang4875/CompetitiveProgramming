#include<bits/stdc++.h>
using namespace std;

int main() {
    int a;
    int *p;
    p = &a;
    // Pointer arithmetic
    cout << "Address p is " << p << endl;
    cout << "size of integer is " << sizeof(int)  << endl;
    cout << "Address p + 1 is " << p + 2 << endl;
    cout << "Value at address p + 1 is " << *(p + 1) << endl;

    return 0;
}