#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n, m;
int a[1005][1005];
int ans = 0;
int sum = 0;
bool visited[1005][1005];


void resetData() {
    for(int i = 1; i<= n; i++) {
        for (int j = 1; j <= m ;j++) {
            visited[i][j] = false;
        }
    }
    ans = 0;
    sum = 0;
}

bool inBound(int r, int c) {
    if (r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}
void dfs(int r, int c) {
    if(!inBound(r, c) || visited[r][c] || a[r][c] == 0) return;
    visited[r][c] = true;
    sum += a[r][c];
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
}

void solve() {
    resetData();
    cin >> n >> m;
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n ; i++) {
        for (int j = 1; j <= m; j++) {
            if(a[i][j] != 0  && !visited[i][j]) {
                sum = 0;
                dfs(i, j);
                ans = max(ans, sum);
            }
        }
    }
    cout << ans << endl;
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