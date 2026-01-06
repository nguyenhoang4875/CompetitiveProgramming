const long long oo = 2e18, mod = 1e9 + 7;

long long power(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

int modInverse(int n) { return power(n, mod - 2); }

int nCr(int n, int k) {
    if (k > n or k < 0) return 0;
    if (k > n - k) k = n - k;

    long long tu = 1, mau = 1;
    for (int i = 0; i < k; i++) {
        tu = tu * (n - i) % mod;
    }
    for (int i = 1; i <= k; i++) {
        mau = mau * i % mod;
    }
    return tu * modInverse(mau) % mod;
}