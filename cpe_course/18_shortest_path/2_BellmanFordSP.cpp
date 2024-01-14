#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Shortest Path
 * Solution: Using dijkstra algorithm
 *  use for edge positive and negative weight
 *  can detect a negative cycle
 *
 * TC: O(V * E)
 * MC: O(V + E)
 */

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
const int ms = 1e5 + 5;

struct Graph {
    int n;
    vector<vector<pair<int, int>>> gr;

    Graph(int _n) {
        n = _n;
        gr = vector<vector<pair<int, int>>>(n + 1);
    }

    void addEdge(int u, int v, int w) {
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});  // if undirected
    }

    vector<int> bellmanFord(int s) {
        vi dist(n + 1, oo);
        dist[s] = 0;
        for (int i = 0; i < n - 1; i++) {
            // travel all edges
            for (int u = 0; u < n; u++) {
                for (auto e : gr[u]) {
                    int v = e.F;
                    int w = e.S;

                    if (dist[u] != oo && dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                    }
                }
            }
        }
        return dist;
    }

    bool isNegCycleBellmanFord(int s) {
        vi dist = bellmanFord(s);
        for (int i = 0; i < n - 1; i++) {
            // travel all edges
            for (int u = 0; u < n; u++) {
                for (auto e : gr[u]) {
                    int v = e.F;
                    int w = e.S;

                    if (dist[u] != oo && dist[u] + w < dist[v]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        g.addEdge(u, v, w);
    }
    if (g.isNegCycleBellmanFord(0)) {
        cout << "No cycle" << el;
    } else
        cout << "has cycle" << el;
    vi dist = g.bellmanFord(0);
    cout << dist[4] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}