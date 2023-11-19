#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.codechef.com/problems/DIVSUBS
 * Solution: Using pigeonhole principle
 * - a[i] = a[i] % n: value will be in range: [0, n -1]
 * - have n numbers so at least two same value
 *
 * TC: O(n)
 * MC: O(n)
 *
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
int a[ms];
int pa[ms];

void solve() {
    cin >> n;
    For(i, 1, n) {
        cin >> a[i];
        a[i] %= n;
    }
    vi va[n];
    For(i, 1, n) {
        pa[i] = pa[i - 1] + a[i];
        pa[i] %= n;
        va[pa[i]].pb(i);
    }

    if (va[0].size() >= 1) {
        int t = va[0][0];
        cout << t << el;
        for (int i = 1; i <= t; i++) {
            cout << i << " ";
        }
        cout << el;
        return;
    }

    For(i, 1, n - 1) {
        int ss = sz(va[i]);
        if (ss >= 2) {
            int l = va[i][0];
            int r = va[i][1];
            cout << r - l << el;
            For(t, l + 1, r) { cout << t << " "; }
            cout << el;
            return;
        }
    }
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