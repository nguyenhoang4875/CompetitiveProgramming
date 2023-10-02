#include<bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Problem: 
 * 
 * TC: O(m * n * diff * log(diff)): diff = maxHeight - minHeight 
 *    => max: (10^6 * log(110)) ~ O(7 * 10 ^ 6)
 * MC: O(m * n)
*/

//*** START CODING ***//

const int oo = 1e9;
int n, m;
int a[105][105];
int visited[105][105];
int dist[105][105];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {-1, 1, 0, 0};


int hMin = oo;
int hMax = 0;

struct node {
    int r, c;
};

bool inBound(int r, int c) {
    if(r < 1 || r > n || c < 1 || c > m) return false;
    return true;
}

void clearData() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            visited[i][j] = false;
            // dist[i][j] = oo;
        }
    }
}

bool bfs(int diff) {
    // brute force for each value
    for(int l = hMin; l <= hMax - diff;l++ ) {
        int r = l + diff;
        if(a[1][1] < l || a[1][1] > r) continue;
        clearData();
        visited[1][1] = true;
        queue<node> q;
        q.push({1, 1});
        while(!q.empty()) {
            node cn = q.front(); q.pop();
            if(cn.r == n && cn.c == n) {
                return true;
            }
            int nr, nc;
            for(int i = 0; i < 4; i++) {
                nr = cn.r + dr[i];
                nc = cn.c + dc[i];

                if(!inBound(nr, nc) || visited[nr][nc]) continue;
                if(a[nr][nc] < l || a[nr][nc] > r) continue;
                visited[nr][nc] = true;
                q.push({nr, nc});
            }
        }
    }
    return false;
}

void solve() {
    cin >> n;
    m = n;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            hMin = min(hMin, a[i][j]);
            hMax = max(hMax, a[i][j]);
        }
    }
    int ans = -1;
    int l = 0, r = hMax - hMin;

    // binary to find the min of diff => O(log(n))
    while(l <= r) {
        int mid = (l + r) / 2;
        if(bfs(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
   
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}