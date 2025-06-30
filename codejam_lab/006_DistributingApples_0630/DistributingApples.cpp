#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0; i < (int)n; ++i)
#define For(i, a, b) for (int i = (a); i <= (int)b; ++i)
#define Rof(i, b, a) for (int i = (b); i >= (int)a; --i)
#define Fore(i, v) for (auto i = (v).begin(); i != (v).end(); ++i)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
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

void solve() {
    init(2e6);

    int n, m;
    cin >> n >> m;
    cout << nCr(n + m - 1, n - 1) << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}