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
    void add(int i, int val) {
        while (i <= n) {
            t[i] += val;
            i += i & (-i);
        }
    }
    int get(int i) {
        int sum = 0;
        while (i > 0) {
            sum += t[i];
            i -= i & -i;
        }
        return sum;
    }
    int query(int l, int r) { return get(r) - get(l - 1); }

    void set(int i, int val) { add(i, val - query(i, i)); }
};

struct Node {
    int a, b, id;
};

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;

void solve() {
    cin >> n;
    vector<Node> vn;
    For(i, 1, n) {
        int a, b;
        cin >> a >> b;
        vn.pb({a, b});
    }
    sort(all(vn), [&](Node n1, Node n2) {
        return n1.a < n2.a;
    });
    For(i, 0, n - 1) {
        vn[i].id = i + 1;
    }
    sort(all(vn), [&](Node n1, Node n2) {
        return n1.b < n2.b;
    });
    FenwickTree ft(n);
    int ans = 0;
    for(auto e: vn) {
        ans += ft.query(e.id, n);
        ft.add(e.id, 1);
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}