#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Give matrix contains 0 and 1
 *  find minimum distance from 1 to 0 in graph
 * Solution: MultiSource Bfs
 *
 *
 * TC: O(n * m)
 * MC: O(n * m)
 */

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e3 + 5;
int n, m;
int a[ms][ms];
vector<vector<int>> dist;
queue<pair<int, int>> q;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool inBound(int r, int c) {
    if (r < 1 or r > n or c < 1 or c > m) return false;
    return true;
}

void bfs() {
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for (int i = 0; i <= 3; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!inBound(nx, ny) || dist[nx][ny] != oo) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
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
    dist = vector<vector<int>>(n + 1, vector<int>(m + 1, oo));
    q = queue<pair<int, int>>();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    bfs();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << dist[i][j] << " ";
        }
        cout << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}