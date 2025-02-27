#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 2e18, mod = 1e6 + 3;
const int ms = 2e6 + 5;

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

    if (ms < mod) {
        inv = vector<int>(n + 1);
        inv[0] = 1;
        inv[n] = power(fac[n], mod - 2);
        for (int i = n - 1; i >= 1; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % mod;
    }
}

int nCr(int n, int k) {
    if (k > n) return 0;
    int ans = fac[n];
    if (ms < mod) {
        ans = ans * inv[k] % mod;
        ans = ans * inv[n - k] % mod;
        return ans;
    }
    ans = ans * power(fac[k], mod - 2) % mod;
    ans = ans * power(fac[n - k], mod - 2) % mod;
    return ans;
}

void solve() {
    int r, c, n;
    cin >> r >> c >> n;
    vii a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].F >> a[i].S;
    }
    a.push_back({1, 1});
    a.push_back({r, c});
    sort(all(a));
    n = a.size();

    vi f(n + 1);  // number ways at i-th points with max snacks
    f[0] = 1;
    map<int, int> cntSnack;
    cntSnack[0] = 0;
    for (int i = 0; i < n; i++) {
        int cntMax = -1;
        vi preMax;
        for (int j = 0; j < i; j++) {
            if (a[i].S >= a[j].S) {
                if (!cntSnack.count(j)) continue;
                if (cntSnack[j] > cntMax) {
                    cntMax = cntSnack[j];
                    preMax.clear();
                    preMax.push_back(j);
                } else if (cntSnack[j] == cntMax) {
                    preMax.push_back(j);
                }
            }
        }
        cntSnack[i] = cntMax + 1;
        for (auto& e : preMax) {
            int cn = a[i].F - a[e].F + a[i].S - a[e].S;
            int ck = max(a[i].F - a[e].F, a[i].S - a[e].S);
            f[i] += f[e] * nCr(cn, ck) % mod;
            f[i] %= mod;
        }
    }
    cout << f[n - 1] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init(ms);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}