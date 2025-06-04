#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 998244353;
const int ms = 2e5 + 5;
int n;

void solve() {
    cin >> n;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];
    vi f(n + 1, 0);
    f[0] = 1;
    f[1] = a[1] == 0;
    For(i, 2, n) {
        // i - 1: honest
        f[i] += (a[i] == a[i - 1]) ? f[i - 1] : 0;

        // i - 1: lair
        f[i] += (a[i - 2] + 1 == a[i]) ? f[i - 2] : 0;
        f[i] %= mod;
    }
    int ans = (f[n] + f[n - 1]) % mod;
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tcs;
    cin >> tcs;
    while (tcs--) solve();

    return 0;
}