#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/DEFKIN/
 * Solution: Find max diff weight, max diff height
 *  => ans = max_diff_weight * max_diff_height
 *
 * TC: O(n * log n)
 * MC: O(n)
 */

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int w, h, n;

void solve() {
    cin >> w >> h >> n;
    if (n == 0) {
        cout << w * h << el;
        return;
    }
    vii a;
    For(i, 1, n) {
        int x, y;
        cin >> x >> y;
        a.pb({x, y});
    }

    sort(all(a), [&](pii p1, pii p2) { return p1.F < p2.F; });
    int maxW = a[0].F - 1;
    For(i, 0, n - 2) { maxW = max(maxW, a[i + 1].F - a[i].F - 1); }
    maxW = max(maxW, w - a[n - 1].F);

    sort(all(a), [&](pii p1, pii p2) { return p1.S < p2.S; });
    int maxH = a[0].S - 1;
    For(i, 0, n - 2) { maxH = max(maxH, a[i + 1].S - a[i].S - 1); }
    maxH = max(maxH, h - a[n - 1].S);
    cout << maxW * maxH << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}