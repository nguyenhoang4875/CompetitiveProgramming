#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[55][55], b[55][55];
set<int> nums;
set<int> setVisit;
int sr, sc, dr, dc;
int totalNum;
int v[15], g[15];
bool visited[55][55];
int ans, valStart, valDes;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool inBound(int r, int c) {
    return 1 <= r && r <= n && 1 <= c && c <= n;
}

bool bfs() {
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    while(!q.empty()) {
        pair<int, int> cp = q.front(); q.pop();
        if(cp.first == dr && cp.second == dc)  return true;
        for(int i = 0; i < 4; i++) {
            int nr = cp.first + dx[i];
            int nc = cp.second + dy[i];
            if(!inBound(nr, nc) || visited[nr][nc] || !b[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
    return false;
}

void preMatrix(set<int> setVisit) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(setVisit.count(a[i][j])) b[i][j] = 1;
            else b[i][j] = 0;
            visited[i][j] = false;
        }
    }
}
void cal(int n) {
    setVisit.clear();
    setVisit.insert(valStart);
    setVisit.insert(valDes);

    for (int i = 1; i <= n ;i++) {
        if(g[i]) setVisit.insert(v[i]);
    }
    preMatrix(setVisit);
    if(bfs()) ans = min(ans, (int) setVisit.size());
    
}
void gen(int start, int n) {
    if(start > n) {
        cal(n);
        return;
    } 
    for(int val = 0; val <= 1; val++) {
        g[start] = val;
        gen(start + 1, n);
    }
}

void solve() {
    nums.clear();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            nums.insert(a[i][j]);
        }
    }

    cin >> sr >> sc;
    cin >> dr >> dc;
    sr += 1; //using array index base 1
    sc += 1;
    dr += 1;
    dc += 1;

    valStart = a[sr][sc];
    valDes = a[dr][dc];
    
    nums.erase(a[sr][sc]);
    if(valStart != valDes)  nums.erase(valDes);
    
    totalNum = nums.size();
    int idx = 1;
    for(int e: nums) {
        v[idx++] = e;
    }
    
    ans = 10;
    gen(1, totalNum);
    cout << ans << '\n';
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