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

struct Dsu {
    int n;
    vector<int> parent, size;

    Dsu() {};

    Dsu(int _n) {
        n = _n;
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1);
        for (int i = 1; i <= n; i++) makeSet(i);
    }

    void makeSet(int v) {
        parent[v] = v;
        size[v] = 1;  // init size = 1;
    }

    int findSet(int v) { return parent[v] = (v == parent[v] ? v : findSet(parent[v])); }

    void unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);  // unordered_set a is root of the bigger size of tree
            parent[b] = a;
            size[a] += size[b];  // update the new size of new the merge tree
        }
    }
};

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int na, ma, nb, mb;

int calAns(vi& a, vi& b) {
    int ret = 0;
    int sumA = 0, sumB = 0;
    int n = a.size() - 1;
    int m = b.size() - 1;

    for (int i = 1; i <= n; i++) {
        sumA += a[i];
        if (sumA > mod) sumA -= mod;
    }

    for (int j = 1; j <= m; j++) {
        sumB += b[j];
        if (sumB > mod) sumB -= mod;
    }

    for (int i = 1; i <= n; i++) {
        ret += a[i] * i * sumB;
        if (ret > mod) ret %= mod;
    }

    for (int j = 1; j <= m; j++) {
        ret += b[j] * j * sumA;
        if (ret > mod) ret %= mod;
    }
    return ret;
}

vector<int> calPath(int n, int m, vb s, vvi& adj) {
    Dsu dsu(n);
    for (int u = 1; u <= n; u++) {
        for (auto v : adj[u]) {
            if (s[u] or s[v]) continue;
            dsu.unionSet(u, v);
        }
    }

    vi p(n + 1);
    // calculate good path for special node
    for (int u = 1; u <= n; u++) {
        if (s[u]) {
            int cnt = 0;
            for (auto v : adj[u]) {
                if (s[v]) continue;
                int rootV = dsu.findSet(v);
                cnt += dsu.size[rootV];
            }
            p[u] = cnt + 1;
        }
    }

    // calculate for normal node
    for (int u = 1; u <= n; u++) {
        if (s[u]) continue;

        int rootU = dsu.findSet(u);
        int cnt = 0;
        for (auto& v : adj[u]) {
            if (s[v] == 1) {
                p[rootU] += p[v];
                p[rootU] -= dsu.size[rootU];
            }
        }
    }

    for (int u = 1; u <= n; u++) {
        if (p[u] != 0) continue;
        p[u] = p[dsu.findSet(u)];
    }
    return p;
}

void solve() {
    cin >> na >> ma;
    vvi adjA(na + 1);
    vb sa(na + 1, false);

    for (int i = 1; i <= ma; i++) {
        int tmp;
        cin >> tmp;
        sa[tmp] = true;
    }

    for (int i = 1; i <= na - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjA[u].pb(v);
        adjA[v].pb(u);
    }

    cin >> nb >> mb;
    vvi adjB(nb + 1);
    vb sb(nb + 1);
    for (int i = 1; i <= mb; i++) {
        int tmp;
        cin >> tmp;
        sb[tmp] = true;
    }
    for (int i = 1; i <= nb - 1; i++) {
        int u, v;
        cin >> u >> v;
        adjB[u].pb(v);
        adjB[v].pb(u);
    }

    vi pa = calPath(na, ma, sa, adjA);

    vi pbb = calPath(nb, mb, sb, adjB);

    cout << calAns(pa, pbb) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}