#include <bits/stdc++.h>
using namespace std;
#define int long long
#define size(a) (int)(a.size())
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define FORD(i, a, b) for (int i = a; i >= b; i--)

struct Graph {
   private:
    int n;
    vector<vector<int> > graph;
    bool bfs(vector<vector<int> >& graph, int s, int t, vector<int>& parent) {
        vector<bool> visited(n + 5, false);
        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (u == t) {
                return true;
            }

            for (int v = 0; v <= n; v++) {
                if (visited[v] == false && graph[u][v] > 0) {
                    q.push(v);
                    visited[v] = true;
                    parent[v] = u;
                }
            }
        }
        return false;
    }

   public:
    Graph(int size) {
        n = size;
        graph.resize(n + 5);
        for (auto& tmp : graph) tmp.resize(n + 5, 0);
    }
    void addEdge(int u, int v, int w) { graph[u][v] += w; }
    int getFlow(int u, int v) { return graph[u][v]; }
    // only call this 1 time
    int getMaxFlow(int s, int t) {
        int maxFlow = 0;
        vector<int> parent(n + 5);
        while (bfs(graph, s, t, parent)) {
            int pathFlow = 1e18;
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                pathFlow = min(pathFlow, graph[u][v]);
            }
            for (int v = t; v != s; v = parent[v]) {
                int u = parent[v];
                graph[u][v] -= pathFlow;
                graph[v][u] += pathFlow;
            }
            maxFlow += pathFlow;
        }
        return maxFlow;
    }
};

bool getBit(int n, int i) { return (n >> i) & 1; }

void solve() {
    int n, na, nb, nc, ma, mb, mc, tmp;
    cin >> n;

    Graph g(11);

    cin >> na >> nb >> nc;

    vector<int> group_id(n + 5, 0);

    cin >> ma;
    for (int i = 1; i <= ma; i++) {
        cin >> tmp;
        group_id[tmp] += 1;
    }
    cin >> mb;
    for (int i = 1; i <= mb; i++) {
        cin >> tmp;
        group_id[tmp] += 2;
    }
    cin >> mc;
    for (int i = 1; i <= mc; i++) {
        cin >> tmp;
        group_id[tmp] += 4;
    }

    vector<vector<int> > groupCategory(8);
    for (int i = 1; i <= n; i++) {
        groupCategory[group_id[i]].push_back(i);
    }

    for (int i = 1; i <= 7; i++) {
        g.addEdge(0, i, size(groupCategory[i]));
        if (getBit(i, 0)) g.addEdge(i, 8, 1e18);
        if (getBit(i, 1)) g.addEdge(i, 9, 1e18);
        if (getBit(i, 2)) g.addEdge(i, 10, 1e18);
    }

    g.addEdge(8, 11, na);
    g.addEdge(9, 11, nb);
    g.addEdge(10, 11, nc);

    cout << g.getMaxFlow(0, 11) << "\n";
    for (int i = 1; i <= 7; i++) {
        for (int j = 8; j <= 10; j++) {
            for (int k = g.getFlow(j, i); k--; k > 0) {
                cout << groupCategory[i].back() << " " << (char)(j - 8 + 'A') << "\n";
                groupCategory[i].pop_back();
            }
        }
    }
}

int32_t main() {
    //	freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
