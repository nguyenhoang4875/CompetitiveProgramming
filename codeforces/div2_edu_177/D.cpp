#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
    return os << "}";
}
#else
#define del
#define debug(x)
#endif

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 2e18, mod = 998244353;
const int ms = 5e5 + 5;

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
    vi c(26);
    int n = 0;
    for (int i = 0; i < 26; i++) {
        cin >> c[i];
        n += c[i];
    }

    vi a;
    for (int i = 0; i < 26; i++) {
        if (c[i] > 0) a.pb(c[i]);
    }

    int no = (n + 1) / 2;
    int ne = n / 2;

    vvi f(a.size() + 1, vi(no + 1));
    f[0][0] = 1;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j <= no; j++) {
            // if (f[i][j] == 0) continue;
            f[i + 1][j] += f[i][j];
            f[i + 1][j] %= mod;
            if (j + a[i] <= no) {
                f[i + 1][j + a[i]] += f[i][j];
                f[i + 1][j + a[i]] %= mod;
            }
        }
    }

    int s1 = fac[no] * fac[ne] % mod;
    for (int i = 0; i < 26; i++) { s1 = s1 * inv[c[i]] % mod; }

    int ans = s1 * f[a.size()][no] % mod;
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    init(ms);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}