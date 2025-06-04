#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
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
int l, r;

int power(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) ans *= a;
        n /= 2;
        a *= a;
    }
    return ans;
}

void solve() {
    cin >> l >> r;
    cout << l << " " << r << el;
    int cl = 1, cr = 1;
    int p3 = 1;
    for (int i = 0; i <= 20; i++) {
        if (l <= p3) {
            cl = i;
            break;
        }
        p3 *= 3;
    }
    for (int i = cl; i <= 20; i++) {
        if (r <= p3) {
            cr = i;
            break;
        }
        p3 *= 3;
    }
    debug(pii(l, r));
    debug(pii(cl, cr));
    vi cnt(15, 0);
    if(cl == cr) {
        // cnt[cl - 1] = (r - l + 1);
        cout << r - l << el;
        int num = 2 * cl * (r - l) + cl;
        cout << num << el;
        return;
    }
    int c1 = 0;
    if(l != 0 and power(3, cl) > l) {
        
        cnt[cl - 1] = power(3, cl) - l;
        c1 += cnt[cl - 1];
    }
    for(int i = cl; i < cr; i++) {
        cnt[i] = power(3, i) - power(3, i - 1);
        c1 += cnt[i];
    }
    if(r > power(3, cr - 1)) {
        cnt[cr] = r - power(3, cr - 1);
        c1 += cnt[cr];
    }
    debug(c1);
    debug(cnt);

    int ans = 2 * (c1 - cnt[cl - 1]) + cnt[cl - 1];
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