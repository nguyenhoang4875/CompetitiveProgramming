#include <bits/stdc++.h>
#define int long long

using namespace std;

int m, n;
int a[255][255];
int cnt = 0;
map<int, int> mi;
int dt[5] = {1, 0, -1, 0, 1};
int num = 0;

bool in_bound(int r, int c) {
    if(r < 1 || r > m || c < 1 || c > n) return false;
    return true;
}

void dfs(int r, int c) {
    if(!in_bound || a[r][c] == 0) return;
    a[r][c] = 0;
    cnt++;
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
}

void solve() {
     while (true) {
        mi.clear();
        num = 0;
        cin >> m >> n;
        if(m == 0 || n == 0) break;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n ; j++) {
                cin >> a[i][j];
            }
        }

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n ; j++) {
                cnt = 0;
                if(a[i][j] == 1) {
                    dfs(i, j);
                    num++;
                    mi[cnt]++;
                }
            }
        }

        cout << num << endl;
        for (auto e: mi) {
            cout << e.first << " " << e.second << endl;
        } 
     } 
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}