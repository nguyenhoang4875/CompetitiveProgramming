#include <bits/stdc++.h>
#define int long long

using namespace std;

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

//*** START CODING ***//

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (auto& x : a) cin >> x;
    int tot = 0;
    for (auto& x : a) tot += x;

    if (tot & n == 0) {
        int v = tot / n;
        int sum = 0;
        for (auto e : a) { sum += abs(v - e); }
        sum /= 2;
        cout << sum << el;
        return;
    }
    int ans = 0;
    int v1 = tot / n;
    int sum = 0;
    for (auto e : a) {
        if (e < v1) sum += v1 - e;
    }
    ans = max(ans, sum);
    sum = 0;
    int v2 = v1 + 1;
    for (auto e : a) {
        if (e > v2) sum += e - v2;
    }
    ans = max(ans, sum);
    cout << ans << el;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs = 1;
    while (tcs--) { solve(); }
    return 0;
}