#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Shortest Path
 * Solution: Using floyd algorithm
 *  use for edge positive and negative weight
 *  can detect a negative cycle
 *
 * TC: O(V ^ 3)
 * MC: O(V ^ 2)
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
const int ms = 1e5 + 5;

vector<vector<int>> dist;

// find shortest path for all pair
void floyd(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}
bool isNegCycleFloyd(int n) {
    floyd(n);
    for (int i = 0; i < n; i++) {
        if (dist[i][i] < 0) {
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    dist = vector<vector<int>>(n + 1, vector<int>(n + 1, oo));
    for (int i = 1; i <= n; i++) dist[i][i] = 0;
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        w = min(w, dist[u][v]);
        dist[u][v] = w;
        dist[v][u] = w;  // remove if directed edge
    }
    floyd(n);
    cout << dist[0][n - 1] << el;
    cout << isNegCycleFloyd(n) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}