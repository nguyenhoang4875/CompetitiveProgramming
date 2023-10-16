#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

using namespace std;

//*** debug(x) ***//
#define debug(x)             \
    cout << "[" << #x << "]" \
         << " : " << (x) << endl

#if 1
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
#endif

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}

//*** define ***//
#define For(_i, _a, _b) for (int _i = (_a); _i < (_b); _i++)
#define Fori(_i, _a, _b) for (int _i = (_a); _i <= (_b); _i++)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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
const int oo = 1e18, mod = 1e9 + 7;
const int ms = 5e4 + 5;
int n, k;
int a[ms];
int b[ms];
int d[ms];

void solve() {
    cin >> n >> k;
    Fori(i, 1, n) cin >> a[i];
    Fori(i, 1, n) cin >> b[i];

    Fori(i, 1, n) {
        d[i] = a[i] - b[i];
    }


    int vmax = 0;
    vector c(4 * ms, 0);
    Fori(i, 1, n - 1) {
        Fori(j, i + 1, n) {
            int val = a[i] - a[j] - (b[i] - b[j]);
            val = abs(val);
            c[val]++;
            vmax = max(vmax, val);
        }
    }

    if (c[0] == k) {
        cout << "0\n";
        return;
    }
    Fori(i, 1, vmax) {
        c[i] += c[i - 1];
        if (c[i] == k) {
            cout << i << '\n';
            return;
        }
        if (c[i] > k) {
            cout << "-1\n";
            return;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}