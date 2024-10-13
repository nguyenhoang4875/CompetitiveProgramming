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
int n, m;

void solve() {
    cin >> n >> m;
    vvi adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vb seen(n, false);
    queue<int> q;
    q.push(0);
    seen[0] = true;

    vi parent(n);
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        if (cur == n - 1) break;

        for (auto x : adj[cur]) {
            if (!seen[x]) {
                seen[x] = true;
                parent[x] = cur;
                q.push(x);
            }
        }
    }
    if (!seen[n - 1]) {
        cout << "IMPOSSIBLE" << el;
        return;
    }
    vi path;
    path.push_back(n - 1);
    int cur = n - 1;
    while (parent[cur] != 0) {
        path.push_back(parent[cur]);
        cur = parent[cur];
    }
    path.push_back(0);
    reverse(all(path));
    cout << path.size() << el;
    for (auto e : path) cout << e + 1 << " ";
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}