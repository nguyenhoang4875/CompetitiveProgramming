#include <bits/stdc++.h>
#define int long long

using namespace std;

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
//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout <<  '\n'
#define debug(x) cout <<  "[" << #x << "]" << " : " << (x) << endl
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


void solve() {
    int n; cin >> n;
    vi a(n + 1);
    For(i, 1, n) cin >> a[i];

    string s; cin >> s;
    s = " " + s;

    vi preA(n + 2), sufA(n + 2);
    For(i, 1, n) preA[i] += preA[i - 1] + ((s[i] == 'A') ? a[i] : 0);
    Rof(i, n, 1) sufA[i] += sufA[i + 1] + ((s[i] == 'A') ? a[i] : 0);

    vi preB(n + 2), sufB(n + 2);
    For(i, 1, n) preB[i] += preB[i - 1] + ((s[i] == 'B') ? a[i] : 0);
    Rof(i, n, 1) sufB[i] += sufB[i + 1] + ((s[i] == 'B') ? a[i] : 0);
    debug(a);
    debug(s);
    debug(preA); debug(sufA); del;
    debug(preB); debug(sufB); del;


    int ans = max(preA[n], preB[n]);
    For(i, 1, n) {
        ans = max(ans, preA[i] + sufB[i + 1]);
    }
    For(i, 1, n) {
        ans = max(ans, preB[i] + sufA[i + 1]);
    }
    cout << ans << el;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}