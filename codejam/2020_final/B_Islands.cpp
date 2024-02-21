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

//*** START CODING ***//

//*** debug(x) ***//
#if 1
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

template <typename T>
void check_here(T x) {
    cout << "------------- " << x << " -------------" << endl;
}
#endif

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e4 + 5;
int n, s, a, b;
int e[ms];

void solve() {
    cin >> n >> s >> a >> b;
    int sqn = n * n;
    e[1] = s % sqn;

    set<pii> si;
    map<pii, int> mi;
    int x = e[1] / n, y = e[1] % n;
    if (x != y) {
        si.insert({x, y});
    }

    int i = 1;
    while (i <= n * n) {
        i++;
        e[i] = (e[i - 1] * a % sqn + b % sqn) % sqn;
        x = e[i] / n;
        y = e[i] % n;
        // debug(x);
        // debug(y);
        if (x == y) continue;
        if (si.count({x, y})) {
            cout << 0 << el;
            return;
        }
        if (!si.count({y, x})) {
            si.insert({x, y});
        }
        // debug(sz(si));
        if (si.size() == n - 1) {
            cout << i << el;
            return;
        }
    }
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