#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/2059/problem/D
 * Solution: Buiild new graph +  dijkstra
 */

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
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
int n, s1, s2, m1, m2;

void solve() {
    cin >> n >> s1 >> s2;
    s1--, s2--;
    vvi g1(n), g2(n);
    set<pii> st;
    cin >> m1;
    For(i, 1, m1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
        g1[u].pb(v);
        g1[v].pb(u);
        st.insert({u, v});
    }
    vi good(n, false);
    cin >> m2;
    For(i, 1, m2) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (u > v) swap(u, v);
        g2[u].pb(v);
        g2[v].pb(u);
        if (st.count({u, v})) {
            good[u] = good[v] = true;
        }
    }

    priority_queue<vi, vvi, greater<vi>> q;
    q.push({0, s1, s2});
    vvi dist(n, vi(n, oo));
    while (!q.empty()) {
        vi cur = q.top();
        q.pop();
        int u = cur[1], v = cur[2];
        for (auto e1 : g1[u]) {
            for (auto e2 : g2[v]) {
                int newDist = cur[0] + abs(e1 - e2);
                if (newDist < dist[e1][e2]) {
                    dist[e1][e2] = newDist;
                    q.push({newDist, e1, e2});
                }
            }
        }
    }

    int ans = oo;
    For(u, 0, n - 1) {
        if (!good[u]) continue;
        ans = min(ans, dist[u][u]);
    }
    if (ans == oo) ans = -1;
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}
