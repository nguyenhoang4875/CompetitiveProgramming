#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vvi nxt(n + 2, vi(k));        // nxt[i][k]: pos of the next s[i]
    Rep(c, k) nxt[n][c] = n + 1;  // out of range
    Rof(i, n - 1, 0) {
        nxt[i] = nxt[i + 1];
        int c = s[i] - 'a';
        nxt[i][c] = i + 1;
    }
    vi f(n + 2);  // f[i]: minimum chars need to add make un subsequece for pos i
    f[n + 1] = 0;
    Rof(i, n, 0) {
        f[i] = n;
        Rep(c, k) { f[i] = min(f[i], f[nxt[i][c]]); }
        f[i]++;
    }

    int q;
    cin >> q;
    while (q--) {
        string t;
        cin >> t;
        int p = 0;
        int m = sz(t);
        for (int i = 0; i < m and p <= n; i++) {
            int c = t[i] - 'a';
            p = nxt[p][c];
        }
        cout << f[p] << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}