#include <bits/stdc++.h>
#define int long long

/**
 * MUST READ: n < mod and n <= 10^7
 */

using namespace std;

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

vector<int> fac;
vector<int> ifac;

long long power(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

void init(int n) {
    fac = vector<int>(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % mod;
    ifac = vector<int>(n + 1);
    ifac[0] = 1;
    ifac[n] = power(fac[n], mod - 2);
    for (int i = n - 1; i >= 1; i--) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % mod;
}

int nCr(int n, int k) {
    if (k > n or k < 0) return 0;
    int ans = fac[n];
    ans = ans * ifac[k] % mod;
    ans = ans * ifac[n - k] % mod;
    return ans;
}
