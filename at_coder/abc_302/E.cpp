#include <bits/stdc++.h>
#define int long long

using namespace std;

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
const int ms = 2e5 + 5;
int n, q;

void solve() {
    cin >> n >> q;
    vector<set<int>> g(n);
    int ans = n;
    while (q--) {
        int type;
        cin >> type;
        int u, v;
        if (type == 1) {
            cin >> u >> v;
            --u, --v;
            if (g[u].empty()) ans--;
            if (g[v].empty()) ans--;
            g[u].insert(v);
            g[v].insert(u);

        } else if (type == 2) {
            cin >> v;
            --v;
            for (auto e : g[v]) {
                g[e].erase(v);
                if (g[e].empty()) ans++;
            }
            if (!g[v].empty()) ans++;
            g[v].clear();
        }
        cout << ans << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}