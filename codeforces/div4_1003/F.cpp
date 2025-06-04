#include <bits/stdc++.h>
#define int long long

using namespace std;

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

//*** debug(x) ***//
#define DEBUG 0

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


//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n;

void solve() {
    cin >> n;
    vi a(n);
    for(auto &x: a) {
        cin >> x;
    } 

    vvi adj(n);

    For(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        debug(n);
        debug(u);
        debug(v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vi ans(n, 0);

    For(u, 0, n - 1) {
        for(auto v: adj[u]) {
            if( v > u and a[u] == a[v]) {
                ans[u] = 1;
            }
        }
    }

    For(u, 0, n - 1) {
        if(adj[u].size() < 2) continue;

        vi nei;
        for(auto v: adj[u]) {
            nei.pb(a[v]);
        }
        sort(all(nei));

        int cnt = 1;
        For(i, 1, nei.size() - 1) {
            if(nei[i] == nei[i - 1]) cnt++;
            else {
                if(cnt >= 2) {
                    ans[nei[i - 1] - 1] = 1;
                }
                cnt = 1;
            }
        }
        if(cnt >= 2) ans[nei.back() - 1] = 1;
    }
    for(auto e: ans) cout << e;

    cout << el;




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