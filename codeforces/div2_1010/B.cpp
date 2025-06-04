#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

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
const int ms = 2e5 + 5;

vi getPrimeFactors(int n) {
    vi ans;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ans.pb(i);
            n /= i;
        }
    }
    if (n != 1) ans.pb(n);
    return ans;
}

void solve() {
    int x, n, m;
    cin >> x >> n >> m;
    if (n + m >= 30) {
        cout << "0 0" << el;
        return;
    }

    vi a = getPrimeFactors(x);
    int co = 0, ce = 0;
    for (auto e : a) {
        if (e & 1) co++;
        else ce++;
    }
    debug(co);
    debug(ce);
    // debug(a);
    // find max:
    auto getMax = [](int x, int n, int m, int co, int ce) {
        while (x > 0 and n > 0) {
            x = (x) / 2;
            n--;
        }
        debug(x);
        while (x > 0 and m > 0) {
            x = (x + 1) / 2;
            m--;
        }
        return x;
    };

    auto getMin = [](int x, int n, int m, int co, int ce) {
        while (x > 0 and m > 0) {
            x = (x + 1) / 2;
            m--;
        }
        while (x > 0 and n > 0) {
            x = (x) / 2;
            n--;
        }
        return x;
    };
    // find min:
    int mn = getMin(x, n, m, co, ce);
    int mx = getMax(x, n, m, co, ce);
    cout << mn << " " << mx << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}