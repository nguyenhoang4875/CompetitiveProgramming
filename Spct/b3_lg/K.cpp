#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
char a[105][105];
int sr, sc, dr, dc;
int dist[105][105];
bool visited[105][105];
int oo = 1e9;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int hpl[105][105];

struct node {
    int r, c, d, hp;
};

struct cmp {
    bool operator()(node& n1, node& n2) {
        return n1.d > n2.d;
    }
};

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

int bfs(int r, int c) {
    visited[r][c] = true;
    dist[r][c] = 0;
    priority_queue<node, vector<node>, cmp> q;
    q.push({r, c, 0, 3});
    hpl[r][c] = 3;
    while (!q.empty()) {
        node cn = q.top(); q.pop();
        hpl[cn.r][cn.c] = cn.hp;
        for (int i = 0; i <= 3; i++) {
            int nr = cn.r + dx[i];
            int nc = cn.c + dy[i];
            int nhp = cn.hp;
            if(!inBound(nr, nc)) continue;
            if(a[nr][nc] == '+') {
                if(nhp > 1) --nhp;
                else continue;
            } 
            int newDist = cn.d + 1;
            if(newDist < dist[nr][nc] || nhp > hpl[nr][nc]) {
                dist[nr][nc] = min(newDist, dist[nr][nc]);
                hpl[nr][nc] = nhp;
                q.push({nr, nc, newDist, nhp});
            }
        }

    }
    return oo;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= m ; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'S') {
                sr = i;
                sc = j;
            }
            if(a[i][j] == 'D') {
                dr = i;
                dc = j;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j<= m; j++) {
            dist[i][j] = oo;
            hpl[i][j] = 0;
            visited[i][j] = false;
        }
    }

    bfs(sr, sc);
    if(dist[dr][dc] == oo) {
        cout << "-1\n";
        return;
    }
    cout << dist[dr][dc] << "\n";

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}