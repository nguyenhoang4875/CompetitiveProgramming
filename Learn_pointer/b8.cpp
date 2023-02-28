#include <bits/stdc++.h>
using namespace std;

// Character arrays and pointer part 2

void print(char *c) {

    while(*c != '\0') {
        printf("%c", *c);
        c++;
    }
    printf("\n");
}

int main() {
    char c[20] = "Hello"; // string gets stored in the space for array
    // char *c = "Hello"; // string gets stored as compile time constant.
    print(c);

    return 0;
}