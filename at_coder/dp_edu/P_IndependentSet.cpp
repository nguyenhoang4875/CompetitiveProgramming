#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Independent Set
 * Solution: DP on Tree
 *
 * TC: O(n)
 * MC: O(n)
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
int n;
vector<int> graph[ms];
int memo[ms][2];

/*
color: black(0), white(1)
dp(cur, 0): total number of way in which the subtree of current painted black(0)
dp(cur, 1): total number of way in which the subtree of current painted black(1)
*/

int dp(int cur, int color, int par) {
    if (memo[cur][color] != -1) return memo[cur][color];
    int ans = 1;
    for (auto child : graph[cur]) {
        if (child != par) {
            if (color) {
                ans *= (dp(child, 0, cur) + dp(child, 1, cur));
            } else {
                ans *= dp(child, 1, cur);
            }
            ans %= mod;
        }
    }
    return memo[cur][color] = ans;
}

void solve() {
    cin >> n;
    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    memset(memo, -1, sizeof(memo));
    int ans = (dp(1, 0, 0) + dp(1, 1, 0)) % mod;
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}