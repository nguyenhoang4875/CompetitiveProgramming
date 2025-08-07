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
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];

    vi ps(2 * k + 5);
    vi cnt(2 * k + 5);
    For(i, 1, n / 2) {
        int l = min(a[i], a[n + 1 - i]) + 1;
        int r = max(a[i], a[n + 1 - i]) + k;
        ps[l]++;
        ps[r + 1]--;
        cnt[(a[i] + a[n - i + 1])]++;
    }
    For(i, 1, 2 * k) ps[i] += ps[i - 1];
    int ans = n;
    for (int val = 2; val <= 2 * k; val++) {
        int c1 = ps[val];
        int res = c1 - cnt[val];
        res += (n / 2 - c1) * 2;
        ans = min(ans, res);
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