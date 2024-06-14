#include <bits/stdc++.h>
#define int long long

using namespace std;
// #DpOnTree

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
vvi adj;
int ans = 0, way = 0;

void solve() {
    cin >> n;
    adj = vvi(n + 1);

    for (int i = 1; i <= n; i++) {
        char c;
        cin >> c;
        s[i] = c;
    }
    for (int u = 1; u <= n; u++) {
        int p;
        cin >> p;
        if (p == 0) {
            root = u;
            continue;
        }
        // adj[u].pb(p); // no need to add this line when have parent
        adj[p].pb(u);
    }

    vi f(n + 1, 1);  // the maximum deep satisfy at subtree i
    vi g(n + 1, 1);  // the #way maximum deep satisfy at subtree i

    function<void(int, int)> dfs = [&](int cur, int par) {
        for (int x : adj[cur]) {
            if (x == par) continue;
            dfs(x, cur);
            if (s[x] == s[cur]) continue;
            if (f[cur] < f[x] + 1) {
                f[cur] = f[x] + 1;
                g[cur] = g[x];
            } else if (f[cur] == f[x] + 1) {
                g[cur] += g[x];
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
            // mx1 > 0;
            if (mx2 == 0) {
                // has one child with deep mx1
                for (auto x : adj[cur]) {
                    if (x == par or s[x] == s[cur]) continue;
                    cnt = g[x];
                }
            } else {
                // mx1 > 0 and mx2 > 0
                if (mx1 == mx2) {
                    int sum = 0;
                    vi can;
                    for (auto x : adj[cur]) {
                        if (x == par or s[x] == s[cur]) continue;
                        if (f[x] == mx1) {
                            can.pb(g[x]);
                            sum += g[x];
                        }
                    }
                    sum *= sum;
                    for (auto e : can) sum -= e * e;
                    sum /= 2;
                    cnt = sum;
                } else {
                    // mx1 != mx2
                    int c1 = 0;
                    int sum = 0;
                    for (auto x : adj[cur]) {
                        if (x == par or s[x] == s[cur]) continue;

                        if (f[x] == mx1) {
                            c1 = g[x];
                        }
                        if (f[x] == mx2) {
                            sum += g[x];
                        }
                    }
                    sum *= c1;
                    cnt = sum;
                }
            }
        }
        int best = mx1 + mx2 + 1;

        if (ans < best) {
            ans = best;
            way = cnt;
        } else if (ans == best) {
            way += cnt;
        }
    };
    ans = 0, way = 0;
    dfs(root, -1);
    cout << ans << " " << way << el;
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
