#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/contest/1272/problem/E
 * Solution: Multi source bfs
 *
 * TC: O(n)
 * MC: O(n)
 */

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
int n;
int a[ms];
vvi graph;
vi dist;
vi odd, even;

void bfs(vi& from, vi& to) {
    vi d(n + 1, oo);

    queue<int> q;
    for (auto v : from) {
        d[v] = 0;
        q.push(v);
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto x : graph[cur]) {
            if (d[x] == oo) {
                d[x] = d[cur] + 1;
                q.push(x);
            }
        }
    }
    for (auto i : to) {
        if (d[i] != oo) {
            dist[i] = d[i];
        }
    }
}

void solve() {
    cin >> n;
    graph = vvi(n + 1);
    For(i, 1, n) {
        cin >> a[i];
        if (a[i] & 1)
            odd.pb(i);
        else
            even.pb(i);

        int l = i - a[i];
        int r = i + a[i];
        if (l >= 1) graph[l].pb(i);  // from i can go to l, l might not go to i
        if (r <= n) graph[r].pb(i);  // from i can go to r, r might not go to i
    }
    dist = vi(n + 1, -1);
    bfs(odd, even);
    bfs(even, odd);
    For(i, 1, n) { cout << dist[i] << " "; }
    cout << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}