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

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define all1(x) (x).begin() + 1, (x).end()
#define el '\n'
#define F first
#define S second
#define Rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define For(i, a, b) for (int i = (a); i <= (int)(b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int)(b); i--)
#define Fore(it, x) for (auto it = (x).begin(); it != (x).end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const long long oo = 1e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vi a(n);
    Rep(i, n) cin >> a[i];
    vi p0;
    bool found = false;
    int sum = 0, curMax = a[0];
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            sum = 0;
            p0.pb(i);
            continue;
        }
        sum += a[i];
        curMax = max(curMax, sum);
        sum = max(sum, 0LL);
        if (curMax > k) {
            debug("n1");
            cout << "NO" << el;
            return;
        }
        if (curMax == k) found = true;
    }
    if (found) {
        cout << "YES" << el;
        Rep(i, n) {
            if (s[i] == '0') cout << -oo << " ";
            else cout << a[i] << " ";
        }
        cout << el;
        return;
    }
    int m = p0.size();
    if (m == 0) {
        debug("n2");
        if (!found) {
            cout << "NO" << el;
            return;
        }
    }
    int l = 0;
    if (m > 1) {
        l = p0[m - 2] + 1;
        for (int i = 0; i < l; i++)
            if (s[i] == '0') a[i] = -oo;
    }
    int id = -1;
    for (int i = l; i < n; i++) {
        if (s[i] == '0') { id = i; }
    }
    debug(id);
    debug(l);

    auto check = [&](int val) {
        a[id] = val;
        debug(val);
        debug(a);
        int sum = 0;
        int ret = a[l];
        for (int i = l; i < n; i++) {
            sum += a[i];
            ret = max(ret, sum);
            sum = max(sum, 0LL);
        }
        debug(ret);
        return ret;
    };
    int ll = -1e13, rr = 1e12;
    int ans = oo;
    while (ll <= rr) {
        int mid = (ll + rr) / 2;
        debug(mid);
        if (check(mid) >= k) {
            debug(mid);
            ans = mid;
            rr = mid - 1;
        } else ll = mid + 1;
    }
    debug(k);
    debug(ans);
    debug(check(ans));
    if (k == check(ans)) {
        cout << "YES" << el;
        Rep(i, n) cout << a[i] << " ";
        cout << el;
    } else {
        debug("N3");
        cout << "NO" << el;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) { solve(); }
    return 0;
}