#include <bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***/
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

int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

void solve() {
    cin >> n;
    vi a(n);
    for (auto& x : a) cin >> x;

    int maxMask = (1 << n) - 1;
    int ans = n - 1;
    for (int mask = 0; mask <= maxMask; mask++) {
        vector<int> tmp;
        for (int i = 0; i < n; i++) {
            if (getBit(mask, i)) {
                tmp.pb(a[i]);
            }
        }
        int m = tmp.size();
        int ret = n - m;
        bool ok = true;
        if(m <= 2) {
            ans = min(ans, ret);
            continue;
        }
        for (int i = 0; i < m; i++) {
            if (!ok) break;
            for (int j = i + 1; j < m; j++) {
                if (!ok) break;
                for (int k = j + 1; k < m; k++) {
                    if (tmp[i] + tmp[j] <= tmp[k] or tmp[i] + tmp[k] <= tmp[j] or tmp[j] + tmp[k] <= tmp[i]) {
                        ok = false;
                        break;
                    }
                }
            }
        }
        if (ok) {
            ans = min(ans, ret);
        }
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