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

void solve() {
    cin >> n;
    vvi adj(n);
    vi changeTo(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
        changeTo[i] = i;
    }
    changeTo[n - 1] = n - 1;

    function<int(int, int)> dfs = [&](int cur, int par) {
        int ans = 0;

        for (auto &x : adj[cur]) {
            if (x == par) continue;
            ans += dfs(x, cur);
        }

        if (changeTo[cur] != cur) return ans;

        if (par >= 0) {
            // swap with parent
            changeTo[cur] = changeTo[par];
            changeTo[par] = cur;
            ans += 2;
        } else {
            // if current node is root node and not swap
            changeTo[cur] = changeTo[adj[cur][0]];
            changeTo[adj[cur][0]] = cur;
            ans += 2;
        }
        return ans;
    };
    int ans = dfs(0, -1);
    cout << ans << el;
    for (auto e : changeTo) cout << e + 1 << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}