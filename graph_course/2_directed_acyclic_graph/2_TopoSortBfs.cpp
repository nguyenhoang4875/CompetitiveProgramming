#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Topological Order
 * Solution: Using bfs
 *
 * TC: O(n)
 * MC: O(n)
 */

int n, m;
vector<vector<int>> graph;
vector<int> topoSort;
vector<int> inDegree;

void bfs(queue<int> q) {
    while (!q.empty()) {
        int cur = q.front();
        topoSort.push_back(cur);
        q.pop();

        for (auto x : graph[cur]) {
            inDegree[x]--;
            if (inDegree[x] == 0) {
                q.push(x);
            }
        }
    }
}

void addEdge(int u, int v) { graph[u].push_back(v); }

void solve() {
    cin >> n >> m;
    graph = vector<vector<int>>(n + 1);
    inDegree = vector<int>(n + 1, 0);

    while (m--) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
        inDegree[v]++;
    }
    topoSort = vector<int>();
    queue<int> q;

    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    bfs(q);

    for (auto e : topoSort) {
        cout << e << " ";
    }
    cout << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}