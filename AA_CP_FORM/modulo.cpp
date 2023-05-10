#include<bits/stdc++.h>
#define int long long

using namespace std;

const int  MOD = 1e9 + 7;
vector<int> fac;

void initFac(int n) {
    fac.reserve(n + 1);
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
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
int modInverse(int n, int p) {
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little theorem.
int nCrModPFermat(int n, int r, int p) {
    if (n < r) return 0;
    if (r == 0) return 1;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int32_t main() {
    int n = 106;
    int r = 1e2;
    initFac(n);
    int ans = nCrModPFermat(n, r, MOD);
    cout << ans << endl;
}