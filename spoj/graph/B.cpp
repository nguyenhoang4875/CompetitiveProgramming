#include <bits/stdc++.h>
#define int long long
/**
 * https://www.spoj.com/problems/NAKANJ
*/

using namespace std;

int tcs, n = 8;
int sr, sc, dr, dc;
int a[10][10];
int dist[10][10];
bool visited[10][10];

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

struct node {
    int r, c, d;
    string path;
};

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > n) return false;
    return true;
}

int bfs() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
    queue<node> q;
    q.push({sr, sc, 0, to_string(sr) + to_string(sc)});
    visited[sr][sc] = true;

    while(!q.empty()) {
        node t = q.front(); q.pop();
        if(t.r == dr && t.c == dc) {
            cout << t.path << endl;
            return t.d;
        } 
        for (int i = 0; i < 8; i++) {
            int nr = t.r + dx[i];
            int nc = t.c + dy[i];

            if(!inBound(nr, nc) || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc, t.d + 1, t.path +"  " + to_string(nr) + to_string(nc)});
        }
    }
    return -1;
}

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    sr = s1[0] - 'a' + 1;
    sc = s1[1] - '0';
    dr = s2[0] - 'a' + 1;
    dc = s2[1] - '0';

    cout << bfs() << endl;
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