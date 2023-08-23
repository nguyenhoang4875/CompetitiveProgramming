#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, m;
int mod = 1e9 + 7;
int gt[200005];
int gt_rev[200005];
int cnt = 0;

int lt(int a, int n) {
    cnt++;
    if (n == 0) return 1;
    int tmp = lt(a, n / 2);
    tmp = tmp * tmp % mod;
    if (n % 2 != 0) tmp = tmp * a % mod;
    return tmp;
}

int rev(int t) { return lt(t, mod - 2); }

// (a+b)!/(a!b!)
int toHopLap(int a, int b) {
    int res = gt[a + b];
    res = res * (gt_rev[a]) % mod;
    res = res * (gt_rev[b]) % mod;
    return res;
}

void solve() {
    cin >> n >> m;
    int ans = 0;
    // Block1: (n)A + (n-1)B => max n+n-1 characters
    // Max cntA of 1-th block is m-1
    for (int cntA = n; cntA <= (m - 1); cntA++) {
        int cntB = (n + n - 1) - cntA;
        if (cntB < 0) break;

        // For block2
        int cntA2 = (m - 1) - cntA;
        int cntB2 = m - cntB;

        ans = (ans + toHopLap(cntA, cntB) * toHopLap(cntA2, cntB2) % mod) % mod;
    }

    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    gt[0] = 1;
    gt_rev[0] = rev(gt[0]);
    for (int i = 1; i <= 200000; i++) {
        gt[i] = gt[i - 1] * i % mod;
        gt_rev[i] = rev(gt[i]);
    }

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
}
