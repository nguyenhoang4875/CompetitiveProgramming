#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Shortest Path in a Binary Weight Graph
 *
 * TC: O(V + E)
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
const int ms = 1e3 + 5;
int n, m;

struct edge {
    int to, weight;
};

vector<vector<edge>> graph;
vector<int> dist;

int addEdge(int u, int v, int w) {
    graph[u].pb({v, w});
    graph[v].pb({u, w});
}

void bfs(int s) {
    dist[s] = 0;
    deque<int> q;
    q.push_back(s);

    while (!q.empty()) {
        int u = q.front();
        q.pop_front();

        for (auto v : graph[u]) {
            if (dist[v.to] > dist[u] + v.weight) {
                dist[v.to] = dist[u] + v.weight;

                if (v.weight == 0) {
                    q.push_front(v.to);
                } else {
                    q.push_back(v.to);
                }
            }
        }
    }
};

void solve() {
    cin >> n >> m;
    graph = vector<vector<edge>>(n + 1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }
    dist = vector<int>(n + 1, oo);
    int source = 0;
    bfs(source);
    for (int i = 0; i < n; i++) {
        cout << dist[i] << " ";
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}