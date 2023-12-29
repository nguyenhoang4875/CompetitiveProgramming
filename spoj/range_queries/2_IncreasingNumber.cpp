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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e6 + 5;
int n, l;
int a[ms];

struct FenwickTree {
    int n;
    vi t;
    FenwickTree(int _n) {
        n = _n;
        t.clear();
        t.resize(n + 1, 0);
    }
    void add(int i, int val) {
        while (i <= n) {
            t[i] = max(t[i], val);
            i += i & (-i);
        }
    }
    int get(int i) {
        int ans = 0;
        while (i > 0) {
            ans = max(ans, t[i]);
            i -= i & -i;
        }
        return ans;
    }
    int query(int l, int r) { return get(r) - get(l - 1); }

    void set(int i, int val) { add(i, val - query(i, i)); }
};

void solve() {
    cin >> n;
    vii b;
    For(i, 1, n) {
        int x;
        cin >> x;
        b.pb({x, i});
    }
    cin >> l;

    if(n == 0 || l > n) {
        cout << -1 << el;
        return;
    }
    sort(all(b));
    vii c;
    for(auto p: b) {
        if(!c.empty() && c.back().F == p.F) continue;
        c.pb(p);
    }
    FenwickTree ft(n);
    for(auto p: b) {
        int cnt = ft.get(p.S - 1) + 1;
        ft.add(p.S, cnt);
        if(cnt == l) {
            cout << p.F << el;
            return;
        }
    }
    cout << -1 << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while(tcs--) solve();
    return 0;
}