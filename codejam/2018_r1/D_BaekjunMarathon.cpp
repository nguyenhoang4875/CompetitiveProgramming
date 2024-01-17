#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/15704
 * Solution: Binary Search on Answer + Dijkstra for shortest path
 *
 * TC: O(log n * m * log m)
 * MC: O(m)
 */

//*** define ***//
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m, k;

struct Graph {
    int n;
    vector<vector<pair<int, int>>> gr;

    Graph(int _n) {
        n = _n;
        gr = vector<vector<pair<int, int>>>(n + 1);
    }

    void addEdge(int u, int v, int w) {
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});  // if undirected
    }

    vector<int> dijkstra(int s) {
        vector<int> dist(n + 1, oo);
        vector<bool> seen(n + 1, false);
        dist[s] = 0;
        seen[s] = true;
        priority_queue<pii, vii, greater<pii>> q;
        q.push({0, s});  // first: dist, second: vertex

        while (!q.empty()) {
            pii p = q.top();
            q.pop();

            int u = p.S;  // get vertex
            seen[u] = true;
            if (dist[u] < p.F) continue;  // stop early
            for (auto e : gr[u]) {
                if (seen[e.F]) continue;
                if (dist[e.F] > dist[u] + e.S) {
                    dist[e.F] = dist[u] + e.S;
                    q.push({dist[e.F], e.F});
                }
            }
        }
        return dist;
    }
};

struct node {
    int a, b, c, t;
};

vector<node> v(ms);

bool check(int val) {
    Graph g(n + 1);
    For(i, 1, m) {
        int cost = 0;
        if (val > v[i].t) cost = v[i].c * (val - v[i].t) * (val - v[i].t);
        g.addEdge(v[i].a, v[i].b, cost);
    }
    return g.dijkstra(1)[n] <= k;
}

void solve() {
    cin >> n >> m >> k;
    For(i, 1, m) { cin >> v[i].a >> v[i].b >> v[i].c >> v[i].t; }

    int l = 0;
    int r = 1e6 + 1;

    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            ans = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}