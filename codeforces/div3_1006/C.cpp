#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 0

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

//*** define ***//
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int) (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int) (b); i--)
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
int n, x;

void solve() {
    cin >> n >> x;
    if(n == 1) {
        cout << x << el;
        return;
    }
    vi a;
    int cnt = 0;
    int tx = x;
    while(tx & 1) {
        cnt++;
        tx >>= 1;
    }
    int mx = (1LL << cnt)  - 1;
    debug(mx);
    int tot = 0;
    for(int i = 0; i <= mx and a.size() < n; i++) {
        a.pb(i);
        tot |= i;
    }
    debug(a);
    if(tot != x and a.size() == n) a.pop_back(), a.push_back(x);

    while(a.size() < n) a.pb(x);
    for(auto e: a) cout << e << " ";
    cout << el;

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