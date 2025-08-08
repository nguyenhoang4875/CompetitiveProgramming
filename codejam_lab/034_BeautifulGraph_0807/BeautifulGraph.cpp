#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

const long long oo = 2e18, mod = 998244353;
const int ms = 3e5 + 5;

vi p2(ms);

void init() {
    p2[0] = 1;
    For(i, 1, ms - 1) { p2[i] = 2 * p2[i - 1] % mod; }
}

int n, m;
int num_node;
vector<vector<int>> adj;
vector<int> color;  // -1: unset color, 0: black, 1: white
bool hasCycle;

vi cnt(2, 0);

bool dfs(int cur, int par, int cl) {
    color[cur] = cl;
    cnt[cl]++;
    for (auto& x : adj[cur]) {
        if (color[x] == -1) {
            if (!dfs(x, cur, 1 - cl)) return false;
        } else if (x != par and color[x] == cl) {
            return false;
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    adj.clear();
    adj.resize(n + 1);
    color = vector<int>(n + 1, -1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = 1;

    for (int i = 1; i <= n; i++) {
        bool ok = true;
        if (color[i] == -1) {
            cnt[0] = cnt[1] = 0;
            ok = dfs(i, -1, 0);
            if (!ok) {
                cout << 0 << el;
                return;
            }
            int cur = (p2[cnt[0]] + p2[cnt[1]]) % mod;
            ans = ans * cur % mod;
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    int tcs;
    cin >> tcs;
    while (tcs--) solve();

    return 0;
}