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
int n, m;

void solve() {
    cin >> n >> m;
    vector<set<int>> st(n + 1);
    for (int i = 1; i <= n; i++) {
        For(j, 1, m) {
            int x;
            cin >> x;
            st[i].insert(x);
        }
    }
    vb check(n + 1, false);
    vi ans;
    int cnt = 0;
    vi sq;
    For(val, 0, n - 1) {
        For(i, 1, n) {
            if (st[i].count(val)) {
                sq.pb(i);
                if (check[i]) {
                    cout << -1 << el;
                    return;
                }
                check[i] = true;
            }
        }
    }

    int val = 0;
    For(i, 1, m) {
        for (auto e : sq) {
            if (!st[e].count(val)) {
                cout << -1 << el;
                return;
            }
            val++;
        }
    }
    for (auto e : sq) cout << e << " ";
    cout << el;
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