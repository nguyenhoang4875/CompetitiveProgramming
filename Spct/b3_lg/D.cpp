#include<bits/stdc++.h>
#define int long long

/**
 * http://10.220.48.248/problem/cowandrope
*/
using namespace std;

int tcs, n, m;
bool used[255];
unordered_set<int> v[255];
set<int> nodes;

void dfs(int s) {
    if(used[s]) return;
    used[s] = true;
    nodes.erase(s);
    for (int e: v[s]) {
        dfs(e);
    }
}

void solve() {
    cin >> n;
    cin >> m;
    nodes.clear();
    int s, e;
    for(int i = 1; i <= n; i++) nodes.insert(i);
    for (int i = 1; i <= m; i++) {
        cin >> s;
        cin >> e;
        v[s].insert(e);
        v[e].insert(s);
    }

    dfs(1);
    if(nodes.empty()) {
        cout << 0 << endl;
        return;
    }
    for (int e: nodes) {
        cout << e << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}