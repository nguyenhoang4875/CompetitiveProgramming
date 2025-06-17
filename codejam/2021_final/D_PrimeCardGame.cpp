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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 5e6 + 5e3;

vector<int> primeNumber;
void sievePrime(int n) {
    vector<bool> prime(n + 1, true);
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p) prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p]) primeNumber.push_back(p);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (auto& x : a) cin >> x;

    auto getScore = [&](int mask) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) sum += a[i];
        }
        int ret = oo;
        auto low = lower_bound(all(primeNumber), sum);
        if (sum == *low) {
            ret = min(ret, *(low + 1) - sum);
        } else {
            ret = min(ret, *low - sum);
        }
        if (low != primeNumber.begin()) {
            ret = min(ret, sum - *(low - 1));
        }
        return ret;
    };

    int maxMask = (1LL << n) - 1;
    vi score(maxMask + 1);
    for (int mask = 1; mask <= maxMask; mask++) {
        score[mask] = getScore(mask);
    }

    vvi f(m + 1, vi(maxMask + 1, oo));  // f[i][mask] minimum of max score for i-th players use mask cards
    f[0][0] = 0;

    for (int mask = 0; mask <= maxMask; mask++) {
        for (int p = 0; p < m; p++) {
            if (f[p][mask] == oo) continue;
            int canUse = mask ^ maxMask;
            int sub = canUse;
            while (sub) {
                f[p + 1][sub ^ mask] = min(f[p + 1][sub ^ mask], max(f[p][mask], score[sub]));
                sub = (sub - 1) & canUse;
            }
        }
    }
    cout << f[m][maxMask] << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sievePrime(ms);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }

    return 0;
}