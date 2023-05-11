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

struct node {
    int r, c, d;
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
    q.push({r, c, 0});
    while (!q.empty()) {
        node cn = q.top(); q.pop();
        visited[cn.r][cn.c] = true;
        if(cn.r == dr && cn.c == dc) return cn.d;
        for (int i = 0; i <= 3; i++) {
            int nr = cn.r + dx[i];
            int nc = cn.c + dy[i];
            if(!inBound(nr, nc) || visited[nr][nc]) continue;
            int val = 1;
            if(a[nr][nc] == '+') val = 4;
            int newDist = cn.d + val;
            if(newDist < dist[nr][nc]) {
                dist[nr][nc] = newDist;
                q.push({nr, nc, newDist});
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
            visited[i][j] = false;
        }
    }

    cout << bfs(sr, sc) << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}