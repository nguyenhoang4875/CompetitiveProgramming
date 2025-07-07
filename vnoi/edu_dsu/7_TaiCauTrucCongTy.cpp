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
    Dsu dsu(n);
    vi nxt(n + 2);
    For(i, 1, n + 1) nxt[i] = i;

    while (q--) {
        int type, a, b;
        cin >> type >> a >> b;
        if (type == 1) {
            dsu.unionSet(a, b);
        } else if (type == 2) {
            int i = a;
            while (i < b) {
                dsu.unionSet(i, i + 1);
                nxt[i] = b;
                i = nxt[i + 1];
            }
        } else {
            if (dsu.findSet(a) == dsu.findSet(b)) {
                cout << "YES" << el;
            } else
                cout << "NO" << el;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}