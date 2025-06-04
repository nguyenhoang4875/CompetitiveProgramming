#include<bits/stdc++.h>
#define int long long

using namespace std;

//*** debug(x) ***//
#define DEBUG 1

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

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = (a); i <= (int) (b); i++)
#define Rof(i, a, b) for (int i = (a); i >= (int) (b); i--)
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

const long long oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    int ia = 0, ib = 0;
    while(ia < n and a[ia] == '0') ia++;
    while(ib < m and b[ib] == '0') ib++;
    // debug(ia);
    // debug(ib);
    if(n - ia != m - ib) {
        if(n - ia > m - ib) {
            cout << ">" << el;
        } else cout << "<" << el;
        return;
    }
    for(int i = ia, j = ib; i < n and j < m; i++, j++) {
        if(a[i] == b[j]) continue;
        if(a[i] > b[j]) {
            cout << ">" << el;
        } else cout << "<" << el;
        return;
    }
    cout << "=" << el;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}