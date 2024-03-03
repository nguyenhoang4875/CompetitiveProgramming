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
int n, m, s, k;
int a[ms];
vvi graph;
vi ans;

void bfs() {
    vvi dist = vvi(k + 1, vi(n + 1, -1));
    for (int type = 1; type <= k; type++) {
        vi q;
        For(i, 1, n) {
            if (a[i] == type) {
                dist[type][i] = 0;
                q.pb(i);
            }
        }

        for (int b = 0; b < sz(q); b++) {
            for (int u : graph[q[b]]) {
                if (dist[type][u] == -1) {
                    dist[type][u] = dist[type][q[b]] + 1;
                    q.pb(u);
                }
            }
        }
    }

    For(i, 1, n) {
        vi d(k + 1);
        For(j, 1, k) { d[j] = dist[j][i]; }
        sort(all(d));

        int sum = 0;
        For(j, 1, s) { sum += d[j]; }
        ans[i] = sum;
    }
}

void solve() {
    cin >> n >> m >> k >> s;
    graph = vvi(n + 1);
    For(i, 1, n) cin >> a[i];
    For(i, 1, m) {
        int u, v;
        cin >> u >> v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    ans = vi(n + 1);
    bfs();
    For(i, 1, n) { cout << ans[i] << " "; }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}