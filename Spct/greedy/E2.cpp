#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/893/problem/C
 * Solution: Using DSU or dfs to find min of each group
*/


int n, m;

int cost[100005];
vector<int> g[100005];
bool visited[100005];
int oo = 2e9;

int res = oo;

void dfs(int v) {
    if(visited[v]) return;
    res = min(res, cost[v]);
    visited[v] = true;
    for(int e: g[v]) {
        if(!visited[e]) dfs(e);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    int u, v;
    while (m--) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        res = oo;
        if(!visited[i]) {
            dfs(i);
        }
        if(res != oo) ans += res;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}