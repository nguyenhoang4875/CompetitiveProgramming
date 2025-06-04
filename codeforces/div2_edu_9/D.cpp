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
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
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

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);
    Rep(i, n) cin >> a[i];

    map<int, int> cnt;
    for (auto& e : a) {
        if (e <= m) cnt[e]++;
    }

    vi num(m + 1);
    for (int d = 1; d <= m; d++) {
        if (!cnt.count(d)) continue;
        for (int i = d; i <= m; i += d) { num[i] += cnt[d]; }
    }
    int mx = 0, l = 1;
    For(i, 1, m) {
        if(num[i] > mx) {
            mx = num[i];
            l = i;
        }
    }
    vi res;
    Rep(i, n) {
        if (l % a[i] == 0) res.pb(i);
    }
    cout << l << " " << res.size() << el;
    for (auto& x : res) cout << x + 1 << " ";
    cout << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}