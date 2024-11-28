#include <bits/stdc++.h>
#define int long long

using namespace std;
//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout <<  '\n'
#define debug(x) cout <<  "[" << #x << "]" << " : " << (x) << endl
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
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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
const int ms = 10 + 5;
int n, m;
char a[ms][ms];

int getBit(int n, int pos) {
    return (n >> pos) & 1;
}

void solve() {
    cin >> n >> m;
    For(i, 0, n -1) {
        For(j, 0, m - 1) { cin >> a[i][j]; }
    }

    auto check = [&](vi &cnt) {
        bool ok = true;
        For(i, 0, m - 1) {
            if (cnt[i] == 0) {
                ok = false;
            }
        }
        return ok;
    };

    vi cnt(15, 0);
    int ans = 15;
    for(int mask = 1; mask < (1 << n); mask++) {
        int num = __builtin_popcount(mask);
        cnt = vi(15, 0);
        for(int pos = 0; pos < n; pos++) {
            if(getBit(mask, pos)) {
                For(i, 0, m - 1) {
                    if(a[pos][i] == 'o') {
                        cnt[i]++;
                    }
                }
            }
        }
        // debug(cnt);
        if(check(cnt)) {
            // cout << "pass" << el;
            // cout << "num = " << num << el;
            ans = min(ans, num);
        }
    }

    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}