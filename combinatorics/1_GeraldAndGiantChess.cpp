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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

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
    int h, w, n;
    cin >> h >> w >> n;
    vii v;
    For(i, 1, n) {
        int x, y;
        cin >> x >> y;
        v.pb({x, y});
    }
    v.pb({h, w});  // add ending point
    sort(all(v));
    init(h + w + 5);
    n = v.size();
    vi f(n + 2, 0);  // number of ways to first i-th points
    for (int i = 0; i < n; i++) {
        f[i] = nCr(v[i].F - 1 + v[i].S - 1, v[i].F - 1);
        for (int j = 0; j < i; j++) {
            if (v[i].F >= v[j].F and v[i].S >= v[j].S) {
                f[i] -= f[j] * nCr(v[i].F - v[j].F + v[i].S - v[j].S, v[i].F - v[j].F) % mod;
                f[i] = (f[i] + mod) % mod;
            }
        }
    }
    // ans = number path from start to end minus number path through black cell
    cout << f[n - 1] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}