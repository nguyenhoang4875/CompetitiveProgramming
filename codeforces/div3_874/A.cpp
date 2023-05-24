#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
string s;

void solve() {
    cin >> n;
    unordered_set<string> ss;
    cin >> s;
    for(int i = 0; i <= n-2 ; i++) {
        string ts;
        ts += s[i];
        ts += s[i+1];
        if(!ss.count(ts)) ss.insert(ts);
    }
    cout << ss.size() << endl;

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