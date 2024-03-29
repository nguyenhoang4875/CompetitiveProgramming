#include <bits/stdc++.h>
#define int long long

using namespace std;

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n, k;

vector<int> fac;

void initFac(int n) {
    fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
}

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

int nCr(int n, int k) {
    int ans = fac[n];
    ans = ans * power(fac[k], mod - 2) % mod;
    ans = ans * power(fac[n - k], mod - 2) % mod;
    return ans;
}

void solve() {
    cin >> n >> k;
    initFac(n);
    cout << nCr(n, k) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}