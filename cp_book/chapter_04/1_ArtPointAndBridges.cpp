#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define LSOne(x) ((x) & -(x))
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define sz(x) static_cast<int>((x).size())
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(...) _debug(#__VA_ARGS__, __VA_ARGS__)
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    int i = 0, n = (int)distance(x.begin(), x.end());
    os << "{ ";
    for (const auto& y : x) os << y << (++i < n ? ", " : "");
    return os << " }";
}
template <typename... Args>
void _debug(const char* s, Args&&... args) {
    cout << "{ ";
    size_t i = 0, cnt = 0, n = sizeof...(args);
    auto next = [&]() {
        while (s[i] && (s[i] == ' ' || s[i] == ',')) ++i;
        size_t st = i;
        while (s[i] && s[i] != ',') ++i;
        return string(s + st, i - st);
    };
    auto dummy = {(cout << next() << ": " << args << (++cnt < n ? ", " : ""), 0)...};
    (void)dummy;
    cout << " }" << '\n';
}
#else
#define del
#define debug(...)
#endif

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

vector<vector<int>> adj;
vector<pair<int, int>> bridges;
vector<int> arts, tin, low;
vector<bool> seen;
int root, root_children, timer;

void artBridge(int u, int p) {
    seen[u] = true;
    tin[u] = low[u] = timer++;

    for (auto& v : adj[u]) {
        if (!seen[v]) {
            if (u == root) ++root_children;  // special case for root
            artBridge(v, u);

            if (low[v] >= tin[u]) arts[u] = 1;               // for articulation point
            if (low[v] > tin[u]) bridges.push_back({u, v});  // for bridge

            low[u] = min(low[u], low[v]);  // subtree alway update

        } else if (v != p) {               // backedge (non-trivial cycle)
            low[u] = min(low[u], tin[v]);  // then can update
        }
    }
};

void solve() {
    int n, m;  // n : vertices, m: edges
    cin >> n >> m;
    adj.assign(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;  // if based index 1: u, v
        adj[u].pb(v);
        adj[v].pb(u);
    }

    seen.assign(n, false), arts.assign(n, 0), tin.assign(n, 0), low.assign(n, 0);
    timer = 0;

    for (int u = 0; u < n; u++) {
        if (!seen[u]) {
            root = u, root_children = 0;
            artBridge(root, root);
            arts[root] = root_children > 1;  // special case
        }
    }

    vector<int> art_vertex;
    for (int u = 0; u < n; ++u) {
        if (arts[u] == 1) art_vertex.push_back(u);
    }

    // print art_vertex
    cout << "Articulation Points: \n";
    for (auto& x : art_vertex) cout << x + 1 << " ";
    cout << '\n';

    // print bridges
    cout << "Bridges: \n";
    for (auto& [u, v] : bridges) cout << u + 1 << " " << v + 1 << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}