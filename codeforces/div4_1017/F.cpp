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
    int n, m, k;
    cin >> n >> m >> k;
    vvi a(n + 1, vi(m + 1, -1));

    a[1][1] = 0;
    vi cnt(k, (n * m) / k);
    // debug(a);
    For(i, 1, n) {
        For(j, 1, m) {
            if(i == 1 and j == 1) continue;
            int val = -1;
            val = max(val, a[i - 1][j] + 1);
            val = max(val, a[i][j - 1] + 1);
            val %= k;
            while (cnt[val] == 0 or val == a[i - 1][j] or val == a[i][j - 1]) {
                val++;
                val %= k;
            }
            a[i][j] = val;
            if(val == a[i - 1][j] or val == a[i][j - 1]) {
                cout << "-----------------------";
                cout << val << el;
                cout << "-----------------------";
            }
            cnt[val]--;
        }
    }
    For(i, 1, n) {
        For(j, 1, m) {
            cout << a[i][j] + 1 << " ";
            // int val = a[i][j];
            // if(val == a[i - 1][j] or val == a[i][j - 1]) {
            //     cout << "-----------------------";
            //     cout << val << el;
            //     cout << "-----------------------";
            // }
        }
        cout << el;
    }
    // debug("PASS");

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