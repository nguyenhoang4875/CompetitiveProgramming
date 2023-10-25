#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

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
const int ms = 2e5 + 5;
int n, m;
int gt[ms];
int gtRev[ms];

int lt(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans *= a, ans %= mod;
        b /= 2;
        a *= a;
        a %= mod;
    }
    return ans;
}

void init() {
    gt[0] = 1;
    gtRev[0] = lt(gt[0], mod - 2);
    for (int i = 1; i <= ms; i++) {
        gt[i] = (gt[i - 1]) * i % mod;
        gtRev[i] = lt(gt[i], mod - 2);
    }
}

int toHop(int a, int b) {
    int ans = gt[a + b];
    ans = ans * gtRev[a] % mod;
    ans = ans * gtRev[b] % mod;
    return ans % mod;
}

void solve() {
    cin >> n >> m;
    int ans = 0;
    for (int cntA = n; cntA < m; cntA++) {
        int cntB = n + n - 1 - cntA;
        if (cntB < 0) break;
        int cntA2 = m - 1 - cntA;
        int cntB2 = m - cntB;
        ans =
            (ans + toHop(cntA, cntB) % mod * (toHop(cntA2, cntB2) % mod)) % mod;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();
    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}