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
int n;
int a[ms];

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
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, int> m;
    vii v(n + 1);

    // find left position for each i
    int l = 1;
    for (int i = 1; i <= n; i++) {
        if (m.count(a[i])) {
            l = max(l, m[a[i]] + 1);
        }
        m[a[i]] = i;
        v[i].F = l;
    }
    m.clear();
    // find right position for each i
    int r = n;
    for (int i = n; i >= 1; i--) {
        if (m.count(a[i])) {
            r = min(r, m[a[i]] - 1);
        }
        m[a[i]] = i;
        v[i].S = r;
    }

    auto cal = [&](int i, int len) {
        if (len == 1) return 0LL;
        if (i == 1) return len - 1;
        int ret = i * i % mod;
        ret *= (powerMod(i, len - 1, mod) - 1);
        ret %= mod;
        ret *= powerMod(i - 1, mod - 2, mod);
        return ret % mod;
    };

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int l = v[i].F, r = v[i].S;
        ans += cal(i, i - l + 1);
        ans %= mod;
        ans += cal(i, r - i + 1);
        ans %= mod;
    }
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