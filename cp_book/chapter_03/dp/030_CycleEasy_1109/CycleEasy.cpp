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

const long long oo = 2e18, mod = 9901;
const int ms = 2e5 + 5;
int tc = 0;

void solve() {
    int n, k;
    cin >> n >> k;
    vvi fob(n, vi(n, false));
    Rep(i, n) fob[i][i] = true;  // self edge
    Rep(i, k) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        fob[u][v] = fob[v][u] = true;
    }
    int max_mask = (1LL << n) - 1;

    vvi f(max_mask + 1, vi(n, 0));  // f[mask][u]: number of ways to go from 0 to mask, end at: u;
    f[1][0] = 1;                    // base case;

    For(mask, 1, max_mask) {
        if (!(mask & 1)) continue;
        Rep(u, n) {
            if (!((mask >> u) & 1)) continue;
            Rep(v, n) {
                if ((mask >> v) & 1) continue;
                if (fob[u][v]) continue;
                int new_mask = mask ^ (1LL << v);
                f[new_mask][v] += f[mask][u];
            }
        }
    }

    int tot = 0;  // directed
    For(u, 1, n - 1) {
        if (fob[u][0]) continue;
        tot += f[max_mask][u];
    }
    int ans = tot / 2;
    ans %= mod;
    cout << "Case #" << ++tc << ": ";
    cout << ans << el;
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