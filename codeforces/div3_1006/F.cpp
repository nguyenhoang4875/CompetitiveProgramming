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
int n, k;

void solve() {
    cin >> n >> k;
    vi a(n + 1, 0);
    a[1] = 1;
    int p = 1LL;
    for (int i = 2; i <= (n + 1) / 2; i++) {
        p <<= 1;
        int cnt = n / p;
        if ((cnt & 1) and (cnt % p) and (!(cnt & 1) and cnt % p == 0)) a[i] = 1;
    }
    For(i, 1, n / 2) { a[n - i + 1] = a[i]; }
    For(i, 1, n) { cout << a[i] * k << " "; }
    cout << el;
    // vvi a(100, vi(100));
    // a[1][1] = k;
    // for (int i = 2; i <= n; i++) {
    //     for (int j = 1; j <= i; j++) {
    //         if (j == 1) {
    //             a[i][j] = a[i - 1][j];
    //             continue;
    //         }
    //         if (j == i) {
    //             a[i][j] = a[i - 1][j - 1];
    //             continue;
    //         }
    //         a[i][j] = a[i - 1][j - 1] ^ a[i - 1][j];
    //     }
    // }

    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= i; j++) {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << el;
    // }
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