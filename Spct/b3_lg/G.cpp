#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * https://oj.vnoi.info/problem/binladen
*/
int n, m;
int Up[3005][15]; // go up
int Right[3005][15]; // go right
int visited[3005][15];
int dist[3005][15];
int oo = 1e9;

struct node {
    int r, c, d;
};
struct cmp {
    bool operator()(node &n1, node& n2) {
        return n1.d > n2.d;
    }
};

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

void bfs() {
    priority_queue<node, vector<node>, cmp> q;
    for (int i = 1; i <= m; i++) {
        dist[1][i] = Up[1][i];
        q.push({1, i, Up[1][i]});
    }

    while (!q.empty()) {
        node cn = q.top(); q.pop();
        int nr, nc, newDist;
        for (int i = 0; i <= 3; i++) {
            nr = cn.r - 1;
            nc = cn.c;
            newDist = cn.d + Up[cn.r][cn.c];
            if(i == 1) {
                nr = cn.r + 1;
                nc = cn.c;
                newDist = cn.d + Up[cn.r + 1][cn.c];
            } else if(i == 2) {
                nr = cn.r;
                nc = cn.c + 1;
                newDist = cn.d + Right[cn.r][cn.c];

            } else if(i == 3) {
                nr = cn.r;
                nc = cn.c - 1;
                newDist = cn.d + Right[cn.r][cn.c - 1];
            }
            if(!inBound(nr, nc)) continue;
            if(newDist < dist[nr][nc]) {
                dist[nr][nc] = newDist;
                q.push({nr, nc, newDist});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> Up[i][j];
        }
        for (int j = 1; j <= m - 1; j++) {
            cin >> Right[i][j];
        }
    }

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] == oo;
        }
    }
    bfs();
    cout << dist[n][m];
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}