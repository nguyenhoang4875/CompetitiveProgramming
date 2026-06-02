#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Monotonic Stak + DSU
 */

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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

struct Dsu {
    // MUST READ: Works for both base-index: 0 and 1
    int n, num_set;
    vector<int> parent, siz;

    Dsu(int _n) {
        n = _n;
        num_set = n;
        parent.resize(n + 1);
        siz.assign(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int findSet(int v) { return parent[v] = (v == parent[v] ? v : findSet(parent[v])); }
    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);

        if (a == b) return false;
        if (siz[a] < siz[b]) swap(a, b);  // set a is root of the bigger size of tree
        parent[b] = a;
        siz[a] += siz[b];
        --num_set;
        return true;
    }
    int getSize(int v) { return siz[findSet(v)]; }
    bool isSameSet(int u, int v) { return findSet(u) == findSet(v); }
    int getNumSet() const { return num_set; }
};

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];

    if (k > 1 and k >= (n + 1) / 2) {
        cout << -1 << el;
        return;
    }

    vi l(n + 1), r(n + 1);

    vector<int> st;
    For(i, 1, n) {
        while (st.size() and a[st.back()] <= a[i]) st.pop_back();

        if (st.size()) l[i] = st.back() + 1;
        else l[i] = 1;

        st.push_back(i);
    }

    st.clear();
    Rof(i, n, 1) {
        while (st.size() and a[st.back()] <= a[i]) st.pop_back();

        if (st.size()) r[i] = st.back() - 1;
        else r[i] = n;

        st.push_back(i);
    }

    vector<pii> vp(n + 1);
    For(i, 1, n) vp[i] = {a[i], i};

    sort(1 + all(vp));

    Dsu dsu(n);

    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        int mn = vp[i].F, idx = vp[i].S;
        int ll = l[idx], rr = r[idx];
        if (rr - ll < k) continue;

        For(j, ll + k, rr) {
            if (dsu.unionSet(ll, j)) {
                sum += mn;
            };
        }

        Rof(j, min(ll + k - 1, rr - k), ll) {
            if (dsu.unionSet(rr, j)) {
                sum += mn;
            }
        }

        if (dsu.num_set == 1) {
            break;
        }
    }
    cout << sum << el;
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