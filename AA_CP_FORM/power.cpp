#include <bits/stdc++.h>
#define int long long

using namespace std;

const int mod = 1e9 + 7;
int cnt;

// power iterator
int power(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) ans *= a;
        n /= 2;
        a *= a;
    }
    return ans;
}

// power mod p iterator without mod param
int powerMod(int a, int n) {
    int ans = 1;
    a = a % mod;
    while (n > 0) {
        if (n & 1) ans = (ans * a) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return ans;
}

int modInv(int a) { return powerMod(a, mod - 2); }

// power mod p iterator
int powerMod(int a, int n, int p) {
    int ans = 1;
    a = a % p;
    while (n > 0) {
        if (n & 1) ans = (ans * a) % p;
        n /= 2;
        a = (a * a) % p;
    }
    return ans;
}

// power recursion
int powerRec(int a, int n) {
    if (n == 0) return 1;  // base case
    int ans = powerRec(a, n / 2);
    ans *= ans;
    if (n & 1) ans *= a;
    return ans;
}

// power recursion mode p
int powerRecMod(int a, int n, int p) {
    if (n == 0) return 1;  // base case
    int ans = powerRecMod(a, n / 2, p);
    ans = (ans * ans) % p;
    if (n & 1) ans = (ans * a) % p;
    return ans;
}

vector<int> fac;     // factorial mod p
vector<int> facRev;  // 1 / fac mod p
int revFact(int t, int p) { return powerMod(t, p - 2, p); }

void initFacMod(int n, int p) {
    fac.resize(n + 1);
    facRev.resize(n + 1);
    fac[0] = 1;
    fac[0] = revFact(fac[0], p);
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i % p;
        facRev[i] = revFact(fac[i], p);
    }
}

int nCr(int n, int r) { return fac[n] * facRev[r] % mod * facRev[n - r] % mod; }

void solve() {
    int a = 9, n = 1234;
    cout << powerMod(a, n, mod) << '\n';
    cout << powerRecMod(a, n, mod) << '\n';
    n = 1e6;
    int r = 1e2;
    initFacMod(n, mod);
    int ans = nCr(n, r);
    cout << ans << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}