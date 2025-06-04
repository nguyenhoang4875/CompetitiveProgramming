#include <bits/stdc++.h>
#define int long long

using namespace std;

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

//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
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
#define debug(x)
#endif

//*** START CODING ***//

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, c, d;

void solve() {
    cin >> n >> c >> d;
    vi a(n * n);
    For(i, 0, n * n - 1) cin >> a[i];

    sort(all(a));
    vi b(n * n);
    b[0] = a[0];

    for (int i = 0; i < n; i++) {
        if (i > 0) b[i * n] = b[(i - 1) * n] + c;
        for (int j = 1; j < n; j++) {
            b[i * n + j] = b[i * n + j - 1] + d;
        }
    }

    sort(all(b));
    for (int i = 0; i < n * n; i++) {
        if (a[i] != b[i]) {
            cout << "NO" << el;
            return;
        }
    }
    cout << "YES" << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}