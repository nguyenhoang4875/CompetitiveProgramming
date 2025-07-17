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

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n);
    Rep(i, n) cin >> a[i];
    if (k >= 3) {
        cout << 0 << el;
        return;
    }
    sort(all(a));
    vi b;
    b.reserve(n * n);
    int ans = a[0];
    For(i, 0, n - 1) {
        For(j, i + 1, n - 1) {
            b.push_back(a[j] - a[i]);
            ans = min(ans, a[j] - a[i]);
        }
    }
    if (k == 1) {
        cout << ans << el;
        return;
    }
    sort(all(b));
    for (auto& e : a) {
        auto low = lower_bound(all(b), e);
        if (low != b.end()) {
            ans = min(ans, abs(*low - e));
        }
        if (low != b.begin()) {
            low--;
            ans = min(ans, abs(*low - e));
        }
    }
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