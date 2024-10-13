#include <bits/stdc++.h>
#define int long long

using namespace std;
//*** debug(x) ***//
#define DEBUG 1

#if DEBUG
#define del cout << '\n'
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl
template <class Ch, class Tr, class Container>
basic_ostream<Ch, Tr>& operator<<(basic_ostream<Ch, Tr>& os, Container const& x) {
    os << "{ ";
    for (const auto& y : x) os << y << ", ";
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
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
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
int setBit(int n, int pos) { return n |= (1 << pos); }
int clearBit(int n, int pos) { return n &= ~(1 << pos); }
int getBit(int n, int pos) { return (n >> pos) & 1; }
int toggleBit(int n, int pos) { return n ^= (1 << pos); }

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n, m;
    cin >> n >> m;
    vi a(n);

    vb used(2 * n + 5);
    for (auto& x : a) {
        cin >> x;
        used[x + n] = true;
    }
    vi b;
    for (int i = 0; i <= 2 * n; i++) {
        if (i - n == 0) continue;
        if (used[i]) continue;
        b.push_back(i - n);
    }

    int maxMask = (1 << n) - 1;
    vvi f(maxMask + 1, vi(n + 1, 0));

    f[0][0] = 1;
    for (int mask = 0; mask <= maxMask; mask++) {
        for (int score = 0; score <= m; score++) {
            int cnt = __builtin_popcount(mask);
            if (cnt == n) continue;

            for (int i = 0; i < n; i++) {
                if (!getBit(mask, i)) {
                    int newMask = setBit(mask, i);
                    if (a[cnt] * b[i] < 0 or abs(a[cnt]) > abs(b[i])) {
                        f[newMask][score + 1] += f[mask][score];
                    } else {
                        f[newMask][score] += f[mask][score];
                    }
                }
            }
        }
    }

    cout << f[maxMask][m] << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    cin >> tcs;
    while (tcs--) {
        solve();
    }
    return 0;
}