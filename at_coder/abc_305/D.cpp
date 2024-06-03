#include <bits/stdc++.h>
#define int long long

using namespace std;

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** debug(x) ***//
#if 1
#define debug(x) cout <<  "[" << #x << "]" << " : " << (x) << endl

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

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}
#endif

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
int a[ms];

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];

    map<int, pii> timeSleep;

    For(i, 2, n) {
        if (i % 2 == 1) {
            int tm = 0;
            if (!timeSleep.empty()) {
                tm += prev(timeSleep.end())->S.F;
            }
            timeSleep[a[i]] = {tm + a[i] - a[i - 1], a[i - 1]};
        }
    }

    debug(timeSleep);

    auto getTimeAt = [&](int val) {
        auto iLow = timeSleep.lower_bound(val);
        if (iLow == timeSleep.end()) {
            return prev(timeSleep.end())->S.F;
        }
        if (val == iLow->F) return iLow->S.F;

        if (val > iLow->S.S) {
            return iLow->S.F - (iLow->F - val);
        }
        if (iLow != timeSleep.begin()) {
            return (prev(iLow)->S.F);
        }
        return 0LL;
    };

    int q;
    cin >> q;
    int l, r;
    while (q--) {
        cin >> l >> r;
        int ans = getTimeAt(r) - getTimeAt(l);
        cout << ans << el;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}