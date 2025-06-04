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
int n, l, r;
int a[ms];

void solve() {
    cin >> n >> l >> r;
    int len = r - l + 1;
    For(i, 1, n) cin >> a[i];
    vi vt;
    For(i, l, r) vt.pb(a[i]);
    vi vl, vr;
    For(i, 1, l - 1) vl.pb(a[i]);
    For(i, r + 1, n) vr.pb(a[i]);
    sort(all(vl));
    sort(all(vr));
    sort(all(vt));

    int sum = 0;
    for (auto e : vt) sum += e;
    int ans = sum;
    int tm = sum;

    for (int i = 0, j = len - 1; i < vl.size() and j >= 0; i++, j--) {
        if (vl[i] >= vt[j]) {
            break;
        }
        tm += vl[i];
        tm -= vt[j];
        ans = min(ans, tm);
    }
    tm = sum;
    for (int i = 0, j = len - 1; i < vr.size() and j >= 0; i++, j--) {
        if (vr[i] >= vt[j]) {
            break;
        }
        tm += vr[i];
        tm -= vt[j];
        ans = min(ans, tm);
    }
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}