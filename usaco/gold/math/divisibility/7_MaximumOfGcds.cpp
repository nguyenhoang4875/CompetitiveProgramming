#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;
int a[ms];

void solve() {
    cin >> n;
    For(i, 1, n) { cin >> a[i]; }
    // f[i][j]: max size of subarray end at i with gcd = j
    vector<map<int, int>> f(n + 1);
    // base case len = 1
    For(i, 1, n) { f[i][a[i]] = 1; }

    For(i, 2, n) {
        for (auto [val, len] : f[i - 1]) {
            int newVal = gcd(val, a[i]);
            // set max size with subarray and at i has gcd newVal
            f[i][newVal] = max(f[i][newVal], len + 1);
        }
    }

    // find max for each len
    vi ans(n + 1, 0);
    For(i, 1, n) {
        for (auto [val, len] : f[i]) {
            ans[len] = max(ans[len], val);
        }
    }
    For(i, 1, n) { cout << ans[i] << " "; }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}