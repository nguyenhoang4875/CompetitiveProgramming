#include <bits/stdc++.h>
#define int long long

using namespace std;
//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout << '\n'
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << ", ";
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

#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

using vb = vector<bool>;
using vvb = vector<vb>;
using vc = vector<char>;
using vvc = vector<vc>;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int, int>;
using vii = vector<pii>;

//*** START CODING ***//

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, m;
int maxCover = 0;
vvi memo;

void cal(vi& a, vi& c) {
    vvi dp(n + 1, vi(m + 1, 0));
    For(i, 0, n - 1) {
        For(j, 0, m) {
            // cout << i << " " << j << " " << dp[i][j] << el;
            auto up = upper_bound(all(a), a[i] + c[j] - 1);
            // cout << *up << el;
            int num = up - (a.begin() + i);
            // cout << num << el;
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if (i + num <= n and j < m) {
                dp[i + num][j + 1] = max(dp[i + num][j + 1], dp[i][j] + num);
            }
        }
    }
    // del;
    // For(i, 0, n){
    //     For(j, 0, m) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << el;
    // }
    maxCover = max(maxCover, dp[n][m]);
}

void solve() {
    cin >> n >> m;
    vi a(n), b(m);
    For(i, 0, n - 1) cin >> a[i];
    For(i, 0, m - 1) cin >> b[i];

    sort(all(a));

    vi p;
    For(i, 0, m - 1) { p.pb(i); }
    debug(pii({n, m}));
    vi c(m);
    do {
        For(i, 0, m - 1) { c[i] = b[p[i]]; }
        cal(a, c);

    } while (next_permutation(all(p)));

    int ans = n - maxCover;
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}