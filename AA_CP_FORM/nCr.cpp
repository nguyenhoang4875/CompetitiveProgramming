#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n, k;

vector<int> fac;
vector<int> inv;

int power(int a, int n) {
    int ans = 1;
    a = a % mod;
    while (n > 0) {
        if (n & 1) ans = (ans * a) % mod;
        n /= 2;
        a = (a * a) % mod;
    }
    return ans;
}

void init(int n) {
    fac = vector<int>(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % mod;

    inv = vector<int>(n + 1);
    inv[0] = 1;
    inv[n] = power(fac[n], mod - 2);
    for (int i = n - 1; i >= 1; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
}

int nCr(int n, int k) {
    if (k > n) return 0;
    int ans = fac[n];
    ans = ans * inv[k] % mod;
    ans = ans * inv[n - k] % mod;
    return ans;
}

void solve() {
    cin >> n >> k;
    init(n);
    cout << nCr(n, k) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}