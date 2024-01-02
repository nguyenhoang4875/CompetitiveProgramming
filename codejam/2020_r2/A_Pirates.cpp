#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/19241
 *
 * Solution: Greedy pick the box has max value of XA + XB first
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
int n;

void solve() {
    cin >> n;
    vii ab;
    For(i, 1, n) {
        int x, y;
        cin >> x >> y;
        ab.pb({x, y});
    }
    sort(all(ab), [&](pii p1, pii p2) { return p1.F + p1.S > p2.F + p2.S; });
    int sumA = 0, sumB = 0;
    For(i, 0, n - 1) {
        if ((i & 1) == 0)
            sumA += ab[i].F;
        else
            sumB += ab[i].S;
    }

    cout << sumA - sumB << el;
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