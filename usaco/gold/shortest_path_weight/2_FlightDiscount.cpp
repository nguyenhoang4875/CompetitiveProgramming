#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

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
int n, m;

struct node {
    int d, id;
    bool used;
};

void solve() {
    cin >> n >> m;
    vector<vii> adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        adj[u].pb({v, w});
    }

    vvi dist(n, vi(2, oo));  // dist from 0 to i for used or not used discount 
    dist[0][0] = 0;

    auto cmp = [&](node& n1, node& n2) { return n1.d > n2.d; };

    priority_queue<node, vector<node>, decltype(cmp)> q(cmp);
    q.push({0, 0, false});

    while (!q.empty()) {
        node cur = q.top();
        q.pop();
        if (dist[cur.id][cur.used] < cur.d) continue;

        for (auto [v, w] : adj[cur.id]) {
            if (!cur.used) {
                int newDist = cur.d + w / 2;
                if (newDist < dist[v][1]) {
                    dist[v][1] = newDist;
                    q.push({newDist, v, true});
                }
            }
            int newDist = cur.d + w;
            if (newDist < dist[v][cur.used]) {
                dist[v][cur.used] = newDist;
                q.push({newDist, v, cur.used});
            }
        }
    }
    cout << dist[n - 1][1] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}