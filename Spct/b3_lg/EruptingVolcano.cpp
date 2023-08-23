#include<bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

//*** START CODING ***//

int n, m;
int a[105][105];
int visited[105][105];
int cnt = 0;

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

void dfs(int r, int c, int val) {
    if(!inBound(r, c) || visited[r][c] || a[r][c] > val) return;
    visited[r][c] = true;
    cnt++;
    val = abs(a[r][c]);
    dfs(r + 1, c, val);
    dfs(r - 1, c, val);
    dfs(r, c + 1, val);
    dfs(r, c - 1, val);
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] < 0 && !visited[i][j]) {
                cnt = 0;
                int val = abs(a[i][j]);
                dfs(i, j, val);
                sum += cnt;
            }
        }
    }
    cout << sum << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}