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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m, l;

void solve() {
    cin >> n >> m >> l;
    map<int, int> h;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        h[x] = y;
    }
    map<int, vi> pows;
    For(i, 0, m - 1) {
        int x, y;
        cin >> x >> y;
        pows[x].pb(y);
    }
    debug(h);
    debug(pows);
    int cp = 0;

    priority_queue<int> q;
    int ans = 0;
    auto it = pows.begin();
    for (auto& [f, s] : h) {
        debug(f);
        debug(s);
        while (it != pows.end() and f >= it->F) {
            debug(it->S);
            for (auto e : it->S) q.push(e);
            it++;
            if (it != pows.end()) {
                debug(it->F);
            }
        }
        int cur = f;
        while (cur + cp <= s) {
            if (q.empty()) {
                cout << -1 << el;
                return;
            } else {
                debug(q.top());
                // cur += q.top();
                cp += q.top();
                ans++;
                q.pop();
            }
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