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
 * Solution: Bit mask + Memo: DP Top Down
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
int memo[MS][1 << MS];

bool dp(int cur, int mask) {
    // base case
    if (mask == (1 << n) - 1) return true;
    if (memo[cur][mask] != -1) return memo[cur][mask];

    bool ans = false;
    for (auto x : g[cur]) {
        // x-th is not visited
        if (!((mask >> x) & 1)) {
            ans |= dp(x, mask | (1 << x));
        }
    }

    return memo[cur][mask] = ans;
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bool ans = false;
    memset(memo, -1, sizeof(memo));

    for (int i = 0; i < n; i++) {
        ans |= dp(i, 1 << i);
    }

    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}