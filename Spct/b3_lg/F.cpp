#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
int a[705][705];
int visited[705][705];
bool isHill;

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

void dfs(int r, int c) {
    visited[r][c] = true;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <=1 ; dc++) {
            if(dr == 0 && dc == 0) continue;
            int nr = r + dr;
            int nc = c + dc;

            if(!inBound(r, c)) continue;
            // if neighbor is greater => not a hill
            if(isHill && a[r][c] < a[nr][nc]) isHill = false;

            // if same height is same hill
            if(a[r][c] == a[nr][nc] && !visited[nr][nc]) dfs(nr, nc);
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int cnt = 0; 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
           if(!visited[i][j])  {
            isHill = true; // mark is a hill at first
            dfs(i, j);
            if(isHill) cnt++;
           }
        }
    }
    cout << cnt << endl;

}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();
    return 0;
}