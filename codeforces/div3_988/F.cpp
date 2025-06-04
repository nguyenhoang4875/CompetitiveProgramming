#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout <<  '\n'
#define debug(x) cout <<  "[" << #x << "]" << " : " << (x) << endl
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
    return os << "}";
}
template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
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
#define For(i, a, b) for (int i = (a); i <= (int) (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int) (b); i--)
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

const long long oo = 2e10, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n, m, k;
int h[ms], a[ms];

void solve() {
    cin >> n >> m >> k;
    For(i, 1, n) cin >> h[i];
    For(i, 1, n) cin >> a[i];

    int mn = a[n] - m + 1;
    int mx = a[1] + m - 1;
    if(mx < mn) {
        cout << -1 << el;
        return;
    }

    int pl = 0, pr = n;

    pl = lower_bound(a + 1, a + n + 1, mn) - a;
    pr = upper_bound(a + 1, a + n + 1, mn) - a;
    pr--;

    auto check = [&](int num) {
        

    };

    int l = 0, r = oo;
    int ans = oo;
    while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout << ans << el;


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}