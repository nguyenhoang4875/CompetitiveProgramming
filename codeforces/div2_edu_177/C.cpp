#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout <<  '\n'
#define debug(x) cout <<  "[" << #x << "]" << " : " << (x) << endl
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
#define For(i, a, b) for (int i = (a); i <= (int) (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int) (b); i--)
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

void solve() {
    int n;
    cin >> n;
    vi p(n + 1), d(n + 1);
    For(i, 1, n) cin >> p[i];
    For(i, 1, n) cin >> d[i];

    map<int, int> m1;
    For(i, 1, n) {
        m1[i] = p[i];
        // m2[p[i]] = i;
    }
    // debug(m1);
    // debug(m2);

    int cnt = 0;
    vi ans;
    For(i, 1, n) {
        int cur = d[i];
        set<int> st;
        vi path;
        while(true) {
            if(st.count(cur) or m1[cur] == 0) break;
            st.insert(cur);
            path.pb(cur);
            cur = m1[cur];
            // cur = m1[cur];
            // debug(cur); debug(m1[cur]);
            cnt++;
            // if(cnt == 10) break;
        }
        cout << cnt << " ";
        for(auto e: st) m1[e] = 0;
        st.clear();
        // ans.pb(cnt);
    }
    cout << el;


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}