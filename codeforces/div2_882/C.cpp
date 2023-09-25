#include <bits/stdc++.h>
#define int long long

using namespace std;

using vi = vector<int>;

int tcs, n;
int a[100005];

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;

    int const max_value = 1 << 8;
    vector<bool> has_pref(max_value);
    has_pref[0] = true;
    int cur_xor = 0;
    int ans = 0;
    for (auto i : a) {
        cur_xor ^= i;
        for (int pref = 0; pref < max_value; ++pref) {
            if (has_pref[pref]) {
                ans = max(ans, pref ^ cur_xor);
            }
        }
        has_pref[cur_xor] = true;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // int mask = (1 << 8) - 1;
    // cout << mask << endl;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}