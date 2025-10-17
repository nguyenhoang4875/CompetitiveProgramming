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
using vs = vector<string>;
using vvs = vector<vs>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

string solve() {
    int n, m;
    cin >> n >> m;
    map<char, int> mp;
    map<int, char> rmp;
    char s, t;
    // string line;
    Rep(i, n) {
        char c;
        cin >> c;
        // line.pb(c);
        mp[c] = i;
        rmp[i] = c;
        if (i == 0) s = c;
        if (i == n - 1) t = c;
    }

    vvi adj(n);
    Rep(i, m) {
        char u, v;
        cin >> u >> v;
        int iu = mp[u], iv = mp[v];
        adj[iu].pb(iv);
        adj[iv].pb(iu);
    }

    const string s_max = string(n, 'Z');
    int max_mask = (1 << n) - 1;

    vvs f(max_mask + 1, vs(n + 1, s_max));
    f[1][0] = s;
    For(mask, 1, max_mask) {
        if (!getBit(mask, 0)) continue;
        Rep(u, n) {
            if (!getBit(mask, u)) continue;
            for (auto v : adj[u]) {
                if (getBit(mask, v)) continue;
                int new_mask = setBit(mask, v);
                f[new_mask][v] = min(f[new_mask][v], f[mask][u] + rmp[v]);
            }
        }
    }
    string ans = f[max_mask][n - 1];
    if (ans == s_max) ans = "impossible";
    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    For(tc, 1, tcs) cout << "Case " << tc << ": " << solve() << el;

    return 0;
}