#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
char a[55][55];
bool visited[55][55];
int dist[55][55];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
int oo = 1e9;
int ans = oo;

struct node {
    int r, c, d;
};
vector<node> v; // can put dynamite;
vector<node> g; // position of gold
queue<node> q;

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

void printMatrix() {
    cout << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

bool isBoom(char c) {
    if('1' <= c && c <= '5') return true;
    return false;
}

int getTime() {
    int time = 0;
    for(node e: g) {
        time = max(time, dist[e.r][e.c]);
    }
    return time;
}


void exploit(int r, int c, int d, int val) {
    for(int dr = -d; dr <= d; dr++) {
        for(int dc = -d; dc <= d; dc++) {
            int nr = r + dr;
            int nc = c + dc;
            if(!inBound(nr, nc) || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            dist[nr][nc] = val;
            q.push({nr, nc, val});
        }
    }
}

void bfs(int r, int c) {
    exploit(r, c, 1, 1);
    while (!q.empty()) {
        node cn = q.front(); q.pop();
        for(int i = 0; i <= 3; i++) {
            int nr = cn.r + dr[i];
            int nc = cn.c + dc[i];
            if(!inBound(nr, nc) || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            dist[nr][nc] = cn.d + 1;
            q.push({nr,nc, dist[nr][nc]});
        }
        if(isBoom(a[cn.r][cn.c])) {
            exploit(cn.r, cn.c, a[cn.r][cn.c] - '0', dist[cn.r][cn.c] + 1);
        }
    }
}


void clearData() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            visited[i][j] = false;
            dist[i][j] = oo;
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == '.') {
                v.push_back({i, j});
            }
            if(a[i][j] == 'G') {
                g.push_back({i, j});
            }
        }
    }
    if(v.empty() || g.empty()) {
        cout << 0 << endl;
        return;
    }
    for(node e: v) {
        clearData();
        bfs(e.r, e.c);
        ans = min(ans, getTime());
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}