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

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int tc = 0;
    while (true) {
        int n, k;
        cin >> n >> k;
        if (!n and !k) return;
        map<pii, vi> cost;
        For(u, 1, n) {
            For(v, 1, n) {
                if (u == v) continue;
                int d;
                cin >> d;
                while (d--) {
                    int x;
                    cin >> x;
                    cost[{u, v}].push_back(x);
                }
            }
        }

        // f[day][last_city]: min cost for first d days and current at the last city
        vvi f(k + 1, vi(n + 1, oo));
        f[0][1] = 0;
        for (int d = 1; d <= k; ++d) {
            for (int u = 1; u <= n; ++u) {
                for (int v = 1; v <= n; ++v) {
                    if (u == v) continue;
                    if (!cost.count({u, v})) continue;
                    if (f[d - 1][u] == oo) continue;
                    vi& c = cost[{u, v}];
                    int idx = (d - 1) % c.size();
                    if (c[idx] == 0) continue;
                    f[d][v] = min(f[d][v], f[d - 1][u] + c[idx]);
                }
            }
        }
        cout << "Scenario #" << ++tc << el;
        int ans = f[k][n];
        if (ans == oo) cout << "No flight possible." << el;
        else cout << "The best flight costs " << ans << "." << el;

        cout << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}