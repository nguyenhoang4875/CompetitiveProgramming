#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/893/problem/C
 * Solution: Using DSU or dfs to find min of each group
*/

struct Dsu {
    Dsu(){};
    Dsu(int n) : parent(n){};

    vector<int> parent;
    void makeSet(int v) {
        parent[v] = v;
    }

    int findSet(int v) {
        return parent[v] = (v == parent[v] ? v : findSet(parent[v]));
    }

    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            parent[a] = parent[b] = min(a, b);
        }
    }
};

int n, m;

int cost[100005];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    Dsu dsu(n + 1);
    for (int i = 1; i <= n; i++) dsu.makeSet(i);
    int u, v;
    while (m--) {
        cin >> u >> v;
        dsu.unionSet(u, v);
    }

    map<int, int> mpi;
    for (int i = 1; i <= n; i++) {
        int x = dsu.findSet(i);
        if (mpi.count(x)) {
            mpi[x] = min(mpi[x], cost[i]);
        } else {
            mpi[x] = cost[i];
        }
    }
    int ans = 0;
    for (auto e : mpi) {
        ans += e.second;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}