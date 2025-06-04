#include <bits/stdc++.h>
#define int long long

using namespace std;

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

//*** debug(x) ***//
#define DEBUG 0

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

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

void solve() {
    cin >> n;
    map<int, int> m;
    int c2 = 0;
    bool ok = false;
    int l4 = 0;
    vi v2, v3;
    set<int> st;
    For(i, 1, n) {
        int x;
        cin >> x;
        st.insert(x);
        m[x]++;
        if (m[x] == 2) {
            c2++;
            v2.push_back(x);
        }
        if (m[x] == 3) {
            v3.pb(x);
        }
        if (m[x] >= 4) {
            ok = true;
            l4 = x;
        }
    }
    if (ok) {
        debug("11");
        For(i, 1, 4) cout << l4 << " ";
        cout << el;
        return;
    }
    if (v2.empty()) {
        debug("22");
        cout << -1 << el;
        return;
    }
    if (v2.size() >= 2) {
        debug("33");
        cout << v2[0] << " " << v2[0] << " ";
        cout << v2[1] << " " << v2[1] << " ";
        cout << el;
        return;
    }
    if (v3.size() == 1) {
        int val = v3[0];
        int cnt = 0;
        for (auto e : st) {
            if (e < 3 * val and e != val) {
                cout << e << " " << val << " " << val << " " << val << el;
                return;
            }
        }
    }
    int val = v2[0];
    vi v;
    for (auto e : st) {
        v.pb(e);
    }
    for (auto e : v) {
        if (e == val) continue;
        auto low = lower_bound(all(v), e + 2 * val);
        if (low != v.begin()) {
            int len = low - v.begin();
            low;
            if (len >= 2) {
                auto l2 = upper_bound(all(v), e - 2 * val);
                for (auto it = l2; it != low; it++) {
                    if (*it == e or *it == val) continue;
                    if (e < *it + 2 * val) {
                        cout << e << " " << val << " " << val << " " << *it << el;
                        return;
                    }
                }
            }
        }
    }
    cout << -1 << el;
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