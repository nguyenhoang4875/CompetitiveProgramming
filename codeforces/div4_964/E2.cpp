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
int p3[15];
set<int> sp;

void init() {
    p3[0] = 1;
    sp.insert(1);
    for (int i = 1; i <= 12; i++) {
        p3[i] = p3[i - 1] * 3;
        sp.insert(p3[i]);
    }
    // For(i, 1, 12) {
    //     cout << p3[i] << " ";
    // }
}

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
    // if (l == 1 and r == 2) {
    //     cout << 3 << el;
    //     return;
    // }
    // if (l == 1 and r == 3) {
    //     cout << 5 << el;
    //     return;
    // }
    // if (l == 2 and r == 3) {
    //     cout << 4 << el;
    //     return;
    // }

    int cur = l;
    vi cnt(15, 0);
    while (cur < r) {
        auto up = sp.upper_bound(cur);
        int len = distance(sp.begin(), up);

        if (*up > r) {
            cnt[len] = r - cur + 1;
            break;
        } else {
            cnt[len] = *up - cur;
            cur = *up;
        }
        if(cur == r) {
            cnt[len + 1]++;
        }
    }
    // debug(cnt);
    int firstI = -1;
    int c1 = 0;
    for(int i = 1; i <= 12; i++) {
        if(cnt[i] > 0 and firstI == -1) {
            firstI = i;
            // cnt[i] -= 1;
        }
        if(cnt[i] > 0) {
            c1 += cnt[i] * i;
        }
    }
    // debug(c1);
    // debug(cnt[firstI]);
    int ans = 2 * firstI + (c1 - firstI);
    cout << ans << el;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}