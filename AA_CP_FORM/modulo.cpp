#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;
vector<int> fac;

void initFac(int n) {
    fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
}

int power(int x, int y) {
    int res = 1;
    x = x % mod;
    while (y > 0) {
        if (y & 1) res = (res * x) % mod;
        y /= 2;
        x = (x * x) % mod;
    }
    return res;
}

// Returns n^(-1) mod p
int modInverse(int n) { return power(n, mod - 2); }

// Returns nCr % p using Fermat's little theorem.
int nCrModPFermat(int n, int r) {
    if (n < r) return 0;
    if (r == 0) return 1;
    return fac[n] * modInverse(fac[r]) % mod * modInverse(fac[n - r]) % mod;
}

// Find gcd(a, b) and find x, y: a * x + b * y = gcd(a, b)
int extendGcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extendGcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

// Find (1 / a)  % mod, codition gcd(a, m) = 1
int modInvNotPrime(int a, int m) {
    int x, y;
    int gcd = extendGcd(a, m, x, y);
    if (gcd != 1) return -1;
    x = (x % m + m) % m;
    return x;
}

int32_t main() {
    int n = 1e6;
    int r = 1e2;
    initFac(n);

    int ans = nCrModPFermat(n, r);
    cout << ans << endl;

    cout << modInvNotPrime(7, 15) << endl;

    return 0;
}