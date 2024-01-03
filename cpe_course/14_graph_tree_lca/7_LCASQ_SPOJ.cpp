#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://www.spoj.com/problems/LCASQ/
 * Solution: Brute force
 *
 * TC: O(log n) for each time get lca
 * MC: O(n)
 */

#define pb push_back
#define all(b) b.begin(), b.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(v, a, b) for (int v = a; v <= (int)b; v++)
#define Ford(v, a, b) for (int v = a; v >= (int)b; v--)
#define Fore(it, b) for (auto it = b.begin(); it != b.end(); ++it)

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
const int ms = 1e4 + 5;
const int LOG = 20;
int n;
int up[ms][LOG + 5];
int depth[ms];
vi children[ms];

void dfs(int a) {
    for (auto b : children[a]) {
        depth[b] = depth[a] + 1;

        up[b][0] = a;
        For(j, 1, LOG - 1) { up[b][j] = up[up[b][j - 1]][j - 1]; }
        dfs(b);
    }
}

int lca(int a, int b) {  // O(log(N))
    if (depth[a] < depth[b]) {
        swap(a, b);
    }
    // 1) Get same depth.
    int k = depth[a] - depth[b];
    for (int j = LOG - 1; j >= 0; j--) {
        if (k & (1 << j)) {
            a = up[a][j];  // parent of a
        }
    }
    // 2) if b was ancestor of a then now a==b
    if (a == b) {
        return a;
    }
    // 3) move both a and b with powers of two
    for (int j = LOG - 1; j >= 0; j--) {
        if (up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

void solve() {
    cin >> n;
    For(v, 0, n - 1) {
        int cnt;
        cin >> cnt;
        For(j, 0, cnt - 1) {
            int c;
            cin >> c;
            children[v].pb(c);
        }
    }
    dfs(0);
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}