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
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 3e5 + 5;
int n;
int a[ms];
vi ps;

void solve() {
    cin >> n;
    vector<int> a(n);
    for (auto& x : a) cin >> x;
    vector<int> ans(n, n);
    for (int z = 0; z < 2; ++z) {
        vector<long long> ps(n + 1);  // preSum
        for (int i = 0; i < n; ++i) ps[i + 1] = ps[i] + a[i];
        vector<int> prv(n, -1);  // previous of
        for (int i = 1; i < n; i++) {
            prv[i] = (a[i] == a[i - 1] ? prv[i - 1] : i - 1);
        }
        for (int i = 1; i < n; ++i) {
            int j = (z ? n - i - 1 : i);
            int l = 1, r = i;
            while (l <= r) {
                int m = (l + r) / 2;
                if (ps[i] - ps[i - m] > a[i] && prv[i - 1] >= i - m) {
                    ans[j] = min(ans[j], m);
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (a[i - 1] > a[i]) ans[j] = 1;
        }
        reverse(a.begin(), a.end());
    }
    for (int i = 0; i < n; ++i) cout << (ans[i] == n ? -1 : ans[i]) << ' ';
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}