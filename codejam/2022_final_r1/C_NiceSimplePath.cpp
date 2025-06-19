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
int n, root;
char s[ms];
int ans = 0, ways = 0;
vvi adj;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> s[i];
    adj = vvi(n + 1);
    for (int u = 1; u <= n; u++) {
        int v;
        cin >> v;
        if (v == 0) {
            root = u;
            continue;
        }
        adj[u].pb(v);  // no need by has parent
        adj[v].pb(u);
    }

    vi f(n + 1, 1);   // max diff ok for subtree has root u;
    vi f1(n + 1, 1);  // number of way to has max deep ok

    function<void(int, int)> dfs = [&](int cur, int par) {
        for (auto x : adj[cur]) {
            if (x == par) continue;
            dfs(x, cur);
            if (s[x] == s[cur]) continue;
            // cout << cur << " " << x << " " << f[x] << el;
            if (f[cur] < f[x] + 1) {
                f[cur] = f[x] + 1;
                f1[cur] = f1[x];
            } else if (f[cur] == f[x] + 1) {
                f1[cur] += f1[x];
            }
        }

        int mx1 = 0, mx2 = 0;
        for (int x : adj[cur]) {
            if (x == par or s[x] == s[cur]) continue;
            if (mx1 < f[x]) {
                mx2 = mx1;
                mx1 = f[x];
            } else if (mx2 < f[x]) {
                mx2 = f[x];
            }
        }

        int cnt = 0;
        if (mx1 == 0) {
            cnt = 1;
        } else {
            if (mx2 == 0) {
                for (auto x : adj[cur]) {
                    if (x == par or s[x] == s[cur]) continue;
                    cnt = f1[x];
                }
            } else {
                // mx1 > 0 and mx2 > 0
                if (mx1 == mx2) {
                    vi can;
                    for (auto x : adj[cur]) {
                        if (x == par or s[x] == s[cur]) continue;
                        if (f[x] == mx1) {
                            can.pb(f1[x]);
                        }
                    }

                    int n = can.size();
                    int sum = 0;
                    for (auto e : can) sum += e;
                    sum *= sum;
                    for (auto e : can) sum -= e * e;
                    sum /= 2;
                    cnt = sum;
                } else {
                    // mx1 != mx2: 1 mx1 and many mx2
                    int c1 = 0;
                    int sum = 0;
                    for (auto x : adj[cur]) {
                        if (x == par or s[x] == s[cur]) continue;
                        if (f[x] == mx1) {
                            c1 = f1[x];
                        }
                        if (f[x] == mx2) {
                            sum += f1[x];
                        }
                    }
                    sum *= c1;
                    cnt = sum;
                }
            }
        }
        int best = mx1 + mx2 + 1;
        if (ans < best) {
            ways = cnt;
            ans = best;
        } else if (ans == best) {
            ways += cnt;
        }
    };
    ans = 1, ways = 0;
    dfs(root, -1);
    cout << ans << " " << ways << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}