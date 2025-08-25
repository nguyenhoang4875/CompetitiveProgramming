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

const long long oo = (1LL << 31);
const int ms = 2e5 + 5;

void solve() {
    vi a;

    function<void(int, int)> f = [&](int v, int p) {
        if (p > oo) return;
        a.pb(p);
        f(v, p * v);
    };
    f(2, 2);
    f(3, 3);

    sort(all(a));
    a.erase(unique(all(a)), a.end());
    // debug(a);
    int n = sz(a);
    vi b;

    function<void(int, int)> dfs = [&](int x, int pos) {
        if (x > oo) return;
        b.push_back(x);
        for (int i = pos; i < n; i++) {
            if (x > oo / a[i]) break;
            dfs(x * a[i], i);
        }
    };

    dfs(1, 0);
    b.push_back(1);
    sort(all(b));
    b.erase(unique(all(b)), b.end());

    int m;
    while (true) {
        cin >> m;
        if (!m) return;
        cout << *lower_bound(all(b), m) << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}