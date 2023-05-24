#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
string s;
char g[20];
int size;
int cnt = 0;
string s1, s2;
int ans = 0;

void calculate() {
    s1 = "", s2 = "";
    for (int i = 0; i < n; i++) {
        if(g[i] == '0') s1 += s[i];
        else s2 += s[i];
    }
    if(s1 != "" && s2 != "") {
        sort(s1.begin(), s1.end(), greater<char>());
        sort(s2.begin(), s2.end(), greater<char>());
        ans = max(ans, stoll(s1, 0, 10) * stoll(s2, 0, 10));
    }
}

void gen(int idx) {
    if(idx == n) {
        calculate(); 
    } else {
        for (char val : {'0', '1'}) {
            g[idx] = val;
            gen(idx + 1);
        }
    }
}

void solve() {
    cin >> s;
    ans = 0;
    s1 = "", s2 = "";
    n = s.size();
    int cntZero = 0;
    for (int i = 0; i < n; i++) {
        if(s[i] == '6') s[i] = '9';
        if(s[i] == '0') cntZero++;
    }
    sort(s.begin(), s.end(), greater<char>());
    s.resize(n - cntZero);
    n -= cntZero;
    gen(0);
    int p = 1;
    while (cntZero--) p *= 10;
    ans *= p;
    cout << ans << endl;
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