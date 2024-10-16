#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
vi color;
vvi adj;
int cnt = 0;

void dfs(int cur, int par, int cl) {
    color[cur] = cl;
    for (auto x : adj[cur]) {
        if (x != par and color[x] == -1) {
            dfs(x, cur, 1 - cl);
        }
    }
}

void solve() {
    cin >> n;
    adj = vvi(n + 1);
    color = vi(n + 1, -1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (color[i] == -1) {
            dfs(i, -1, 0);
        }
    }
    int cl0 = 0, cl1 = 0;
    for (int i = 1; i <= n; i++) {
        if (color[i] == 0)
            cl0++;
        else
            cl1++;
    }
    cout << cl0 * cl1 - (n - 1) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}