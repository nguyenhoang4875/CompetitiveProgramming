#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Shortest Path
 * Solution: Using dijkstra algorithm
 *  use for edge positive weight
 *
 * TC: O((V + E) * log E)
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

    vector<int> dijkstra(int s) {
        vector<int> dist(n + 1, oo);
        dist[s] = 0;
        priority_queue<pii, vii, greater<pii>> q;
        q.push({0, s});  // first: dist, second: vertex

        while (!q.empty()) {
            pii p = q.top();
            q.pop();

            int u = p.S;  // get vertex
            for (auto e : gr[u]) {
                if (dist[u] != oo && dist[e.F] > dist[u] + e.S) {
                    dist[e.F] = dist[u] + e.S;
                    q.push({dist[e.F], e.F});
                }
            }
        }
        return dist;
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
    vi dist = g.dijkstra(0);
    cout << dist[n - 1];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}