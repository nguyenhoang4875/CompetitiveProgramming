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
int n, m, k;

void solve() {
    cin >> n >> m >> k;
    string s;
    cin >> s;
    s = " " + s;
    set<int> vl;
    vl.insert(0);

    For(i, 1, n) {
        if (s[i] == 'L') {
            vl.insert(i);
        }
    }
    vl.insert(n + 1);
    int cur = 0;
    int lenSwim = 0;
    for (int i = 0; i <= n; i++) {
        debug(i);
        if (s[i] == 'C') {
            debug(1);
            cout << "NO" << el;
            return;
        }
        if (vl.count(i)) {
            int nextL = *vl.upper_bound(i);

            debug(i);
            debug(nextL);
            if (nextL - i <= m) {
                i = nextL;
            } else {
                i += m;
            }
            i--;
            continue;
        }
        lenSwim++;
        if (lenSwim > k) {
            debug(2);
            cout << "NO" << el;
            return;
        }
    }
    cout << "YES" << el;
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