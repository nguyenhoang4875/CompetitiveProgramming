#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
int a[105][105];
int b[105][105];
set<int> si;
bool visited[105][105];

void clear_data() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m ; j++) {
            b[i][j] = 1;
        }
    }
}

void clear_visited() {
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= m; j++) {
            visited[i][j] = false;
        }
    }
}

void fill_bound(int val) {
    // row 1
    for (int i = 1; i <= m; i++) {
        if(a[1][i] <= val) b[1][i] = 0;
    }

    // row n
    for (int i = 1; i <= m; i++) {
        if(a[n][i] <= val) b[n][i] = 0;
    }

    // col 1
    for (int i = 1; i <= n; i++) {
        if(a[i][1] <= val) b[i][1] = 0;
    }
    // col m
    for (int i = 1; i <= n; i++) {
        if(a[i][m] <= val) b[i][m] = 0;
    }
}

bool in_bound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}
void dfs(int r, int c, int val) {
    if(!in_bound(r, c) || visited[r][c] || a[r][c] > val) return;
    visited[r][c] = true;
    b[r][c] = 0;
    dfs(r + 1, c, val);
    dfs(r - 1, c, val);
    dfs(r, c + 1, val);
    dfs(r, c -1, val);
}

void dfs2(int r, int c) {
    if(!in_bound(r, c)|| b[r][c] == 0) return;
    b[r][c] = 0;
    dfs2(r + 1, c);
    dfs2(r - 1, c);
    dfs2(r, c + 1);
    dfs2(r, c -1);
}

void print_array() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
    cin >> n >> m;
    // cout << n << " " << m << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            si.insert(a[i][j]);
        }
    }

    for (int val: si) {
        // cout << "val = " << val << endl;
        clear_visited();
        clear_data();
        fill_bound(val);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m ; j++) {
                if(b[i][j] == 0 && !visited[i][j]) {
                    dfs(i, j, val);
                }
            }
        }
        // print_array();
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m ; j++) {
                if(b[i][j] == 1) {
                    dfs2(i, j);
                    cnt++;
                    if(cnt >= 2) {
                        cout << val << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}