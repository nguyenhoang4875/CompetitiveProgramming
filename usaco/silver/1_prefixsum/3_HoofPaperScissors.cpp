#include <bits/stdc++.h>
#define int long long

using namespace std;

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
int n;
int ch[ms], cs[ms], cp[ms];

int getNumberWin(char c, int l, int r) {
    if (c == 'H') {
        return cs[r] - cs[l - 1];
    }
    if (c == 'S') {
        return cp[r] - cp[l - 1];
    }
    if (c == 'P') {
        return ch[r] - ch[l - 1];
    }
    return 0;
}

int calChange(char A, char B, int i) { return getNumberWin(A, 1, i - 1) + getNumberWin(B, i, n); }

void solve() {
    cin >> n;
    char x;
    For(i, 1, n) {
        cin >> x;
        ch[i] = ch[i - 1];
        cs[i] = cs[i - 1];
        cp[i] = cp[i - 1];
        if (x == 'H') ch[i]++;
        if (x == 'S') cs[i]++;
        if (x == 'P') cp[i]++;
    }
    int ans = 0;
    for (auto e1 : {'H', 'S', 'P'}) {
        for (auto e2 : {'H', 'S', 'P'}) {
            For(i, 1, n) { ans = max(ans, calChange(e1, e2, i)); }
        }
    }
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);

    solve();
    return 0;
}