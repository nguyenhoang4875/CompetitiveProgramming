#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/BUSYMAN/
 * Solution: Greedy sort ascending time end of activity
 *
 * TC: O(n log n)
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
int n, a, b;

void solve() {
    cin >> n;
    vii times;
    For(i, 1, n) {
        cin >> a >> b;
        times.pb({a, b});
    }
    sort(all(times), [&](pii p1, pii p2) { return p1.S < p2.S; });
    int t = 0;
    int cnt = 0;
    for (auto p : times) {
        if (p.F >= t) {
            cnt++;
            t = p.S;
        }
    }
    cout << cnt << el;
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