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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, m; cin >> n >> m;
    vi a(n + 1);
    For(i, 1, n) {
        cin >> a[i];
    }

    vi cnt(n + 5);
    For(i, 1, m) {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        cnt[u]++; cnt[v - 1]--;
    }
    For(i, 1, n) {
        cnt[i] += cnt[i - 1];
    }

    int tot = 0;
    int ans = 0;
    // debug(cnt);
    For(i, 1, n) cout << cnt[i] << " ";
    cout << el;
    for(int i = 1; i <= n; i++) {
        if(cnt[i] != 0) {
            if(tot >= 2) ans += (tot) * (tot - 1) / 2;
            tot = 0;
        } else {
            tot++;
        }
    }
    if(tot >= 2) ans += (tot) * (tot - 1) / 2;
    ans += n;
    cout << ans << el;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}