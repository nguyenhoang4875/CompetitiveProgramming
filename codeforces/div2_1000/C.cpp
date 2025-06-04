#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
    return os << "}";
}
#else
#define del
#define debug(x)
#endif

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
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
int n;

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

void solve() {
    cin >> n;
    vector<vector<int>> adj(n + 1);
    vii edges;
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        edges.pb({u, v});
    }

    For(u, 1, n) { adj[u].pb(u); }
    sort(adj.begin(), adj.end(),
         [&](vector<int>& s1, vector<int>& s2) { return s1.size() > s2.size(); });
    int u = adj[0].back();

    adj = vvi(n + 1);
    for (auto& [x, y] : edges) {
        if (x == u or y == u) continue;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    For(i, 1, n) {
        if (i == u) continue;
        adj[i].pb(i);
    }
    sort(adj.begin(), adj.end(),
         [&](vector<int>& s1, vector<int>& s2) { return s1.size() > s2.size(); });
    int v = adj[0].back();
    debug(u);
    debug(v);

    Dsu dsu(n);
    for (auto& [x, y] : edges) {
        if (x == u or x == v) continue;
        if (y == u or y == v) continue;
        dsu.unionSet(x, y);
    }

    int ans = 0;
    vb seen(n + 1, false);
    for (int x = 1; x <= n; x++) {
        if (x == u or x == v) continue;
        int root = dsu.findSet(x);
        if (!seen[root]) {
            ans++;
            seen[root] = true;
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}