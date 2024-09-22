#include <bits/stdc++.h>
#define int long long

using namespace std;

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
int n, m;
int s[ms];

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    vector<vector<int>> dist(n, vector<int>(n, oo));
    vector<vector<int>> vis(n, vector<int>(n, 0));
    priority_queue<vi, vvi, greater<vi>> pq;

    dist[0][0] = 0;
    pq.push({0, 0, 0});

    while (!pq.empty()) {
        int city = pq.top()[1];
        int bike = pq.top()[2];
        pq.pop();

        if (city == n - 1) {
            cout << dist[city][bike] << endl;
            return;
        }

        if (vis[city][bike]) continue;
        vis[city][bike] = 1;

        for (auto it : adj[city]) {
            int nbr = it.first;
            int wt = it.second;

            int newBike = bike;
            if (s[nbr] < s[bike]) newBike = nbr;

            if (dist[nbr][newBike] < dist[city][bike] + wt * s[bike]) continue;

            dist[nbr][newBike] = dist[city][bike] + wt * s[bike];
            pq.push({dist[nbr][newBike], nbr, newBike});
        }
    }

    cout << -1 << endl;
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