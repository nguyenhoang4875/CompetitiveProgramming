#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/18768
 * Solution: Greedy
 *  sort by b[i] - a[i] desc
 *
 * TC: O(n log n)
 * MC: O(n)
 */

//*** define ***//
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
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
int n, k;
struct node {
    int id, a, b;
};

void solve() {
    cin >> n >> k;
    vi a(n), b(n);
    For(i, 0, n - 1) cin >> a[i];
    For(i, 0, n - 1) cin >> b[i];
    vi v(n);
    For(i, 0, n - 1) v[i] = i;
    sort(all(v), [&](int i, int j) {
        int di = b[i] - a[i];
        int dj = b[j] - a[j];
        return di > dj;  // sort by diff b[i] vs a[i] desc
    });

    /*
    cntA + cntB = n
    cntA - cntB = k
    => 2 * cnTB = n - k;
    m = n - k;
    if(m & 1) m++, k--; // reduce k to meet condition
    m /= 2;
    cntB = m ;
    cntA = m + k;
    */

    int m = n - k;
    if (m & 1) ++m, --k;
    m /= 2;

    int ans = 0;
    For(i, 0, m - 1) ans += b[v[i]];
    For(i, m, m + k - 1) ans += max(a[v[i]], b[v[i]]);
    For(i, m + k, n - 1) ans += a[v[i]];

    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}