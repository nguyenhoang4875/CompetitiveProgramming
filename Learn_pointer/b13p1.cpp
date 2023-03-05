#include <bits/stdc++.h>
using namespace std;

/**
 * Function pointer and callbacks
*/

void a () {
    printf("Hello\n");
}
void b (void(*ptr)()) { // function pointer as argument
    ptr(); // callback function that "ptr" points to
}

int main() { 
    void (*p)() = a;
    b(p); // same with b(a)
    b(a); // a is callback function
    

    return 0;
}
