#include<bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
int a[105][105];

bool inBound(int r, int c) {
    if (r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}
void bfs(int r, int c) {
    if(!inBound(r, c) || a[r][c] == 0) return;
    a[r][c] = 0;
    for (int dr = -1; dr <= 1; dr++) {
        for (int dc = -1; dc <= 1; dc++) {
            if(dr == 0 && dc == 0) continue;
            bfs(r + dr, c + dc);
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
            if(a[i][j] != 0) {
               bfs(i, j);
               cnt++;
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