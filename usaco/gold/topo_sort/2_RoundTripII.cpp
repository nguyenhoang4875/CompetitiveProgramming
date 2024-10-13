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
    vi inDeg(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
    }

    vb seen(n);
    vb onStack(n);
    vi cycle;
    function<bool(int)> dfs = [&](int cur) {
        seen[cur] = onStack[cur] = true;
        for (int next : adj[cur]) {
            if (onStack[next]) {
                cycle.push_back(cur);
                onStack[cur] = onStack[next] = false;
                return true;
            } else if (!seen[next]) {
                if (dfs(next)) {
                    if (onStack[cur]) {
                        cycle.push_back(cur);
                        onStack[cur] = false;
                        return true;
                    } else {
                        cycle.push_back(cur);
                        return false;
                    }
                }
                if (!cycle.empty()) return false;
            }
        }
        onStack[cur] = false;
        return false;
    };

    for (int i = 0; i < n; i++) {
        dfs(i);
        if (!cycle.empty()) break;
    }
    if (cycle.empty()) {
        cout << "IMPOSSIBLE" << el;
    } else {
        reverse(cycle.begin(), cycle.end());
        cout << cycle.size() + 1 << el;
        for (auto e : cycle) cout << e + 1 << " ";
        cout << cycle[0] + 1 << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}