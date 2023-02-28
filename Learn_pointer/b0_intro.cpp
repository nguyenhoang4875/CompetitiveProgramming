#include<bits/stdc++.h>

int c;
using namespace std;
int main() {
    int a = 5;
    int *p; //declare a pointer
    p = &a; // assign address of a to the pointer p
    int n;
    cin >> n;
    cout << "n = " << n << endl;
    cout << "a address = " << &a << endl; //print address of a
    cout << "value of p = " << p << endl; //print value of b
    cout << "a = " << a << endl;
    cout << "value in the variable that p point to: " << *p << endl;
    // change value at the pointer p
    *p = 10; // change the value of variable that p point to
    cout << "a = " << a << endl;
    cout << " c = " << c << endl;
    return 0;
}
