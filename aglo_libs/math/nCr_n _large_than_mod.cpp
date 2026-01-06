const int mod = 1e6 + 3;
int fac[mod + 5], ifac[mod + 5];

long long power(long long a, long long b) {
    long long ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i < mod; i++) fac[i] = 1LL * fac[i - 1] * i % mod;

    ifac[mod - 1] = power(fac[mod - 1], mod - 2);
    for (int i = mod - 2; i >= 0; i--) ifac[i] = 1LL * ifac[i + 1] * (i + 1) % mod;
}

int nCr(int n, int k) {
    if (k > n or k < 0) return 0;
    return (1LL * fac[n] * ifac[k] % mod) * ifac[n - k] % mod;
}

// Hàm tính nCk với n có thể lớn hơn M
int comb(long long n, long long k) {
    if (k > n or k < 0) return 0;
    int res = 1;
    while (n > 0) {
        res = 1LL * res * nCr(n % mod, k % mod) % mod;
        n /= mod;
        k /= mod;
    }
    return res;
}
