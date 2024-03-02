#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Given a graph check the graph is bipartite or not
 * A Bipartite Graph is a graph whose vertices can be divided into two
 * independent sets, U and V such that every edge (u, v) either connects a
 * vertex from U to V or a vertex from V to U
 *
 * Solution: DFS
 * TC: O(V + E)
 * MC: O(V)
 */

int n, m;
vector<vector<int>> graph;
vector<int> color;  // -1: unset color, 0: black, 1: white
bool hasCycle;

bool dfs(int cur, int par, int cl) {
    color[cur] = cl;
    for (auto x : graph[cur]) {
        if (color[x] == -1) {
            bool sub = dfs(x, cur, 1 - cl);
            if (sub == false) {
                return false;
            }
        } else if (x != par and color[x] == cl) {
            return false;
        }
    }
    return true;
}

int addEdge(int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);  // remove if directed graph
}

void solve() {
    cin >> n >> m;
    graph.clear();
    graph.resize(n + 1);
    color = vector<int>(n + 1, -1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    bool ans = true;
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            ans = dfs(i, -1, 0);
        }
        if (!ans) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes"
         << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}