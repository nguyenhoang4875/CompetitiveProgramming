#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: Find ancestor for a node
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

vvi gr;
vi parent;
void dfs(int cur, int par) {
    parent[cur] = par;
    for (auto x : gr[cur]) {
        if (x != par) {
            dfs(x, cur);
        }
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    gr.resize(n + 1);
    parent.resize(n + 1);
    For(i, 1, n) {
        int u, v;
        cin >> u >> v;
        gr[u].pb(v);
        gr[v].pb(u);
    }
    dfs(10, 0);

    while (x) {
        cout << x << '\n';
        x = parent[x];
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}