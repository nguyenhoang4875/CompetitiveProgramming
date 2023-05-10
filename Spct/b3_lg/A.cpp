#include<bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, m;
bool used[100005];
unordered_set<int> v[100005];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int f = q.front(); q.pop();
        if(used[f]) continue;
        used[f] = true;
        for (int e: v[f]) {
            if(!used[e]) q.push(e);
        }
    }
}

void dfs(int s) {
    if(v[s].empty() || used[s]) return;
    used[s] = true;
    for (int e: v[s]) {
        dfs(e);
    }
}

void solve() {
    cin >> n;
    cin >> m;
    int s, e;
    for (int i = 1; i <= m; i++) {
        cin >> s;
        cin >> e;
        v[s].insert(e);
        v[e].insert(s);
    }
    int cnt = 0;
    for (int i = 1; i <= n ; i++) {
        if(!used[i]) {
            bfs(i);
            cnt++;
        }
    }
    cout << cnt << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}