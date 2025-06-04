#include <bits/stdc++.h>
#define int long long

using namespace std;

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
int n;
string s;

void solve() {
    cin >> s;
    n = s.size();
    int l = 0, r = n - 1;
    while (l <= r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else
            break;
    }
    debug(l);
    debug(r);

    if (l >= r) {
        cout << 0 << el;
        return;
    }

    auto check = [&](int k) {
        map<char, int> m;
        debug(l + k);
        for (int i = l; i < l + k; i++) {
            m[s[i]]++;
        }
        debug(m);
        int tl = l, tr = r;
        while (tl <= tr) {
            debug(tl);
            debug(tr);
            if (tr < l + k) {
                return true;
            }
            if (tl < l + k) {
                debug(m[s[tr]]);
                debug(s[tr]);
                if (!m.count(s[tr]) or m[s[tr]] <= 0) return false;
                m[s[tr]]--;
            } else {
                debug(s[tl]);
                debug(s[tr]);
                if (s[tl] != s[tr]) return false;
            }
            tl++;
            tr--;
        }
        return true;
    };

    int ans = n;
    int ll = 1, rr = (r - l + 1);
    while (ll <= rr) {
        int mid = (ll + rr) / 2;
        debug(mid);
        if (check(mid)) {
            ans = mid;
            rr = mid - 1;
        } else
            ll = mid + 1;
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