#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

using namespace std;

//*** debug(x) ***//
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

#if 1
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}
#endif

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}

//*** define ***//
#define For(_i, _a, _b) for (int _i = (_a); _i < (_b); _i++)
#define Fori(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e6 + 5;
int n, k;
string s;
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
    cin >> s;
    int cntTop = 0;
    For(i, 0, n) if (s[i] == '1') cntTop++;

    if (cntTop == 0) {
        // find nCk
        cout << nCr(n - 1, k - 1) << '\n';
        return;
    }
    if (cntTop % k != 0) {
        cout << "0\n";
        return;
    }
    int eachTop = cntTop / k;
    int time = 0;
    int cnt = 0;
    int cntZero = 0;
    int l = 0, r = 0;
    int ans = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            cnt++;
        else {
            if (cnt == 0) cntZero++;
        }
        if (cnt == eachTop) {
            if (time != 0) {
                ans = (ans * (1 + cntZero)) % mod;
            }
            time++;
            cnt = 0;
            cntZero = 0;
        }
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    initFac(ms);
    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}