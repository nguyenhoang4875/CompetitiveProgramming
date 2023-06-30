#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m, k;
char a[55][55];
bool visited[55][55];
bool isLake;
int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};

struct lake {
    int r, c;
    int size;
};

vector<lake> lakes;

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

bool onBound(int r, int c) {
    if(r == 1 || r == n || c == 1 || c == m) return true;
    return false;
}

void clearData() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j] == '.') visited[i][j] = false;
        }
    }
}

int bfs(int r, int c) {
    int cnt = 0;
    queue<lake> q;
    q.push({r, c});
    visited[r][c] = true;
    while(!q.empty()) {
        lake cl = q.front();
        if(onBound(cl.r, cl.c)) isLake = false;
        q.pop();
        cnt++;
        for(int i = 0; i < 4; i++) {
            int nr = cl.r + dr[i];
            int nc = cl.c + dc[i];
            if(!inBound(nr, nc) || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    return cnt;
}

void dfs(int r, int c) {
    if(!inBound(r, c) || visited[r][c]) return;
    visited[r][c] = true;
    a[r][c] = '*';
    dfs(r - 1, c);
    dfs(r + 1, c);
    dfs(r, c - 1);
    dfs(r, c + 1);

}

void printResult(int num) {
    cout << num << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

void solve() {
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m ;j++) {
            cin >> a[i][j];
            if(a[i][j] == '*') visited[i][j] = true;
        }
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m ;j++) {
            if(!visited[i][j]) {
                isLake = true;
                int size = bfs(i, j);
                if(isLake) {
                    lakes.push_back({i, j, size});
                }
            }
        }
    }
    if(lakes.size() == k) {
        printResult(0);
        return;
    }
    sort(lakes.begin(), lakes.end(), [&](lake l1, lake l2) {
        return l1.size < l2.size;
    });
    int numRm = lakes.size() - k;
    clearData();
    int numLand = 0;
    for(int i = 0; i < numRm; i++) {
        lake lm = lakes[i];
        numLand += lm.size;
        dfs(lm.r, lm.c);
    }

    printResult(numLand);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}