#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/17137
 * Solution: Using DP
 * A[i][k]: the number of all possible sequences
 * when the number of k or more is present in the i-th position
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
vi a;
vvi memo;

int sumCount(int pos, int start) {
    if (start > a[pos]) return 0;

    int &ans = memo[pos][start];
    if (ans > 0) return ans;

    if (pos + 1 == n)
        ans = a[pos] - start + 1;
    else {
        if (start + 1 <= a[pos]) ans = sumCount(pos, start + 1);
        ans += sumCount(pos + 1, start);
        ans = ans % mod;
    }
    return ans;
}

void solve() {
    cin >> n;
    a = vi(n);
    memo = vvi(n, vi(201, 0));
    For(i, 0, n - 1) cin >> a[i];
    sort(all(a));

    int ans = sumCount(0, 1) * n % mod;
    cout << ans << el;
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