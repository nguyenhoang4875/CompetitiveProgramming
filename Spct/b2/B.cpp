#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
int dx[4] = {0, 0 , -1, 1};
int dy[4] = {-1, 1 , 0, 0};

struct color {
    char c; // color
    int b, s; // block, sum
};
vector<color> ans(3);

char a[105][105];
bool visited[105][105];

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m ;j++) {
            visited[i][j] = false;
        }
    }
}

bool inBound(int r, int c) {
    if(r < 0 || r >= n || c < 0 || c >= m) return false;
    return true;
}

void bfs(int r, int c, int cl) {
    visited[r][c] = true;
    queue<pair<int, int>> q;
    q.push({r, c});
    while(!q.empty()) {
        pair<int, int> cn = q.front();
        q.pop();
        for (int i = 0; i <= 3; i++) {
            int x = cn.first + dx[i];
            int y = cn.second + dy[i];
            if(!inBound(x, y) || visited[x][y] || a[x][y] != cl) continue;
            visited[x][y] = true;
            q.push({x, y});
        }
    }
}

void solve() {
    ans.resize(3);
    ans[0] = {'R', 0, 0};
    ans[1] = {'G', 0, 0};
    ans[2] = {'B', 0, 0};
    cin >> n >> m;
    string s;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j];
            if(s[j] == 'R') ans[0].s++;
            if(s[j] == 'G') ans[1].s++;
            if(s[j] == 'B') ans[2].s++;
        }
    }

    reset();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j] == 'R' && !visited[i][j]) {
                bfs(i, j, a[i][j]);
                ans[0].b++;
            }
        }
    }
    reset();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j] == 'G' && !visited[i][j]) {
                bfs(i, j, a[i][j]);
                ans[1].b++;
            }
        }
    }
    reset();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(a[i][j] == 'B' && !visited[i][j]) {
                bfs(i, j, a[i][j]);
                ans[2].b++;
            }
        }
    }
    sort(ans.begin(), ans.end(), [&](color c1, color c2) {
        if(c1.b == c2.b) {
            if(c1.s == c2.s) return c1.c > c2.c;
            return c1.s > c2.s;
        }
        return c1.b > c2.b;
    });

    cout << ans[0].c << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}