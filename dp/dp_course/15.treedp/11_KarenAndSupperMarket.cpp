#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 1e9 + 10;
const int ms = 5e3 + 5;
// use pure array and int to avoid MLE 
// f[u][k][i]: min cost to buy from subtree u, exactly k items, i: 0, 1 (discount for u or not)
int f[ms][ms][2];

void solve() {
    int n, b;
    cin >> n >> b;
    vi c(n + 1), d(n + 1);

    vvi children(n + 1);
    For(i, 1, n) {
        cin >> c[i] >> d[i];
        if (i > 1) {
            int p;
            cin >> p;
            children[p].pb(i);
        }
    }

    memset(f, 0x3f, sizeof f);

    vi treeSize(n + 1);
    vvi pre(n + 1, vi(2, oo));
    vvi cur(n + 1, vi(2, oo));

    function<void(int)> dfs = [&](int u) {
        for (int& v : children[u]) dfs(v);
        For(i, 0, n) { Rep(j, 2) cur[i][j] = oo; }

        cur[0][0] = 0;
        treeSize[u] = 0;

        for (int& v : children[u]) {
            For(i, 0, treeSize[u]) Rep(j, 2) {
                pre[i][j] = cur[i][j];
                cur[i][j] = oo;
            }

            For(i1, 0, treeSize[u]) For(i2, 0, treeSize[v]) {
                Rep(j1, 2) Rep(j2, 2) {
                    cur[i1 + i2][j1 || j2] = min(cur[i1 + i2][j1 || j2], pre[i1][j1] + f[v][i2][j2]);
                }
            }
            treeSize[u] += treeSize[v];
        }

        For(i, 0, treeSize[u]) {
            f[u][i][0] = min(f[u][i][0], cur[i][0]);
            f[u][i + 1][0] = min(f[u][i + 1][0], cur[i][0] + c[u]);
            f[u][i + 1][1] = min(f[u][i + 1][1], min(cur[i][0], cur[i][1]) + c[u] - d[u]);
        }
        treeSize[u]++;
    };
    dfs(1);
    int res = 0;
    For(i, 1, n) {
        if (min(f[1][i][0], f[1][i][1]) <= b) res = i;
    }
    cout << res << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}