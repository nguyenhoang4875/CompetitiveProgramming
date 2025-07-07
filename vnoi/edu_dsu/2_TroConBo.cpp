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
typedef long long ll;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

struct Dsu {
    int n;
    vector<int> parent, size;
    vi diff, val;

    Dsu() {};
    Dsu(int _n) {
        n = _n;
        parent = vector<int>(n + 1);
        size = vector<int>(n + 1);
        diff = vi(n + 1, 0);
        val = vi(n + 1, 0);
        for (int v = 1; v <= n; v++) makeSet(v);
    }

    void makeSet(int v) {
        parent[v] = v;
        size[v] = 1;  // init size = 1;
    }

    int findSet(int v) {
        if (parent[v] == v) return v;
        int p = findSet(parent[v]);
        diff[v] += diff[parent[v]];
        return parent[v] = p;
    }

    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);  // set a is root of the bigger size of tree
        parent[b] = a;
        diff[b] = val[b] - val[a];
        size[a] += size[b];  // update the new size of new the merge tree
        return true;
    }

    void add(int v, int x) {
        int r = findSet(v);
        val[r] += x;
    }

    int get(int v) {
        int r = findSet(v);
        return val[r] + diff[v];
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    Dsu dsu(n);
    while (q--) {
        string type;
        cin >> type;
        if (type == "join") {
            int u, v;
            cin >> u >> v;
            dsu.unionSet(u, v);
        } else if (type == "add") {
            int u, x;
            cin >> u >> x;
            dsu.add(u, x);
        } else {
            int u;
            cin >> u;
            cout << dsu.get(u) << el;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}