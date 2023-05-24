#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Let A, B, add X to A or B
 * if(A < B) => AX * B larger than A * BX
*/

int tcs, n;
string s;
int ans = 0;

void solve() {
    cin >> s;
    ans = 0;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if(s[i] == '6') s[i] = '9';
    }
    sort(s.begin(), s.end(), greater<char>());
    int s1 = 0, s2 = 0;
    for (int i = 0; i < n; i++) {
        if(s1 < s2) {
            s1  = s1 * 10 + (s[i] - '0');
        } else {
            s2  = s2 * 10 + (s[i] - '0');
        }
    }
    cout << s1*s2 << endl;
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