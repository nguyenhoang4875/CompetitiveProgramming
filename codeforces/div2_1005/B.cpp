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

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;
int a[ms];

void solve() {
    cin >> n;
    set<int> st;
    set<int> dup;
    For(i, 1, n) {
        int x;
        cin >> x;
        a[i] = x;
        if (st.count(x)) dup.insert(x);
        st.insert(x);
    }
    if (st.size() == n) {
        cout << 1 << " " << n << el;
        return;
    }

    int cnt = 0;
    vii ans;
    int l = 1;

    for (int i = 1; i <= n; i++) {
        if (!dup.count(a[i])) {
            cnt++;
        } else {
            if (cnt > 0) ans.push_back({cnt, l});
            cnt = 0;
            l = i + 1;
        }
    }
    if (cnt > 0) ans.push_back({cnt, l});
    // debug(ans);
    if (ans.empty()) {
        cout << 0 << el;
        return;
    }
    sort(all(ans));
    cout << ans.back().S << " " << ans.back().S + ans.back().F - 1 << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}