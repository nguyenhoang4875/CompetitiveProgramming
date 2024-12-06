#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int) (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int) (b); i--)
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
    int n;
    vector<int> parent, size;

    Dsu() {};
    Dsu(int _n) {
        n = _n;
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1);
        for (int v = 1; v <= n; v++) makeSet(v);
    }

    void makeSet(int v) {
        parent[v] = v;
        size[v] = 1;  // init size = 1;
    }

    int findSet(int v) { return parent[v] = (v == parent[v] ? v : findSet(parent[v])); }

    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);  // set a is root of the bigger size of tree
        parent[b] = a;
        size[a] += size[b];  // update the new size of new the merge tree
        return true;
    }
};

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;
int a[ms], b[ms], d[ms];

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) cin >> b[i];
    For(i, 1, n) cin >> d[i];

    Dsu dsu(n);
    For(i, 1, n) {
        dsu.unionSet(a[i], b[i]);
    }

    set<int> st;
    For(i, 1, n) {
        st.insert(dsu.findSet(i));
    }
    For(i, 1, n) {
        if(d[i] == 0) continue;
        st.erase(dsu.findSet(a[i]));
    }

    int p = 0;
    for(auto e: st) {
        if(dsu.size[dsu.findSet(e)] > 1) {
            p++;
        }
    }
    int ret = 1;
    for(int i = 0; i < p; i++) {
        ret *= 2; 
        if(ret > mod) ret = ret % mod;
    }
    cout << ret << el;
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