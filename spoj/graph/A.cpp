#include <bits/stdc++.h>
#define int long long

/**
 * https://www.spoj.com/problems/UOFTCE/
*/

using namespace std;

int tcs, n, m;
char a[105][105];
bool visited[105][105];
int dt[5] = {1, 0, -1, 0 , 1};

struct node {
    int r, c, d;
};
vector<node> vn;

bool in_bound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

int bfs(node s, node d) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = false;
        }
    }

    queue<node> q;
    s.d = 0;
    q.push(s);
    visited[s.r][s.c] = true;
    while (!q.empty()) {
        node t = q.front(); q.pop();
        if(t.r == d.r && t.c == d.c) return t.d;

        for (int i = 0; i < 4; i++) {
            int nr = t.r + dt[i];
            int nc = t.c + dt[i+1];

            if(!in_bound(nr, nc) || visited[nr][nc] || a[nr][nc] == '#') continue;
            visited[t.r][t.c] = true;
            q.push({nr, nc, t.d + 1});
        }
    }
    return 0;
    
}

void solve() {
    vn.clear();
    cin >> n >> m;
    node s;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m;  j++) {
            cin >> a[i][j];
            if(a[i][j] == 'S') {
                vn.push_back({i, j, 0});
            }
            if(a[i][j] == 'C') {
                s = {i, j , 0};
            }
        }
    }
    int ans = 0;
    int k = vn.size();
    ans = k * 60;
    int mx = 0;
    for (int i = 0; i < k; i++) {
        int dis = bfs(s, vn[i]);
        ans += 2 * dis;
        mx = max(mx, dis);
    }
    ans -= mx;
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}