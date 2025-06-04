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
#if 1
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os,
                                  Container const& x) {
    os << "{ ";
    for (auto& y : x) os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream& operator<<(ostream& os, pair<X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}
#endif

//*** START CODING ***//

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 3e5 + 5;
int n, k;
int a[ms], x[ms];

void solve() {
    cin >> n >> k;
    For(i, 1, n) cin >> a[i];
    For(i, 1, n) {
        cin >> x[i];
        x[i] = abs(x[i]);
    }
    vi cnt(n + 5, 0);
    For(i, 1, n) { cnt[x[i]] += a[i]; }
    int sum = 0;
    For(i, 0, n) {
        sum += cnt[i];
        if (i * k < sum) {
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