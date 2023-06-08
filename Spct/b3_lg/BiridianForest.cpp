#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, m;
char a[1005][1005];
bool visited[1005][1005];
int dist[1005][1005];
int oo = 1e15;

int dr[4] = {0, 0 ,-1, 1};
int dc[4] = {-1, 1, 0, 0};

int sr, sc;
int er, ec;
struct node {
    int r, c, num;
};
vector<node> v;

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

void bfs(int r, int c) {
    queue<node> q;
    q.push({r, c, 0});
    dist[r][c] = 0;
    visited[r][c] = true;
    while (!q.empty()) {
        node cn = q.front(); q.pop();
        for (int i = 0 ; i <= 3; i++) {
            int nr = cn.r + dr[i];
            int nc = cn.c + dc[i];
            if(!inBound(nr, nc) || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            int nd = cn.num + 1;
            q.push({nr, nc, nd});
            dist[nr][nc] = nd;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'S') sr = i, sc = j;
            if(a[i][j] == 'E') er = i, ec = j;
            if(a[i][j] == 'T') visited[i][j] = true;
            if('1' <= a[i][j] && a[i][j] <= '9') {
                v.push_back({i, j, a[i][j] - '0'});
            }
        }
    }
    bfs(er, ec);
    int sDist = dist[sr][sc];
    int cnt = 0;
    for (node e: v) {
        if(dist[e.r][e.c] == 0 || dist[e.r][e.c] > sDist) continue;
        cnt += e.num;
    }
    cout << cnt << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}