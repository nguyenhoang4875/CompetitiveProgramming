#include <bits/stdc++.h>
#define int long long
/**
 * Problem: https://www.spoj.com/problems/MST/
 * Solution: Using Prim Algorithm for minimum spanning tree
 *
 * TC: O((V + E) * logV)
 * MC: O(V + E)
 */

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
const int ms = 1e5 + 5;

struct Graph {
    int n;
    vector<vector<pair<int, int>>> gr;

    Graph(int _n) {
        n = _n;
        gr = vector<vector<pair<int, int>>>(n + 1);
        // first: vertex, second: weight
    }

    void addEdge(int u, int v, int w) {
        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }

    int primMst() {
        priority_queue<pii, vector<pii>, greater<pii>> q;
        // priority pair: first: weight, second: vertex

        vector<bool> seen(n + 1, false);
        int ans = 0;
        q.push({0, 0});  // weight, vertex: change to {0, 1} if based-index 1
        while (!q.empty()) {
            pii best = q.top();
            q.pop();

            int weight = best.first;
            int to = best.second;

            if (seen[to]) continue;
            ans += weight;
            seen[to] = true;

            for (auto x : gr[to]) {
                if (!seen[x.first]) {
                    q.push({x.second, x.first});
                }
            }
        }

        return ans;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Graph g(n);
    For(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        g.addEdge(u, v, w);
    }
    cout << g.primMst() << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}