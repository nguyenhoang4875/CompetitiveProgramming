#include <bits/stdc++.h>
#define int long long
/**
 * Problem: https://www.spoj.com/problems/MST/
 * Solution: Using Kruskal Algorithm for minimum spanning tree
 *
 * TC: O((V + E) * logV)
 * MC: O(V + E)
 */

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

struct DsuRank {
    DsuRank(){};
    DsuRank(int n) : parent(n + 1), rank(n + 1){};

    vector<int> parent, rank;
    void makeSet(int v) {
        parent[v] = v;
        rank[v] = 0;  // init rank = 0
    }

    int findSet(int v) { return parent[v] = (parent[v] == v ? v : findSet(parent[v])); }

    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);  // set a is root of the bigger rank tree
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;  // if same rank increase the merge tree by 1
        }
    }
};

struct Graph {
    int n;
    vvi edges;

    Graph(int _n) {
        n = _n;
        edges.clear();
    }

    void addEdge(int u, int v, int w) { edges.push_back({w, u, v}); }

    int kruskalMst() {
        DsuRank dsu(n);
        For(i, 0, n - 1) dsu.makeSet(i);
        sort(all(edges));

        int ans = 0;
        int cnt = 0;
        for (auto edge : edges) {
            int w = edge[0];
            int u = dsu.findSet(edge[1]);
            int v = dsu.findSet(edge[2]);
            if (u == v) continue;
            dsu.unionSet(u, v);
            ans += w;  // weight
            cnt++;
            if (cnt == n - 1) break;
        }
        return ans;
    }
};

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n;

void solve() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    For(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;  // for based-index 0
        g.addEdge(u, v, w);
    }
    cout << g.kruskalMst() << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}