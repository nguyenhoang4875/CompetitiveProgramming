#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://codeforces.com/contest/1765/problem/D
 */

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
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
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];
    int sum = 0;
    For(i, 1, n) sum += a[i];
    sort(all1(a));

    int l = 1, r = n;
    int ans = 1;
    while (l < r) {
        if (a[l] + a[r] <= m) l++;
        else ans++;
        r--;
    }
    cout << ans + sum << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}