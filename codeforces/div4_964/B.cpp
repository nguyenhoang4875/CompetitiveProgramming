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
int n;

void solve() {
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int cnt = 0;
    cnt += (((a1 > b1) + (a2 > b2)) == 2);
    cnt += (((a1 > b1) + (a2 == b2)) == 2);
    cnt += (((a1 == b1) + (a2 > b2)) == 2);
    // cout << a1 << " " << b1  << " " << a2 << " " << b2 << el;

    swap(b1, b2);
    // cnt += (((a1 > b1) + (a2 > b2)) == 2);
    cnt += (((a1 > b1) + (a2 > b2)) == 2);
    cnt += (((a1 > b1) + (a2 == b2)) == 2);
    cnt += (((a1 == b1) + (a2 > b2)) == 2);
    // cout << a1 << " " << b1  << " " << a2 << " " << b2 << el;

    swap(a1, a2);
    // cnt += (((a1 > b1) + (a2 > b2)) == 2);
    cnt += (((a1 > b1) + (a2 > b2)) == 2);
    cnt += (((a1 > b1) + (a2 == b2)) == 2);
    cnt += (((a1 == b1) + (a2 > b2)) == 2);
    // cout << a1 << " " << b1  << " " << a2 << " " << b2 << el;

    swap(b1, b2);
    // cnt += (((a1 > b1) + (a2 > b2)) == 2);
    cnt += (((a1 > b1) + (a2 > b2)) == 2);
    cnt += (((a1 > b1) + (a2 == b2)) == 2);
    cnt += (((a1 == b1) + (a2 > b2)) == 2);
    // cout << a1 << " " << b1  << " " << a2 << " " << b2 << el;

    cout << cnt << el;
    // ?
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