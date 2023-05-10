#include<bits/stdc++.h>
using namespace std;
/**
 * https://codeforces.com/contest/1703/problem/B
*/
int tcs, n;
string s;
set<char> setc;

void solve() {
    setc.clear();
    cin >> n;
    cin >> s;
    for (int i = 0; i < n ; i++) {
        setc.insert(s[i]);
    }
    cout << (setc.size() + n) << endl;
}

int main() {
    cin >> tcs;
    while(tcs-- > 0) {
        solve();
    }

    return 0;
}