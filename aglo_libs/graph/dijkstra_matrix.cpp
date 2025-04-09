#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define endl '\n';

using namespace std;
/**
 * Dijkstra on matrix
 *
 * Dijkstra’s algorithm finds shortest paths from the starting node to all nodes
 * of the graph, like the Bellman–Ford algorithm. The benefit of Dijkstra’s
 * algorithm is that it is more efficient and can be used for processing large
 * graphs.
 *
 * The algorithm requires that there are no negative weight edges in the graph
 *
 * TC: O(n * n)
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
int n, m;
struct node {
    int r, c, d;  // position: x, y, value: d
};

struct cmp {
    bool operator()(node& n1, node& n2) {
        return n1.d > n2.d;  // reverse with cmp in vector
    }
};
int a[105][105];  // maximum number of n, m
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

vvi dist;
vvb visited;

bool inBound(int r, int c) {
    if (r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

// ********** DIJKSTRA ALGORITHM **********//
void dijkstra(int r, int c) {
    dist.assign(n + 1, vi(m + 1, oo));
    visited.assign(n + 1, vb(m + 1, false));
    dist[r][c] = a[r][c];
    priority_queue<node, vector<node>, cmp> q;
    q.push({r, c, a[r][c]});
    while (!q.empty()) {
        node nd = q.top();
        q.pop();
        visited[nd.r][nd.c] = true;
        int nr, nc;
        for (int i = 0; i <= 3; i++) {
            nr = nd.r + dr[i];
            nc = nd.c + dc[i];
            if (!inBound(nr, nc) || visited[nr][nc]) continue;
            int newDist = nd.d + a[nr][nc];
            if (newDist < dist[nr][nc]) {
                dist[nr][nc] = newDist;
                q.push({nr, nc, newDist});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    char c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[m][n];
        }
    }
    // dijkstra at start point
    dijkstra(1, 1);
    cout << dist[n][m] << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
