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
const int ms = 2e5 + 5;

// power mod p iterator
int powerMod(int a, int n, int p) {
    int ans = 1;
    a = a % p;
    while (n > 0) {
        if (n & 1) ans = (ans * a) % p;
        n /= 2;
        a = (a * a) % p;
    }
    return ans;
}

void solve() {
    int l, r, k;
    cin >> l >> r >> k;
    int ans = (powerMod(9 / k + 1, r, mod) - powerMod(9 / k + 1, l, mod) + mod) % mod;
    cout << ans << el;
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