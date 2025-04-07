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

struct SegmentTree {
    int n;
    vector<int> t;
    SegmentTree() {};
    SegmentTree(int a[], int _n) : t(4 * n), n(_n) { build(a, 1, 1, n); };

    void build(int a[], int v, int tl, int tr) {
        if (tl == tr) t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build(a, 2 * v, tl, tm);
            build(a, 2 * v + 1, tm + 1, tr);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    int combine(int v1, int v2) { return min(v1, v2); }

    int query(int v, int tl, int tr, int l, int r) {
        if (l <= tl && tr <= r) return t[v];
        if (l > tr || r < tl) return oo;  // invalid with min

        int tm = (tl + tr) / 2;
        return combine(query(2 * v, tl, tm, l, r), query(2 * v + 1, tm + 1, tr, l, r));
    }

    void update(int v, int tl, int tr, int pos, int newVal) {
        if (tl == tr) t[v] = newVal;
        else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) update(2 * v, tl, tm, pos, newVal);
            else update(2 * v + 1, tm + 1, tr, pos, newVal);
            t[v] = combine(t[2 * v], t[2 * v + 1]);
        }
    }

    int query(int l, int r) { return query(1, 1, n, l, r); }
    void update(int pos, int newVal) { return update(1, 1, n, pos, newVal); }
};

vector<int> dijkstra(int s, int n, vector<vector<pair<int, int>>>& adj) {
    vector<int> dist(n + 1, oo);
    dist[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, s});
    while (!q.empty()) {
        auto [d, u] = q.top();
        q.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
    return dist;
}

struct Node {
    int sq, cost, dist;
};

struct Query {
    int low, high, r, idx;
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<Node> vn(n + 1);
    For(i, 1, n) { cin >> vn[i].sq >> vn[i].cost; }

    vector<vii> adj(n + 1);
    For(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].pb({v, w});
        adj[v].pb({u, w});
    }
    vi dist = dijkstra(1, n, adj);
    For(i, 1, n) vn[i].dist = dist[i];

    sort(all(vn), [&](Node& n1, Node& n2) { return n1.dist < n2.dist; });

    // get unique square value;
    vector<int> uniSq;
    for (auto& node : vn) uniSq.push_back(node.sq);
    sort(all(uniSq));
    uniSq.resize(unique(all(uniSq)) - uniSq.begin());

    int nt = uniSq.size();
    vi a(nt + 1, oo);
    SegmentTree sgt(a.data(), nt);

    vector<Query> vq(q);
    For(i, 0, q - 1) {
        cin >> vq[i].low >> vq[i].high >> vq[i].r;
        vq[i].idx = i;
    }
    sort(all(vq), [&](Query& q1, Query& q2) { return q1.r < q2.r; });

    vi ans(q);
    int p = 0;
    for (auto& query : vq) {
        while (p < vn.size() and vn[p].dist <= query.r) {
            int rank = lower_bound(all(uniSq), vn[p].sq) - uniSq.begin() + 1;
            int preVal = sgt.query(rank, rank);
            if (vn[p].cost < preVal) sgt.update(rank, vn[p].cost);
            p++;
        }
        int left = lower_bound(all(uniSq), query.low) - uniSq.begin() + 1;
        int right = upper_bound(all(uniSq), query.high) - uniSq.begin();
        int minCost = oo;
        if (left <= right) { minCost = sgt.query(left, right); }
        ans[query.idx] = (minCost == oo) ? -1 : minCost;
    }
    for (auto e : ans) cout << e << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}