#include <bits/stdc++.h>
#define int long long

/**
 * https://codeforces.com/problemset/problem/1638/C
 */
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
struct Dsu {
    // MUST READ: Okay for both base-index: 0, 1
    int n;
    vector<int> parent, size;

    Dsu() {};
    Dsu(int _n) {
        n = _n;
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1, 1);  // init size = 1
        for (int v = 0; v <= n; v++) makeSet(v);
    }

    void makeSet(int v) { parent[v] = v; }

    int findSet(int v) { return parent[v] = (v == parent[v] ? v : findSet(parent[v])); }

    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);  // set a is root of the bigger size of tree
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int getSize(int v) { return size[findSet(v)]; }
};

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];
    Dsu dsu(n);
    set<pii> st;

    For(i, 1, n) {
        auto up = st.upper_bound({a[i], i});
        if (up == st.end()) {
            st.insert({a[i], i});
        } else {
            pii pre;
            while (up != st.end()) {
                dsu.unionSet(i, up->S);
                pre = *up;
                up = st.erase(up);
            }
            st.insert(pre);
        }
    }
    int cnt = 0;
    For(i, 1, n) {
        if (i == dsu.findSet(i)) cnt++;
    }
    cout << cnt << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}