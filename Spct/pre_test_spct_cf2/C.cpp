#include<bits/stdc++.h>

using namespace std;

/**
 * Need to add k block('X') to the maze
 * s: total of empty cell('.') 
 * Solution: dfs or bfs to find (s - k) connected empty cell('.') first
 * Then fill the the other empty cell ('.') to ('X')
*/


int n, m, k;
char a[505][505];
bool visited[505][505];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int cnt, s;

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

void dfs(int r, int c) {
    if(!inBound(r, c) || visited[r][c] || a[r][c] == '#') return;
    if(cnt == (s - k)) return;
    cnt++;
    visited[r][c] = true;
    dfs(r - 1, c);
    dfs(r + 1, c);
    dfs(r, c - 1);
    dfs(r, c + 1);
}

void solve() {
    cin >> n >> m >> k;
    int fx, fy;
    bool isFirst = false;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == '.') {
                s++;
                if(!isFirst) fx = i, fy = j;
            }
        }
    }
    
    dfs(fx, fy);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == '.' && !visited[i][j]) a[i][j] = 'X';
            cout << a[i][j];
        }
        cout << "\n";
    }

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}