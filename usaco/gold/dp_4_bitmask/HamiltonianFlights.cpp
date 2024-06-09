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
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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

int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m;

void solve() {
    cin >> n >> m;
    vvi adj(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[v].pb(u);
    }

    vvi f(1 << n, vi(n + 1, 0));
    // f[i][j]: number of way get subset i from j city (j is last city)

    f[1][0] = 1;
    int maxMask = (1 << n) - 1;
    for (int mask = 1; mask <= maxMask; mask += 2) {
        // only take the mask that has 1: so mask always is odd number (mask += 2)
        // also only consider subsets with the last city if it's the full subset
        if (getBit(mask, n - 1) and mask != maxMask) continue;

        for (int pos = 0; pos < n; pos++) {
            if (!getBit(mask, pos)) continue;
            for (auto from : adj[pos]) {
                if (getBit(mask, from)) {
                    int newMask = toggleBit(mask, pos);
                    f[mask][pos] += f[newMask][from];
                    f[mask][pos] %= mod;
                }
            }
        }
    }
    cout << f[maxMask][n - 1] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}