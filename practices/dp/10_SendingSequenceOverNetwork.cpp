#include<bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/contest/1741/problem/E
 * Dp in two directions
 */

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int) (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int) (b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];

    vi f(n + 1, 0); // f[i]: is valid for first i-th element
    f[0] = 1;
    For(i, 1, n) {
        if (i - a[i] - 1 >= 0) f[i] |= f[i - a[i] - 1];
        if (i + a[i] <= n) f[i + a[i]] |= f[i - 1];
    }
    if (f[n]) cout << "YES" << el;
    else cout << "NO" << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}