#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define endl '\n';

using namespace std;
/**
 * Dijkstra’s algorithm finds shortest paths from the starting node to all nodes of the
 * graph, like the Bellman–Ford algorithm. The benefit of Dijkstra’s algorithm is that it
 * is more efficient and can be used for processing large graphs.
 * 
 * The algorithm requires that there are no negative weight edges in the graph
 * 
 * TC: O(n + m * log(m)) // n: number of vertex, m: number of edges
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

struct cmp {
    bool operator()(int a , int b) {
        return  a < b; // reverse with cmp in vector
    }
};
vector<edge> graph[100005]; // max of vertices
vi dist;
vb visited;

// ********** DIJKSTRA ALGORITHM **********//
void dijkstra(int start) {
    dist.assign(n + 1, oo);
    visited.assign(n + 1, false);
    dist[start] = 0;

    priority_queue<int, vi, cmp> q;
    q.push(x);
    while(!q.empty()) {
        int a = q.top(); q.pop();
        if(visited[a]) continue;
        visited[a] = true;
        for(auto e: graph[a]) {
            int newDist = dist[e.a] + e.d;
            if(newDist < dist[e.b]) {
                dist[e.b] = newDist;
                q.push(e.b);
            }
        }

    }
    for(int i = 1; i <= n; i++) {
        cout << x << " " << i << " " << dist[i] << '\n';
    }
}


void solve() {
    cin >> n >> m >> x; 
    int a, b, d;
    while(m--) {
        cin >> a >> b >> d;
        graph[a].pb({a, b, d});
        graph[b].pb({b, a, d}); // undirected graph
    }
    dijkstra(x);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
