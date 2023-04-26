#include<bits/stdc++.h>

using namespace std;

/**
 * https://codeforces.com/contest/1805/problem/B
*/

int tcs, n;
string s;

struct pt{
    int a, b, c;
    pt(int a, int b, int c): a(a), b(b), c(c){};
};

void solve() {
    cin >> n;
    cin >> s;
    if(n == 1) {
        cout << s << endl;
        return;
    }
    char c = 'z';
    int imin = 0;
    // char fc = s[0];
    // int idup = 1;
    // while(s[idup] == fc) idup++;
    for (int i = 0; i < n; i++) {
        if(s[i] <= c ) {
            imin = i;
            c = s[i];
        };
    };
    s.erase(imin, 1);
    s = c + s;
    cout << s << endl;
}

int main() {
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    
    return 0;
}