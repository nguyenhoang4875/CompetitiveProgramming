#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
string s;
map<char, int> mc;

void solve() {
    cin >> s;
    mc.clear();
    n = s.size();
    for (int i = 0; i < n; i++) {
        mc[s[i]]++;
    }
    if(mc.size() == 1) {
        cout << "NO\n";
        return;
    }
    if(mc.size() == 2) {
        for (auto e: mc) {
            if(e.second == 1) {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";

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