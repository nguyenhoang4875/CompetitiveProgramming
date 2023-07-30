#include <bits/stdc++.h>
#define int long long

using namespace std;
/**
 * Problem: https://codeforces.com/problemset/problem/1091/D
 * Solution:
 *  ans = n * n! - sum(i = 1 -> n - 1) n! / k!
 */

const int MOD = 998244353;
vector<int> fac;

void initFac(int n) {
    fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
}

int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y >>= 1;  // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Returns n^(-1) mod p
int modInverse(int n, int p) { return power(n, p - 2, p); }

// Returns nCr % p using Fermat's little theorem.
int nCrModPFermat(int n, int r, int p) {
    if (n < r) return 0;
    if (r == 0) return 1;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) %
            p) %
           p;
}

int n;
void solve() {
    cin >> n;
    initFac(n);
    int a = n * fac[n] % MOD;
    int b = 0;
    for (int i = 1; i < n; i++) {
        b += fac[n] * modInverse(fac[i], MOD);
        b %= MOD;
    }
    int ans = (a - b + MOD) % MOD;
    cout << ans << '\n';
}

int32_t main() {
    cin.sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}