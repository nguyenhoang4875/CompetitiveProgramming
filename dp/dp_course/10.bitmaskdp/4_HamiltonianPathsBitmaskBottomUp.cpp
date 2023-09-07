#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;
/**
 * Hamiltonian Path is a path in directed or undirected graph
 * that visit each vertex exactly once.
 * Input: n vertex, m edge and edges represent by a to b
 * Ouput: can construct hamiltonian path or not
 *
 * Solution: Bit mask DP: Bottom Up
 *
 *
 * TC: O(n * n * 2^n)
 * MC: O(2^n * n)
 *
 */

using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;

//*** START CODING ***//

const int MS = 15;
int n, m;
vector<int> g[MS];

void solve() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int dp[n][1 << n];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++) {
        dp[i][1 << i] = 1;
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        for (int cur = 0; cur < n; cur++) {
            if (dp[cur][mask]) {
                // find edges of cur
                for (auto x : g[cur]) {
                    // if x is not visited
                    if (!((mask >> x) & 1)) {
                        // set x is visited
                        dp[x][mask | (1 << x)] = 1;
                    }
                }
            }
        }
    }
    bool ans = false;
    for (int i = 0; i < n; i++) {
        ans |= dp[i][(1 << n) - 1];
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}