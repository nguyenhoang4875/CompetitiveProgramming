#include <bits/stdc++.h>
#define int long long

using namespace std;

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

const long long oo = 2e18, mod = 444449;
const int ms = 1e5 + 5;
int fact[mod + 5], ifact[mod + 5];

// Hàm lũy thừa nhanh
long long binpow(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b % 2) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

void init() {
    // Tính fact[]
    fact[0] = 1;
    for (int i = 1; i < mod; i++) fact[i] = 1LL * fact[i - 1] * i % mod;

    // Tính ifact[]
    ifact[mod - 1] = binpow(fact[mod - 1], mod - 2);
    for (int i = mod - 2; i >= 0; i--) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;
}

// Hàm tính nCk với n < M
int C(int n, int k) {
    if (k > n) return 0;
    return (1LL * fact[n] * ifact[k] % mod) * ifact[n - k] % mod;
}

// Hàm tính nCk với n có thể lớn hơn M
int comb(long long n, long long k) {
    if (k > n) return 0;
    int res = 1;
    while (n > 0) {
        res = 1LL * res * C(n % mod, k % mod) % mod;
        n /= mod;
        k /= mod;
    }
    return res;
}

void solve() {
    int n, v;
    cin >> n >> v;

    vi a(n);
    Rep(i, n) cin >> a[i];
    vi l(n);
    Rep(i, n) {
        cin >> l[i];
        l[i]--;
    }
    vi r(n);
    Rep(i, n) {
        cin >> r[i];
        r[i]--;
    }

    vi anc(n, -1);
    Rep(i, n) {
        if (l[i] != -1) anc[l[i]] = i;
        if (r[i] != -1) anc[r[i]] = i;
    }
    int root = -1;
    Rep(i, n) if (anc[i] == -1) root = i;

    vi order;
    function<void(int)> inOrder = [&](int u) {
        if (l[u] != -1) inOrder(l[u]);
        order.pb(u);
        if (r[u] != -1) inOrder(r[u]);
    };

    inOrder(root);
    vii fixed;
    fixed.pb({0, -1});
    Rep(i, n) {
        int p = a[order[i]];
        if (p != 0) fixed.pb({p, i});
    }

    fixed.pb({v + 1, n});

    int res = 1;
    int m = fixed.size();
    for (int i = 1; i < m; i++) {
        auto [x1, y1] = fixed[i];
        auto [x2, y2] = fixed[i - 1];
        int nn = x1 - x2 - 1;
        int kk = y1 - y2 - 1;
        int t = comb(nn, kk);
        if (t == 0) {
            res = 0;
            break;
        }
        res = res * t % mod;
    }
    cout << res << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}