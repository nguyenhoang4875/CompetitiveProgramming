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
vb visited;
bool cycle = false;
void dfs(int cur, int par) {
    visited[cur] = true;
    for (auto x : gr[cur]) {
        if (!visited[x]) {
            dfs(x, cur);
        } else if (x != par) {
            cout << x << " " << cur << el;
            cycle = true;
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    gr.resize(n + 1);
    visited.resize(n + 1, false);
    For(i, 1, m) {
        int u, v;
        cin >> u >> v;
        gr[u].pb(v);
        gr[v].pb(u);
    }
    For(i, 1, n) {
        if (!visited[i]) {
            dfs(i, 0);
        }
    }
    if (cycle) {
        cout << "Yes, have cycle" << el;
    } else
        cout << "NO, haven't cycle" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}