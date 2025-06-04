#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
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

const long long oo = 1e9, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;

    int id = 0;
    int p = 1;
    int ans = 0;
    while (true) {
        if (id == 0) {
            p = 1;
            ans += max(min(r1, r2) - max(l1, l2) + 1, 0LL);
            debug(ans);
        } else {
            p *= k;
            int t1 = (l2 + p - 1) / p;
            int t2 = r2 / p;
            debug(p);
            debug(t1);
            debug(t2);

            if (t1 <= t2) {
                ans += max(min(r1, t2) - max(l1, t1) + 1, 0LL);
                debug(ans);
            }
        }
        id++;
        if (p > 1e9) break;
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