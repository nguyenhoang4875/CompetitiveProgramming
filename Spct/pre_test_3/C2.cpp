#include <bits/stdc++.h>
#define int long long

using namespace std;

int n, m;
char a[55][55];
bool visited[55][55];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
int oo = 1e9;
int ans = oo;
int totalGold;
int cntGold;

struct node {
    int r, c, d;
};
vector<node> boom;
vector<node> dynamite;
vector<node> v; // can put dynamite;
vector<node> vb;
vector<node> g; // position of gold
queue<node> q;

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

void printMatrix() {
    cout << endl;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

bool isBoom(char c) {
    if('1' <= c && c <= '5') return true;
    return false;
}

bool isFinish() {
    return cntGold == totalGold;
}

void case1(int r, int c, int d) {
    for(int dr = -d; dr <= d; dr++) {
        for(int dc = -d; dc <= d; dc++) {
            int nr = r + dr;
            int nc = c + dc;
            if(!inBound(nr, nc) || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            if(a[nr][nc] == 'G') cntGold++;
            q.push({nr, nc});
            if(isBoom(a[nr][nc])) boom.push_back({nr, nc, a[nr][nc] - '0'});
        }
    }
}

void exploit(int r, int c, int d) {
    for(int dr = -d; dr <= d; dr++) {
        for(int dc = -d; dc <= d; dc++) {
            int nr = r + dr;
            int nc = c + dc;
            if(!inBound(nr, nc) || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            if(a[nr][nc] == 'G') cntGold++;
            vb.push_back({nr, nc});
            if(isBoom(a[nr][nc])) dynamite.push_back({nr, nc, a[nr][nc] - '0'});
        }
    }
}

void afterOne() {
    while (!q.empty()) {
        node cn = q.front();
        q.pop();
        for(int i = 0; i <= 3; i++) {
            int nr = cn.r + dr[i];
            int nc = cn.c + dc[i];
            if(!inBound(nr, nc) || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            vb.push_back({nr, nc});
            if(a[nr][nc] == 'G') cntGold++;
            if(isBoom(a[nr][nc])) {
                dynamite.push_back({nr, nc, a[nr][nc] - '0'});
            }
        }
    }
    
    for(node e: boom) {
        exploit(e.r, e.c, e.d);
    }
    for(node e: vb) q.push(e);
    vb.clear();
    boom.clear();
    for(node e: dynamite) boom.push_back(e);
    dynamite.clear();
}

void clearData() {
    boom.clear();
    dynamite.clear();
    queue<node> empty;
    swap(q, empty);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            visited[i][j] = false;
        }
    }
}

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if(a[i][j] == '.') {
                v.push_back({i, j});
            }
            if(a[i][j] == 'G') {
                totalGold++;
            }
        }
    }
    if(totalGold == 0 || v.empty()) {
        cout << 0 << endl;
        return;
    }
    for(node e: v) {
        clearData();
        int cnt = 1;
        cntGold = 0;
        visited[e.r][e.c] = true;
        case1(e.r, e.c, 1);
        // printMatrix();
        while(!isFinish()) {
            cnt++;
            // printMatrix();
            afterOne();
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}