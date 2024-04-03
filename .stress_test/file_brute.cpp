#include <bits/stdc++.h>
#define int long long
/**
 * Problem: https://www.hackerrank.com/contests/dn-swpct-2024-batch-1/challenges/lgedvs-marathon
 */

using namespace std;

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
const int ms = 2e5 + 5;
int n, t;

void solve() {
    cin >> n >> t;
    vii v = vii(n);
    For(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        int val = x + y * t;
        v[i] = {i, val};
    }
    sort(all(v), [&](pii p1, pii p2) {
        if (p1.S == p2.S) return p1.F > p2.F;
        return p1.S < p2.S;
    });
    int idxCur = v[0].F;
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (v[i].F < idxCur) {
            continue;
        }
        idxCur = v[i].F;
        cnt++;
    }
    cout << cnt << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}