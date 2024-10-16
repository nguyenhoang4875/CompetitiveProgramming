#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
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

struct FenwickTree {
    int n;
    vector<int> t;
    FenwickTree(int _n) {
        n = _n;
        t.resize(n + 1, 0);
    }
    // custom this function if needed
    int combine(int x, int y) {
        return x + y;
        // return max(x, y); // if max tree
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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, t;
int pre[ms];
int a[ms];

void solve() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
        a[i] = pre[i];
    }

    sort(a + 1, a + n + 1);
    int m = unique(a + 1, a + n + 1) - a - 1;

    FenwickTree ft(n);
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        int l = lower_bound(a + 1, a + m + 1, pre[i]) - a;
        ft.add(l, 1);
        int r = upper_bound(a + 1, a + m + 1, pre[i - 1] + t - 1) - a - 1;
        ans += ft.get(r);
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}