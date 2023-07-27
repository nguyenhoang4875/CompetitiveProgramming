#include <bits/stdc++.h>

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1015/problem/D
 * TC: O(n)
 * MC: O(n)
*/

//*** define ***//
#define int long long
#define pb push_back

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

int tcs, n, k, s;

void solve() {
    cin >> n >> k >> s;
    int mx = n - 1;
    int m = s % mx;
    if (s / mx > k || (s / mx == k && m != 0) || k > s) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    if (s / mx == k && m == 0) {
        for (int i = 1; i <= k; i++) {
            if (i & 1)
                cout << n << ' ';
            else
                cout << "1 ";
        }
        return;
    }

    int d = s / mx;
    int rm = k - d;
    s -= d * mx;
    // while until rm <= s: can move for other cases
    while (d > 0 && rm > s) {
        d--;
        s += mx;
        rm++;
    }
    vi v;
    for (int i = 1; i <= d; i++) {
        if (i & 1)
            v.pb(n);
        else
            v.pb(1);
    }
    int d1 = s / rm;
    int t = s % rm;
    // cout << "d = " << d << endl;
    if (d & 1) {
        // pre = n
        rm--;
        int pre = n - d1 - t;
        v.pb(pre);
        for (int i = 1; i <= rm; i++) {
            if (i & 1)
                pre += d1;
            else
                pre -= d1;
            v.pb(pre);
        }
    } else {
        // pre = 1
        rm--;
        int pre = 1 + d1 + t;
        v.pb(pre);
        for (int i = 1; i <= rm; i++) {
            if (i & 1)
                pre -= d1;
            else
                pre += d1;
            v.pb(pre);
        }
    }
    for (auto e : v) cout << e << ' ';
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cin >> tcs;
    tcs = 1;
    while (tcs--) {
        solve();
    }
    return 0;
}