#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
    return os << "}";
}
#else
#define del
#define debug(x)
#endif

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

template <typename T = int>
struct Dsu2d {
    // Must use based-index 0 for modulo
    int n, row, col;
    vector<int> parent, size;

    Dsu2d() {};
    Dsu2d(int r, int c) {
        row = r, col = c;
        n = row * col;
        parent = vector<int>(n);
        size = vector<int>(n);
        for (int v = 0; v < n; v++) makeSet(v);
    }

    void makeSet(int r, int c) { makeSet(flat(r, c)); }

    pair<int, int> findSet(int r, int c) {
        int root = findSet(flat(r, c));
        return unFlat(root);
    }

    int flat(int r, int c) { return r * col + c; }

    pair<int, int> unFlat(int idx) {
        int r = idx / col;
        int c = idx % col;
        return {r, c};
    }

    bool unionSet(int r1, int c1, int r2, int c2) {
        int u = flat(r1, c1);
        int v = flat(r2, c2);
        return unionSet(u, v);
    }

    int getSize(pair<int, int> p) { return getSize(flat(p.first, p.second)); }

   private:
    void makeSet(int v) {
        parent[v] = v;
        size[v] = 1;
    }

    int findSet(int v) { return parent[v] = (v == parent[v] ? v : findSet(parent[v])); }

    bool unionSet(int a, int b) {
        a = findSet(a);
        b = findSet(b);
        if (a == b) return false;

        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    int getSize(int v) { return size[findSet(v)]; }
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    debug(a);
    Dsu2d dsu(n, m);
    // debug(dsu.size);
    auto inBound = [&](int r, int c) {
        if (r < 0 or r >= n or c < 0 or c >= m) return false;
        return true;
    };
    // auto getVal = [&](int r, int c) {
    //     assert(r * m + c <= n * m);
    //     return r * m + c;
    // };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '*') continue;
            for (int k = 0; k < 4; k++) {
                int nr = i + dx[k];
                int nc = j + dy[k];
                if (!inBound(nr, nc) or a[nr][nc] == '*') continue;
                assert(nr < n);
                assert(nc < m);
                dsu.unionSet(i, j, nr, nc);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') continue;
            set<pii> sr;
            int sum = 1;
            for (int k = 0; k < 4; k++) {
                int nr = i + dx[k];
                int nc = j + dy[k];
                if (!inBound(nr, nc) or a[nr][nc] != '.') continue;
                assert(nr < n);
                assert(nc < m);
                pii root = dsu.findSet(nr, nc);
                if (!sr.count(root)) {
                    sum += dsu.getSize(root);
                    sr.insert(root);
                }
            }
            sum %= 10;
            a[i][j] = sum + '0';
        }
    }
    for (auto e : a) { cout << e << el; }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // char c = 0 + 65;
    // cout << c << el;

    solve();
    return 0;
}