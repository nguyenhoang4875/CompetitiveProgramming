#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
string s;

void solve() {
    cin >> s;
    n = s.size();
    int num = 0;
    for(char c: s) if(c == '?') num++;
    if(num == 0) {
        cout << s << endl;
        return;
    }
    if(s[0] == '?') s[0] = '0';
    if(s[n - 1] == '?') s[n -1] = '1';
    for(int i = 1; i < n - 1; i++) {
        if(s[i] == '?') {
            s[i] = s[i-1];
        }
    }
    cout << s << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}