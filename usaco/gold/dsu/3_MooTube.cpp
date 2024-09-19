#include <bits/stdc++.h>
#define int long long
/**
 * DSU OFFLINE queries:
 * 1. Sort Edged desc weight
 * 2. Sort query desc k
 * 3. Use DSU to union edge
 * 4. Calculate ans for query desc k
 * 5. Reorder the answer
 *
 * TC: O(alpha(N))
 */

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
struct Dsu {
    int n;
    vector<int> parent, size;

    Dsu() {};
    Dsu(int _n) {
        n = _n;
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1);
        for (int v = 1; v <= n; v++) makeSet(v);
    }

    void makeSet(int v) {
        parent[v] = v;
        size[v] = 1;  // init size = 1;
    }

    int findSet(int v) { return parent[v] = (v == parent[v] ? v : findSet(parent[v])); }

    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);  // set a is root of the bigger size of tree
        parent[b] = a;
        size[a] += size[b];  // update the new size of new the merge tree
        return true;
    }
};

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, q;
    cin >> n >> q;
    vvi edges;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});
    }

    sort(all(edges), greater<vi>());
    vvi query;
    for (int i = 0; i < q; i++) {
        int k, v;
        cin >> k >> v;
        query.push_back({k, v, i});
    }
    sort(all(query), greater<vi>());

    vii ans;
    int idx = 0;
    Dsu dsu(n);

    for (auto& e : query) {
        int k = e[0], v = e[1], qid = e[2];
        while (idx < n - 1 and edges[idx][0] >= k) {
            dsu.unionSet(edges[idx][1], edges[idx][2]);
            idx++;
        }
        ans.push_back({qid, dsu.size[dsu.findSet(v)] - 1});
    }
    sort(all(ans));

    for (auto& e : ans) {
        cout << e.S << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("mootube.in", "r", stdin);
    freopen("mootube.out", "w", stdout);

    solve();
    return 0;
}