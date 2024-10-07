#include <bits/stdc++.h>

using namespace std;
#define int long long
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)

struct Graph {
   private:
    int n;

    vector<vector<int> > flow;
    vector<vector<int> > adj;
    vector<int> parent;

    int maxFlow;

    bool bfs(int source, int sink, vector<int>& parent) {
        vector<bool> visited(n + 5, false);
        queue<int> q;
        q.push(source);
        visited[source] = true;
        parent[source] = -1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == sink) return true;
            for (auto v : adj[u]) {
                if (visited[v] == false && flow[u][v] != 0) {
                    q.push(v);
                    visited[v] = true;
                    parent[v] = u;
                }
            }
        }
        return false;
    }

   public:
    Graph(int si) {
        n = si;
        flow.resize(si + 5);
        for (auto& t : flow) t.resize(si + 5);
        adj.resize(si + 5);
        parent.resize(si + 5);
        maxFlow = 0;
    }

    void addEdge(int u, int v, int w) {
        flow[u][v] = w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void updateEdge(int u, int v, int w) { flow[u][v] += w; }

    int getMaxFlow() {
        //            cout << "start\n";
        while (bfs(0, 401, parent)) {
            int curFlow = 1e18;
            for (int v = 401; parent[v] != -1; v = parent[v]) {
                int u = parent[v];
                curFlow = min(curFlow, flow[u][v]);
            }

            for (int v = 401; parent[v] != -1; v = parent[v]) {
                int u = parent[v];
                flow[u][v] -= curFlow;
                flow[v][u] += curFlow;
            }

            maxFlow += curFlow;
            // cout << maxFlow << "\n";
        }
        // cout << "end\n";

        return maxFlow;
    }
};

void solve() {
    int n, m, g, x;
    cin >> n >> m;
    vector<int> l(m + 5), u(m + 5);
    Graph graph(401);
    FOR(i, 1, n) {
        cin >> g;
        FOR(j, 1, g) {
            cin >> x;
            graph.addEdge(i, x + 200, 1);
        }
    }
    int sumL = 0;
    FOR(j, 1, m) {
        cin >> l[j] >> u[j];
        graph.addEdge(j + 200, 401, l[j]);
        sumL += l[j];
    }
    FOR(i, 1, n) graph.addEdge(0, i, 0);
    int b;
    for (b = 1; b <= m; b++) {
        FOR(i, 1, n) graph.updateEdge(0, i, 1);
        int maxFlow = graph.getMaxFlow();
        if (maxFlow < sumL) {
            cout << "-1 ";
        } else {
            break;
        }
    }

    FOR(j, 1, m) { graph.updateEdge(j + 200, 401, u[j] - l[j]); }

    for (; b <= m; b++) {
        int maxFlow = graph.getMaxFlow();

        cout << maxFlow << " ";

        FOR(i, 1, n) graph.updateEdge(0, i, 1);
    }

    cout << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}