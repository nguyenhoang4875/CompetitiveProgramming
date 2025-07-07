#include <bits/stdc++.h>
#define int long long

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

struct Dsu {
    int n;
    vector<int> parent, size, mn, mx;

    Dsu() {};
    Dsu(int _n) {
        n = _n;
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1);
        mn = vi(n + 1);
        mx = vi(n + 1);
        for (int v = 1; v <= n; v++) makeSet(v);
    }

    void makeSet(int v) {
        parent[v] = v;
        size[v] = 1;  // init size = 1;
        mn[v] = v;
        mx[v] = v;
    }

    int findSet(int v) { return parent[v] = (v == parent[v] ? v : findSet(parent[v])); }

    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);  // set a is root of the bigger size of tree
        parent[b] = a;
        mn[a] = min(mn[a], mn[b]);
        mx[a] = max(mx[a], mx[b]);
        size[a] += size[b];  // update the new size of new the merge tree
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Dsu dsu(n);
    For(i, 1, m) {
        string type;
        cin >> type;
        int u, v;
        if (type == "union") {
            cin >> u >> v;
            dsu.unionSet(u, v);
        } else {
            cin >> u;
            u = dsu.findSet(u);
            cout << dsu.mn[u] << " " << dsu.mx[u] << " " << dsu.size[u] << el;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}