#include <bits/stdc++.h>

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

const int oo = 1e9, mod = 1e9 + 7;
const int ms = 2e5 + 5;

int tspBu(vector<vector<int>>& dist) {
    int n = dist.size();

    vector<vector<int>> f(n + 1, vector<int>(1LL << n, oo));
    f[0][1] = 0;  // base case visited vertex 0 with mask 1
    // mask: bit 1 visited, 0: unvisited
    for (int mask = 1; mask < (1LL << n); ++mask) {
        if (!(mask & 1)) continue;  // not contain 0 vertex

        for (int u = 0; u < n; u++) {
            if (!((mask >> u) & 1)) continue;  // u not visited in this mask
            if (f[u][mask] == oo) continue;
            for (int v = 0; v < n; v++) {
                if ((mask >> v) & 1) continue;  // v already visited
                int new_mask = mask ^ (1LL << v);
                f[v][new_mask] = min(f[v][new_mask], dist[u][v] + f[u][mask]);
            }
        }
    }

    int ans = oo;
    for (int i = 1; i < n; i++) {
        ans = min(ans, f[i][(1LL << n) - 1] + dist[i][0]);
    }
    return ans;
}

void solve() {
    int x, y;
    cin >> x >> y;
    vii a;
    cin >> x >> y;
    a.pb({x, y});
    int b;
    cin >> b;
    Rep(i, b) {
        cin >> x >> y;
        a.pb({x, y});
    }

    int n = a.size();
    vvi dist(n, vi(n));

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            dist[i][j] = dist[j][i] = abs(a[i].F - a[j].F) + abs(a[i].S - a[j].S);
        }
    }

    vvi memo(n, vi((1LL << (n - 1)), -1));
    // bit 1: unvisited, 0: visited
    function<int(int, int)> tspTd = [&](int u, int mask) {
        if (mask == 0) return dist[u][0];

        int& ans = memo[u][mask];
        if (ans != -1) return ans;

        ans = oo;
        int m = mask;
        while (m) {
            int p2 = LSOne(m);
            int v = __builtin_ctz(p2) + 1;  // get pos for 1
            ans = min(ans, dist[u][v] + tspTd(v, mask ^ p2));
            m -= p2;
        }
        return ans;
    };

    cout << "The shortest path has length ";
    // cout << tspBu(dist) << el;
    cout << tspTd(0, (1LL << (n - 1)) - 1) << el;
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