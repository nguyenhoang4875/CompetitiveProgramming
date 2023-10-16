#include<bits/stdc++.h>
using namespace std;
#define int long long

struct edge {
    int u, v, w, oldW;
};

class Graph {
    private:
        vector<vector<vector<int>> > minPath;
        vector<vector<int> > matrix;
        int n;
        int oo = 1e18;
    public:
        Graph(int size) {
            n = size;
            minPath.resize(n+1, vector<vector<int> >(n+1));
            matrix.resize(n+1, vector<int>(n+1, oo));
        }
        void addEdge(int u, int v, int w) {
            matrix[u][v] = min(matrix[u][v], w);
            matrix[v][u] = min(matrix[v][u], w);
        }
        void addAdditionEdge(int u, int v, int w) {
            minPath[u][v].push_back(min(minPath[u][v].back(), w));
            minPath[v][u].push_back(min(minPath[v][u].back(), w));
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == u && j == v) continue;
                    if (i == v && j == u) continue; 
                    minPath[i][j].push_back(minPath[i][j].back());
                }
            }
        }
        void removeLastAdditionEdge() {
            if (minPath[1][1].size() <= 1) return;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    minPath[i][j].pop_back();
                }
            }
        }
        void calShortestPath() {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (i == j) minPath[i][j].push_back(0);
                    else minPath[i][j].push_back(matrix[i][j]);
                }
            }
            for (int k = 1; k <= n; k++) {
                for (int i = 1; i <= n; i++) {
                    for (int j = 1; j <= n; j++) {
                        if (minPath[i][k][0] + minPath[k][j][0] < minPath[i][j][0]) {
                            minPath[i][j][0] = minPath[i][k][0] + minPath[k][j][0];
                        }
                    }
                }
            }

            // for (int i = 1; i <= n; i++) {
            //     for (int j = 1; j <= n; j++) {
            //         if (minPath[i][j].back() == oo) cout << "oo ";
            //         else cout << minPath[i][j].back() << " ";
            //     }
            //     cout << "\n";
            // }
        }
        void updateShortestPath(int u, int v) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    // i -> u - > v - > j
                    if (minPath[i][u].back() + minPath[v][j].back() + minPath[u][v].back() < minPath[i][j].back()) {
                        minPath[i][j].back() = minPath[i][u].back() + minPath[v][j].back() + minPath[u][v].back();
                    }
                    // i -> ... -> v -> u -> ... -> j
                    if (minPath[i][v].back() + minPath[u][j].back() + minPath[v][u].back() < minPath[i][j].back()) {
                        minPath[i][j].back() = minPath[i][v].back() + minPath[u][j].back() + minPath[v][u].back();
                    }
                }
            }
        }
        int getSumShortestPath() {
            int res = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = i+1; j <= n; j++) {
                    if (minPath[i][j].back() != oo) res += minPath[i][j].back();
                    // cout << minPath[i][j].back();
                }
                // cout << "\n";
            }
            return res;
        }
};


void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    Graph graph(n);
    for (int i = 1; i <= m; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        graph.addEdge(x, y, c);
    }
    // Calculate shortest path
    graph.calShortestPath();
    // cout << graph.getSumShortestPath() << " first\n";

    while (q--) {
        int r, a, b, w;
        cin >> r;
        if (r == 2) cin >> a >> b >> w;
        if (r == 1) {
            cout << graph.getSumShortestPath() << " ";
        } else if (r == 2) {
            graph.addAdditionEdge(a, b, w);
            graph.updateShortestPath(a, b);
        } else {
            graph.removeLastAdditionEdge();
        }
    }
    cout << "\n";
}

int32_t main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}