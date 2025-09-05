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
    int m;
    cin >> m;

    vii a;
    while (true) {
        int l, r;
        cin >> l >> r;
        if (!l and !r) break;
        a.pb({l, r});
    }

    sort(all(a));

    vii p;
    int n = a.size();
    int i = 0;
    int cur = 0;
    while (cur < m) {
        int j = i;
        int best_i = -1;
        int max_r = -oo;
        while (j < n and cur >= a[j].F) {
            if (max_r < a[j].S) {
                best_i = j;
                max_r = a[j].S;
            }
            j++;
        }
        if (best_i == -1) break;
        cur = max_r;
        p.pb(a[best_i]);
        i = best_i + 1;
    }
    if (cur >= m) {
        cout << sz(p) << el;
        for (auto &[f, s] : p) cout << f << " " << s << el;
    } else cout << 0 << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    Rep(i, tcs) {
        solve();
        if (i != tcs - 1) cout << el;
    }
    return 0;
}