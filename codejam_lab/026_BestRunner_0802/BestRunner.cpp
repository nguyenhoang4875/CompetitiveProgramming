#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
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

template <class X, class Y>
bool minimize(X &x, const Y &y) {
    if (x > y) {
        x = y;
        return true;
    } else return false;
}

template <class X, class Y>
bool maximize(X &x, const Y &y) {
    if (x < y) {
        x = y;
        return true;
    } else return false;
}

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];
    vi p(n + 1);
    For(i, 1, n) {
        int x;
        cin >> x;
        p[x] = 1;
    }

    vi ps(n + 2);
    For(i, 1, n) ps[i] = ps[i - 1] + a[i];

    int ans = 0;
    // run left to right
    for (int i = 1, x = 0; i <= n; i++) {
        if (p[i]) x = i;
        if (x == 0) continue;
        int sum = ps[i - 1] - ps[x - 1];
        if (sum > t) continue;
        maximize(ans, (i - x) + (t - sum) / a[i]);
    }

    // run right to left
    for (int i = n, x = 0; i >= 1; i--) {
        if (p[i]) x = i;
        if (x == 0) continue;
        int sum = ps[x] - ps[i];
        if (sum > t) continue;
        maximize(ans, (x - i) + (t - sum) / a[i]);
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}