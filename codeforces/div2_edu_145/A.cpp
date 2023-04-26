#include<bits/stdc++.h>

using namespace std;
/**
 * https://codeforces.com/contest/1809/problem/A
*/

int tcs, n;

void solve() {
    // cin >> n;
    string s;
    cin >> s;
    map<char, int> ss;
    for(char c: s) {
        ss[c]++;
    }
    int mc = 0;
    if(ss.size() >= 3) {
        cout << 4 << endl;
        return;
    } else if (ss.size() == 1) {
        cout << -1 << endl;
        return;
    } else {
        for (pair<char, int> e: ss) {
            mc = max(mc, e.second);
        }
        if(mc == 3) {
            cout << 6 << endl;
            return;
        }
        if(mc == 2) {
            cout << 4 << endl;
            return;
        }

    }
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