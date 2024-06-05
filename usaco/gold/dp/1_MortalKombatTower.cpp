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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
int a[ms];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    vvi f(n + 5, vi(2, oo));
    f[1][0] = oo;
    f[2][0] = a[1];
    f[1][1] = a[1];
    f[2][1] = a[1] + a[2];
    for (int i = 3; i <= n; i++) {
        f[i][0] = min({f[i - 1][1], f[i - 2][1]});
        f[i][1] = min({f[i - 1][0] + a[i], f[i - 2][0] + a[i - 1] + a[i]});
    }
    cout << min(f[n][0], f[n][1]) << el;
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