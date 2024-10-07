#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;

void dfs(int u, vector<bool>& visited, vector<vector<int> >& adj, vector<bool>& s,
         vector<int>& path, int& num) {
    if (visited[u] || s[u]) return;
    path.push_back(u);
    visited[u] = true;
    num++;
    for (auto v : adj[u]) dfs(v, visited, adj, s, path, num);
}

vector<int> cal(int n, vector<bool>& s, vector<vector<int> >& adj) {
    vector<int> res(n + 5, 0);
    vector<int> val(n + 5, 0);
    vector<bool> visited(n + 5, false);
    for (int i = 1; i <= n; i++) {
        if (s[i] == false && visited[i] == false) {
            vector<int> path;
            int num = 0;
            dfs(i, visited, adj, s, path, num);
            for (auto u : path) {
                val[u] = num;
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        if (s[u]) {
            for (auto v : adj[u]) {
                res[u] += val[v];
            }
            res[u]++;
        }
    }
    fill(visited.begin(), visited.end(), false);
    for (int i = 1; i <= n; i++) {
        if (s[i] == false && visited[i] == false) {
            vector<int> path;
            int num = 0;
            dfs(i, visited, adj, s, path, num);
            int tmp = 0;
            for (auto u : path) {
                for (auto v : adj[u]) {
                    if (s[v]) {
                        tmp += res[v] - num;
                    }
                }
            }
            for (auto u : path) {
                res[u] = tmp;
            }
        }
    }
    return res;
}

void solve() {
    int na, nb, n, m;
    int si, u, v;
    vector<int> a, b;
    for (int t = 1; t <= 2; t++) {
        cin >> n >> m;
        if (t == 1)
            na = n;
        else
            nb = n;
        vector<bool> s(n + 5, false);
        vector<vector<int> > adj(n + 5);
        for (int i = 1; i <= m; i++) {
            cin >> si;
            s[si] = true;
        }
        for (int i = 1; i <= n - 1; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (t == 1)
            a = cal(n, s, adj);
        else
            b = cal(n, s, adj);
    }
    //    for (int i= 1; i <= na; i++) {
    //        cout << a[i] << " ";
    //    }
    //    cout << "\n";
    //    for (int i= 1; i <= nb; i++) {
    //        cout << b[i] << " ";
    //    }
    //    cout << "\n";
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 1; i <= nb; i++) {
        sum1 = (sum1 + b[i]) % mod;
        sum2 = (sum2 + b[i] * i) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= na; i++) {
        ans = (ans + a[i] * (i * sum1 + sum2)) % mod;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}