#include <bits/stdc++.h>
#define int long long

/**
 * https://www.spoj.com/problems/RDR2_1/
*/

using namespace std;

int tcs, n, m;
char a[1005][1005];
bool visited[1005][1005];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
int dist = 0;
bool found = false;

struct point {
    int r, c;
};

struct node {
    int r, c, d;
    string path;
};

point ath;
vector<node> vex;

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

bool onBound(int r, int c) {
    if(r == 1 || r == n || c == 1 || c == m) return true;
    return false;
}

void reset_visited() {
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = false;
        }
    }
}

void bfs() {
    queue<node> q;
    q.push({ath.r, ath.c, 0, ""});
    visited[ath.r][ath.c] = true;

    while (!q.empty()) {
        node t = q.front();
        q.pop();
        if(onBound(t.r, t.c)) vex.push_back(t);

        for (int i = 0; i < 4; i++) {
            int nr = t.r + dr[i];
            int nc = t.c + dc[i];
            if(!inBound(nr, nc) || visited[nr][nc] || a[nr][nc] != '.') continue;
            visited[nr][nc] = true;
            node tmp;
            if(dr[i] == 1)  tmp = {nr, nc, t.d + 1, t.path + "D"};
            if(dr[i] == -1) tmp = {nr, nc, t.d + 1, t.path + "U"};
            if(dc[i] == 1)  tmp = {nr, nc, t.d + 1, t.path + "R"};
            if(dc[i] == -1) tmp = {nr, nc, t.d + 1, t.path + "L"};
            q.push(tmp);
        }
    }
}
void bfs2(node e) {
    e.d = 0;
    queue<node> q;
    q.push({e.r, e.c, 0});
    visited[e.r][e.c] = true;

    while (!q.empty()) {
        node t = q.front();
        q.pop();
        if(a[t.r][t.c] == 'S') {
            if(t.d <= dist) found = false;
        }

        for (int i = 0; i < 4; i++) {
            int nr = t.r + dr[i];
            int nc = t.c + dc[i];
            if(!inBound(nr, nc) || visited[nr][nc] || a[nr][nc] == '#') continue;
            visited[nr][nc] = true;
            node tmp = {nr, nc, t.d + 1};
            q.push(tmp);
        }
    }
}

void solve() {
    cin >> n >> m;
    vex.clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == 'A') ath =  {i, j};
        }
    }
    bfs();
    if(vex.empty())  {
        cout << "NO" << endl;
        return;
    }

    sort(vex.begin(), vex.end(), [&](node n1, node n2) {
        return n1.d < n2.d;
    });

    for (node e: vex) {
        dist = e.d;
        found = true;
        reset_visited();
        bfs2(e);
        if(found) {
            cout << "YES" << endl;
            cout << e.d << endl;
            cout << e.path << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}