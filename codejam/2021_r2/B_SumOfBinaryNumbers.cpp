#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/21396
 * Solution: Adding without carry is XOR operator
 * using map to save and get data
 * TC: O(n)
 * MC: O(n)
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

int tcs, n, x;
unordered_map<int, int> mp;

void solve() {
    mp.clear();
    cin >> n >> x;
    int val;
    for(int i = 1; i <= n; i++) {
        cin >> val;
        mp[val]++;
    }

    int k;
    int ans = 0;
    // cout << " n = " << n << " x = " << x << endl;
    for(auto e: mp) {
        if(x == 0) {
            ans += e.second * (e.second - 1) / 2;
            continue;
        }
        k = x ^ e.first;
        if(mp.count(k)) ans += e.second * mp[k];
    }
    if(x != 0) ans /= 2;
    cout << ans << '\n';

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