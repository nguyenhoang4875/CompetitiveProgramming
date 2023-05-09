#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;

void solve() {
    cin >> n;
    vector<pair<string, int>> v(n);
    int num;
    string s;
    for (int i = 0; i < n; i++) {
        cin >> num;
        cin >> s;
        v[i] = {s, num};
    }
    sort(v.begin(), v.end(), [&](pair<string, int> p1, pair<string, int> p2) {
        if(p1.first == p2.first) return p1.second < p2.second;
        return p1.first < p2.first;
    });

    // cout << "-----------------------" << endl;
    // for (auto e : v) {
    //     cout << e.second << " " << e.first << endl;
    // }
    // cout << "-----------------------" << endl;

    int s1 = 0, s2 = 0;
    int ans =  1e9;
    int ans2 = 1e9;
    for (auto e: v) {
        string s = e.first;
        if(s[0] == '1' && s[1] == '1') {
            ans2 = min(ans2, e.second);
        }
        if(s[0] == '1' && s[1] == '0' && s1 == 0) {
            s1 = e.second;
        }
        if(s[0] == '0' && s[1] == '1' && s2 == 0) {
            s2 = e.second;
        }
        if(s1 != 0 && s2 != 0) {
            ans = min(ans, s1 + s2);
        }
    }
    int res = min(ans, ans2);
    if(res == 1e9) {
        res = -1;
    } 
    cout << res << endl;

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