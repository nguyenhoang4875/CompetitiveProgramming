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

const long long oo = 2e18, mod = 998244353;
const int ms = 2e5 + 5;

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vvi a(n + 1, vi(m + 1));
    For(i, 1, n) {
        For(j, 1, m) {
            char c;
            cin >> c;
            if(c == 'X') a[i][j] = 1;
        }
    }
    // f[i][j][k]: number of way at row i column j, from upper(1) or same(0)row
    vector<vvi> f(n + 1, vvi(m + 1, vi(2))); 
    vector<vvi> ps(n + 1, vvi(m + 1, vi(2))); // prefixSum same for f 

    For(i, 1, m) {
        if(a[n][i]) f[n][i][0] = 1;
    }

    For(i, 1, m) {
        ps[n][i][0] = (ps[n][i - 1][0] + f[n][i][0]) % mod;
    }

    For(i, 1, m) {
        if(a[n][i]) {
            int l = max(i - d, 1LL);
            int r = min(i + d, m);
            f[n][i][1] =  ((ps[n][r][0] - ps[n][l - 1][0] + mod) - f[n][i][0] + mod) % mod;
        }
    }

    For(i, 1, m) {
        ps[n][i][1] = (ps[n][i - 1][1] + f[n][i][1]) % mod;
    }
    // https://codeforces.com/contest/2091/submission/312439313




  

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