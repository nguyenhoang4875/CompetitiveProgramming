#include <bits/stdc++.h>
using namespace std;

/**
 * Function pointer
 *  Can point ot data
 *  Can point to function
*/

int*  func(int, int); // declare a function that would return int*;

int add(int a, int b) {
    return a + b;
}

void printHello(string str) {
    printf("Hello: ");
    cout << str << endl;
}

int main() { 

    // pointer to function that should take
    // (int, int) as argument/parameter and return it
    int c;
    int (*p) (int, int);
    p = &add; // or: p = add;
    // p = add;
    c = (*p)(2, 3); // de-referencing and executing the function
    // c = p(2, 3); // de-referencing and executing the function
    printf("%d\n", c);

    void (*ptr) (string);
    ptr = printHello;
    ptr("Tom");
    
    return 0;
}
