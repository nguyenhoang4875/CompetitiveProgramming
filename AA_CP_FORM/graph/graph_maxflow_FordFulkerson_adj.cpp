#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Max flow in graph using adjency adjacency list edges as graph
 * Solution: Using Maximum flow - Ford-Fulkerson and Edmonds-Karp algorithm
 *
 * TC: O(V^2 * E)
 */
/*
Example input:
6 9
0 1 7
0 2 4
1 3 5
1 4 3
2 1 3
2 4 2
3 5 8
4 3 3
4 5 5

=> maxFlow = 10
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

int n, m;  // n: vertices, m: edges
vector<vector<int>> capacity;
vector<vector<int>> adj;

int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);  // also use as visited array
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, oo});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxFlow(int s, int t) {
    int flow = 0;
    vector<int> parent(n);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void solve() {
    cin >> n >> m;
    adj = vector<vector<int>>(n + 1);
    capacity = vector<vector<int>>(n + 1, vector<int>(n + 1));
    For(i, 1, m) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back(v);
        capacity[u][v] = d;
    }
    cout << maxFlow(0, n - 1) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}