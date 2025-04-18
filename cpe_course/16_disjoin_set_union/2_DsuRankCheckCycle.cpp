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

struct Dsu {
    int n;
    vector<int> parent, rank;
    vector<pair<int, int>> edges;

    Dsu() {};
    Dsu(int _n) {
        n = _n;
        parent = vector<int>(n + 1);
        rank = vector<int>(n + 1, 0);  // init rank = 0
        for (int v = 1; v <= n; v++) { makeSet(v); }
    }

    void makeSet(int v) { parent[v] = v; }

    int findSet(int v) { return parent[v] = (parent[v] == v ? v : findSet(parent[v])); }

    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return false;

        if (rank[a] < rank[b]) swap(a, b);  // set a is root of the bigger rank tree
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;  // if same rank increase the merge tree by 1
        return true;
    }

    void addEdge(int a, int b) { edges.push_back({a, b}); }

    bool hasCycle() {
        for (int i = 1; i <= n; i++) { parent[i] = i; }

        for (auto edge : edges) {
            int a = findSet(edge.first);
            int b = findSet(edge.second);
            if (a == b) return true;
            unionSet(a, b);
        }
        return false;
    }
};

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;

void solve() {
    int n, m;
    cin >> n >> m;
    Dsu dsu(n);
    For(i, 1, m) {
        int u, v;
        cin >> u >> v;
        dsu.edges.pb({u, v});
    }

    cout << "The graph contains cycle: " << dsu.hasCycle() << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}