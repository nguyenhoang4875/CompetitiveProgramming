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
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
vvi adj;

void solve() {
    cin >> n;
    adj = vvi(n + 1);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi d(n + 1, 0);  // max deep at i
    vi f(n + 1, 0);  // ans at i

    function<void(int, int)> dfs = [&](int u, int par) {
        for (int v : adj[u]) {
            if (v == par) continue;
            dfs(v, u);
            d[u] = max(d[u], d[v] + 1);
        }
    };

    function<void(int, int, int)> cal = [&](int u, int par, int ansPar) {
        vi preMax, sufMax;
        for (auto v : adj[u]) {
            if (v == par) continue;
            preMax.pb(d[v]);
            sufMax.pb(d[v]);
        }

        // cal preMax and sufMax
        for (int i = 1; i < preMax.size(); i++) {
            preMax[i] = max(preMax[i], preMax[i - 1]);
        }
        for (int i = sufMax.size() - 2; i >= 0; i--) {
            sufMax[i] = max(sufMax[i], sufMax[i + 1]);
        }
        int no = 0;
        for (auto v : adj[u]) {
            if (v == par) continue;
            int op1 = no == 0 ? -oo : preMax[no - 1];
            int op2 = no == sufMax.size() - 1 ? -oo : sufMax[no + 1];
            int ans = 1 + max({ansPar, op1, op2});
            cal(v, u, ans);
            no++;
        }

        f[u] = 1 + max(ansPar, preMax.empty() ? -oo : preMax.back());
    };
    dfs(1, 0);
    cal(1, 0, -1);
    for (int i = 1; i <= n; i++) {
        cout << f[i] << " ";
    }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}