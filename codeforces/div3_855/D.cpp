#include<bits/stdc++.h>

using namespace std;
/**
 * This source for problem
 * https://codeforces.com/contest/1800/problem/D
*/

int tcs, n;
string s;

void solve() {
    unordered_set<string> set_str;
    cin >> n;
    cin >> s;
    string tmp;
    int dup = 1;
    for (int i = 0; i <= n - 3 ; i++) {
        if(s[i] == s[i+2]) dup++;
    }
    cout << (n - dup) << endl;
}
int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> tcs;
    while(tcs--) {
        solve();
    }
    
    return 0;
}