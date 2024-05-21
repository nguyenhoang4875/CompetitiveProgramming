#include <bits/stdc++.h>

using namespace std;

struct node {
    int a, b, c;
    
    bool operator<(const node& n) const {
        if (a == n.a) return b < n.b;
        return a < n.a;
    }

    bool operator==(const node& n) const {
        return a == n.a && b == n.b && c == n.c;
    }

    friend ostream& operator<<(ostream& os, const node& n) {
        return os << n.a << " " << n.b << " " << n.c;
    }
};
