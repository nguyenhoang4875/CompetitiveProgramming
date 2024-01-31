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

struct FenwickTree {
    int n;
    vi t;
    FenwickTree(int _n) {
        n = _n;
        t.resize(n + 1, 0);
    }

    int combine(int x, int y) {
        // return x + y;
        return max(x, y); // if max tree
    }

    void add(int i, int val) {
        while (i <= n) {
            t[i] = combine(t[i], val);
            i += i & (-i);
        }
    }
    int get(int i) {
        int val = 0;
        while (i > 0) {
            val = combine(val, t[i]);
            i -= i & -i;
        }
        return val;
    }
    int query(int l, int r) { return get(r) - get(l - 1); }

    void set(int i, int val) { add(i, val - query(i, i)); }
};

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
int a[ms];
int h[ms];
int dp[ms];

void solve() {
    cin >> n;
    For(i, 1, n) cin >> h[i];
    For(i, 1, n) cin >> a[i];
    int ans = 0;

    // For(i, 1, n) {
    //     dp[i] = a[i];
    //     For(j, 1, i - 1) {
    //         if(h[i] >= h[j]) {
    //             dp[i] = max(dp[i], dp[j] + a[i]);
    //         }
    //     }
    //     ans = max(ans, dp[i]);
    // }
    // cout << ans << el;

    FenwickTree ft(n);
    For(i, 1, n) { ft.add(h[i], ft.get(h[i] - 1) + a[i]); }
    cout << ft.get(n) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}