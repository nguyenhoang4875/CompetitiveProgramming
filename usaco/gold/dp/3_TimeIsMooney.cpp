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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int N, M, C;

void solve() {
    cin >> N >> M >> C;
    vi m(N);
    vvi adj(N);

    for (int i = 0; i < N; i++) {
        cin >> m[i];
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        adj[a].pb(b);
    }
    vvi dp(N, vi(2, -1));  // dp[i][j] max money is earned when end at i has level j
    dp[0][0] = 0;
    queue<int> q;
    q.push(0);
    int ans = 0;
    for (int level = 1; level < 1000; level++) {
        set<int> nextNodeLevel;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto v : adj[u]) {
                dp[v][level % 2] = max(dp[v][level % 2], dp[u][(level - 1) % 2] + m[v]);
                nextNodeLevel.insert(v);
            }
        }

        for (auto u : nextNodeLevel) {
            q.push(u);
        }
        ans = max(ans, dp[0][level % 2] - C * level * level);
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("time.in", "r", stdin);
    // freopen("time.out", "w", stdout);

    int tcs = 1;
    // cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}