#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Bellman-Ford Algorithm
 * The Bellman–Ford algorithm finds shortest paths from a starting node to all nodes
 * of the graph. The algorithm can process all kinds of graphs, provided that the graph
 * does not contain a cycle with negative length. If the graph contains a negative cycle,
 * the algorithm can detect this.
 * 
 * The weight edges can be negative
 * 
 * Note that this algorithm can be used to search for a negative cycle
 * in the entire graph regardless of the starting node
 * This source for directed graph.
 * 
 * TC: O(n * m) // n: number of vertices, m: number of edges
 * MC: O(m)
 *
*/

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//
const int oo = 1e9;
int n, m, x;
struct edge {
    int a, b, d; // from: a, to: b, distance: d
};
vector<edge> graph[100005]; // max of vertices
vi dist;

// ********** BELLMAN-FORD ALGORITHM **********//
void bellmanFord(int start) {
    dist.assign(n + 1, oo);
    dist[start] = 0;
    for(int i = 1; i <= n; i++) {
        for(auto e: graph[i]) {
            dist[e.b] = min(dist[e.b], dist[e.a] + e.d);
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << x << " " << i << " " << dist[i] << '\n';
    }
}

// check is Negative Cycle Bellman-Ford
bool isNegCycleBellmanFord(int start) {
    bellmanFord(start);

    for(int i = 1; i <= n; i++) {
        for(auto e: graph[i]) {
            // if we get a shorter path, then there is a cycle
            if(dist[e.a] != oo && dist[e.a] + e.d < dist[e.b]) {
                return true;
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m >> x; 
    int a, b, d;
    while(m--) {
        cin >> a >> b >> d;
        graph[a].pb({a, b, d});
        //graph[b].pb({b, a, d}); // undirected graph
    }
    bellmanFord(x);
    cout << "is Negative Cycle: " << isNegCycleBellmanFord(x) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
