#include <bits/stdc++.h>
#define int long long

using namespace std;

int tcs, n;
int a[55][55];
int b[55][55];
set<int> nums;
set<int> setVisit;
int sr, sc, dr, dc;
int totalNum;
int v[15];
int g[15];
bool visited[55][55];
bool used[15];
int ans, valStart, valDes;
bool found;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void clearData() {
    nums.clear();
    setVisit.clear();
    for(int i = 1; i < 11; i++) {
        v[i] = 0;
        g[i] = 0;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            visited[i][j] = false;
        }
    }
}

bool inBound(int r, int c) {
    return 1 <= r && r <= n && 1 <= c && c <= n;
}

void bfs() {
    queue<pair<int, int>> q;
    q.push({sr, sc});
    visited[sr][sc] = true;
    while(!q.empty()) {
        pair<int, int> cp = q.front(); q.pop();
        if(cp.first == dr && cp.second == dc) {
            found = true;
            return;
        }
        for(int i = 0; i < 4; i++) {
            int nr = cp.first + dx[i];
            int nc = cp.second + dy[i];
            if(!inBound(nr, nc) || visited[nr][nc] || !b[nr][nc]) continue;
            visited[nr][nc] = true;
            q.push({nr, nc});
        }
    }
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
void cal(int k) {
    // cout << "k = " << k << endl;
    // for(int i = 1; i <= k; i++) {
    //     cout << g[i] << ' ';
    // }
    // cout << endl;
    setVisit.clear();
    setVisit.insert(valStart);
    setVisit.insert(valDes);
    for (int i = 1; i <= k ;i++) {
        setVisit.insert(g[i]);
    }
    preMatrix(setVisit);
    bfs();
}
void gen(int start, int k, int n) {
    if(found) return;
    if(start > k) {
        cal(k);
        return;
    } else {
        for(int i = 1; i <= n; i++) {
            if(used[v[i]]) continue;
            if(v[i] < g[start - 1]) continue;
            used[v[i]] = true;
            g[start] = v[i];
            gen(start + 1, k , n);
            used[v[i]] = false;
        }
    }
}

void printMatrix() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}
void solve() {
    clearData();
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            nums.insert(a[i][j]);
        }
    }

    // printMatrix();
    
    cin >> sr >> sc;
    cin >> dr >> dc;
    sr += 1;
    sc += 1;
    dr += 1;
    dc += 1;


    valStart = a[sr][sc];
    valDes = a[dr][dc];
    
    // cout << valStart << valDes << endl;
    nums.erase(a[sr][sc]);
    setVisit.insert(valStart);
    setVisit.insert(valDes);
    
    ans = 1;
    if(valStart != valDes)  {
        ans += 1;
        nums.erase(valDes);
    }
    totalNum = nums.size();
    int idx = 1;
    for(int e: nums) {
        v[idx++] = e;
    }
    // for (int i = 1; i <= totalNum; i++) {
    //     cout << v[i] << ' ';
    // }
    // cout << '\n';

    // cout << "totalNum = " << totalNum << endl;
    preMatrix(setVisit);
    bfs();
    if(found) {
        cout << ans << '\n';
        return;
    }
    for(int k = 1; k <= totalNum; k++) {
        gen(1, k, totalNum);
        if(found) {
            ans += k;
            cout << ans << '\n';
            return;
        }
    }
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