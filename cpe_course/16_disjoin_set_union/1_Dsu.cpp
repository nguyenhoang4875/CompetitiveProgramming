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
    Dsu(){};
    Dsu(int _n) {
        n = _n;
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1);
    }

    int n;
    vector<int> parent, size;
    vector<pair<int, int>> edges;
    void makeSet(int v) {
        parent[v] = v;
        size[v] = 1;  // init size = 1;
    }

    int findSet(int v) {
        return parent[v] = (v == parent[v] ? v : findSet(parent[v]));
    }

    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);  // set a is root of the bigger size of tree
            parent[b] = a;
            size[a] += size[b];  // update the new size of new the merge tree
        }
    }
    void addEdge(int u, int v) { edges.push_back({u, v}); }

    bool hasCycle() {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for (auto edge : edges) {
            int u = findSet(edge.first);
            int v = findSet(edge.second);
            if (u == v) return true;
            unionSet(u, v);
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