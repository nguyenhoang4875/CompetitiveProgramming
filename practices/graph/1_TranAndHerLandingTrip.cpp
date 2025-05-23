#include <bits/stdc++.h>
#define int long long

/**
 * https://vjudge.net/contest/717959#problem/D
 */
using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
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

struct Edge {
    int to, interval, depart, travel;
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> adj(n + 1);
    For(i, 1, m) {
        int k, interval;
        cin >> k >> interval;
        vi stops(k);
        Rep(j, k) cin >> stops[j];
        vi times(k);
        Rep(j, k) cin >> times[j];

        int curTime = 0;
        Rep(j, k) {
            int u = stops[j];
            int v = stops[(j + 1) % k];
            int t = times[j];
            int depart = curTime + 5 * 3600 + 1800;  // start at 5:30
            adj[u].pb({v, interval, depart, t});
            curTime += t;
        }
    }

    auto getWait = [](int curTime, int depart, int interval) {
        if (curTime <= depart) { return depart - curTime; }
        int r = (curTime - depart) % interval;
        return (interval - r) % interval;
    };

    vi dist(n + 1, oo);
    const int startTime = 14 * 3600;  // start at 14:00
    priority_queue<pii, vii, greater<pii>> q;
    dist[1] = startTime;
    q.push({startTime, 1});

    while (!q.empty()) {
        auto [curTime, u] = q.top();
        q.pop();
        if (curTime > dist[u]) continue;

        for (auto &v : adj[u]) {
            int arrivalTime = curTime + v.travel + getWait(curTime, v.depart, v.interval);
            if (arrivalTime < dist[v.to]) {
                dist[v.to] = arrivalTime;
                q.push({arrivalTime, v.to});
            }
        }
    }
    int ans = dist[n] == oo ? -1 : dist[n] - startTime;
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}