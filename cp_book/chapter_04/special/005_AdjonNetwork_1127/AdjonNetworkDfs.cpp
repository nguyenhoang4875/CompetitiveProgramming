#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dist(n), vis(n), par(n);
    int token = 1;
    int far;

    function<void(int)> dfs = [&](int u) {
        vis[u] = token;
        if (dist[u] > dist[far]) far = u;
        for (int v : adj[u]) {
            if (vis[v] != token) {
                dist[v] = dist[u] + 1;
                par[v] = u;
                dfs(v);
            }
        }
    };

    auto find_farthest = [&](int start) {
        far = start;
        vis[start] = token;
        dist[start] = 0;
        par[start] = -1;
        dfs(start);
        ++token;
        return far;
    };

    vector<int> centers, radii;

    for (int i = 0; i < n; ++i) {
        if (vis[i]) continue;

        int t1 = find_farthest(i);
        int t2 = find_farthest(t1);

        vector<int> path;
        for (int v = t2; v != -1; v = par[v]) 
            path.push_back(v);

        int center = path[path.size() / 2];
        int radius = path.size() / 2;

        centers.push_back(center);
        radii.push_back(radius);
    }

    int k = centers.size();
    if (k <= 1) {
        cout << (k ? radii[0] * 2 : 0) << '\n';
        return 0;
    }

    int best = max_element(radii.begin(), radii.end()) - radii.begin();

    for (int i = 0; i < k; ++i) {
        if (i != best) {
            adj[centers[best]].push_back(centers[i]);
            adj[centers[i]].push_back(centers[best]);
        }
    }

    cout << dist[find_farthest(find_farthest(centers[best]))] << '\n';
}