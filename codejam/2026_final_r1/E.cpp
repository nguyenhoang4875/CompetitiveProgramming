#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 998244353;
const int ms = 2e5 + 5;

template <typename T = int>
struct FenwickTree {
    // MUST: base-index 1
    int n;
    vector<T> t;
    FenwickTree(int _n) {
        n = _n;
        t.resize(n + 1, 0);
    }
    // custom this function if needed (ACCUMULATE ONLY)
    T combine(T x, T y) { return x + y; }

    void update(int i, T delta) {
        while (i <= n) {
            t[i] = combine(t[i], delta);
            i += (i & (-i));
        }
    }
    T prefixSum(int i) {
        T val = 0;
        while (i > 0) {
            val = combine(val, t[i]);
            i -= (i & (-i));
        }
        return val;
    }
    T query(int l, int r) { return prefixSum(r) - prefixSum(l - 1); }

    void assign(int i, T val) { update(i, val - query(i, i)); }
};

void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];

    long long ans = n;       // len 1
    ans += n * (n - 1) / 2;  // len 2

    // len 3
    vi left_ls(n + 1), left_gr(n + 1);
    vi right_ls(n + 1), right_gr(n + 1);

    FenwickTree<int> ft(n);
    For(i, 1, n) {
        left_ls[i] = ft.prefixSum(a[i] - 1);
        left_gr[i] = i - 1 - left_ls[i];
        ft.update(a[i], 1);
    }

    ft.t.assign(n + 1, 0);
    Rof(i, n, 1) {
        right_ls[i] = ft.prefixSum(a[i] - 1);
        right_gr[i] = (n - i) - right_ls[i];
        ft.update(a[i], 1);
    }

    For(i, 2, n - 1) {
        ans += 1LL * left_ls[i] * right_ls[i];
        ans += 1LL * left_gr[i] * right_gr[i];
        ans %= mod;
    }

    // len 4
    vvi left_cnt(n + 2, vi(n + 2));  // number element has index <= i and value < v
    For(i, 1, n) {
        if (i > 1) left_cnt[i] = left_cnt[i - 1];
        For(v, a[i] + 1, n)++ left_cnt[i][v];
    }

    vvi right_cnt(n + 2, vi(n + 2));  // number element has index >= i and value < v
    Rof(i, n, 1) {
        if (i < n) right_cnt[i] = right_cnt[i + 1];
        For(v, a[i] + 1, n)++ right_cnt[i][v];
    }

    For(i, 2, n - 2) {
        For(j, i + 1, n - 1) {
            int mn = min(a[i], a[j]);
            int mx = max(a[i], a[j]);

            int cl = left_cnt[i - 1][mx] - left_cnt[i - 1][mn + 1];
            int cr = right_cnt[j + 1][mx] - right_cnt[j + 1][mn + 1];
            ans += 1LL * cl * cr;
            ans %= mod;
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    while (tcs--) {
        solve();
    }
    return 0;
}