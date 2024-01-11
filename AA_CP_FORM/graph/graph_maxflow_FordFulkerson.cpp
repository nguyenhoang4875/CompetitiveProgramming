#include <bits/stdc++.h>
#define int long long
/**
 * Problem: Max flow in graph using array as graph
 * Solution: Using Maximum flow - Ford-Fulkerson and Edmonds-Karp algorithm
 *
 * TC: O(V^2 * E)
 */

using namespace std;
const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;

bool bfs(vector<vector<int>>& rGraph, int n, int s, int t, vector<int>& parent) {
    bool visited[n + 1];
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                if (v == t) {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

// Returns the maximum flow from s to t in the given graph
int fordFulkerson(vector<vector<int>>& graph, int n, int s, int t) {
    int u, v;
    vector<vector<int>> rGraph(n + 1, vector<int>(n + 1));  // Residual graph where rGraph[i][j]
    for (u = 0; u < n; u++) {
        for (v = 0; v < n; v++) {
            rGraph[u][v] = graph[u][v];
        }
    }

    vector<int> parent(n);  // This array is filled by BFS and to
    int max_flow = 0;

    while (bfs(rGraph, n, s, t, parent)) {
        int path_flow = INT_MAX;
        // find the path_flow weight
        for (v = t; v != s; v = parent[v]) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        // re-calculate the graph
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            rGraph[prev][cur] -= path_flow;
            rGraph[cur][prev] += path_flow;
            cur = prev;
        }
        max_flow += path_flow;
    }

    return max_flow;
}

int32_t main() {
    int n = 6;
    vector<vector<int>> graph = {{0, 16, 13, 0, 0, 0}, {0, 0, 10, 12, 0, 0}, {0, 4, 0, 0, 14, 0},
                                 {0, 0, 9, 0, 0, 20},  {0, 0, 0, 7, 0, 4},   {0, 0, 0, 0, 0, 0}};
    cout << "The maximum possible flow is " << fordFulkerson(graph, n, 0, 5);  // max flow = 23
    return 0;
}