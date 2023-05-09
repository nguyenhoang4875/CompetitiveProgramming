#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
char a[255][255];
bool visited[255][255];
int cntSheep, cntWolves;
int ansSheep = 0, ansWolves = 0;
bool touchBound;
bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}
bool onBound(int r, int c) {
    if(r == 1 || r == n || c == 1 || c == m) return true;
    return false;
}

void dfs(int r, int c) {
    if(!inBound(r, c) || visited[r][c] || a[r][c] == '#') return;
    visited[r][c] = true;
    if(onBound(r, c)) touchBound = true; 
    if(a[r][c] == 'k') cntSheep++;
    if(a[r][c] == 'v') cntWolves++;
    dfs(r - 1, c);
    dfs(r + 1, c);
    dfs(r, c - 1);
    dfs(r, c + 1);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1;j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1;j <= m; j++) {
            if(a[i][j] != '#' && !visited[i][j]) {
                touchBound = false;
                cntSheep = 0;
                cntWolves = 0;
                dfs(i, j);
                if(touchBound) ansSheep += cntSheep, ansWolves += cntWolves;
                else {
                    if(cntSheep > cntWolves) ansSheep += cntSheep;
                    else ansWolves += cntWolves;
                }
            }
        }
    }
    cout << ansSheep << " " << ansWolves << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}