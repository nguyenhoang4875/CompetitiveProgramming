#include <bits/stdc++.h>
#define int long long

using namespace std;
//*** debug(x) ***//
#define DEBUG 0

#if DEBUG
#define del cout <<  '\n'
#define debug(x) cout <<  "[" << #x << "]" << " : " << (x) << endl
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
vi x, a;
int findNext(int ai, int xi, int idx){
    int val = (ai + xi);
    if(idx <= n - 1 and idx >= 1) val += x[idx + 1];
    int rm = val % a[idx - 1];
    val -= rm;
    val += x[idx];
    return val;
}

void solve() {
    cin >> n;
    x = vi(n + 1, 0);
    a = vi(n + 1, 0);


    For(i, 1, n - 1) cin >> x[i];
    a[0] = x[1] + 1;


    For(i, 1, n - 1) {
        a[i] = findNext(a[i - 1], x[i], i);
    }
    For(i, 0, n - 1) {
        cout << a[i] << " ";
    }
    cout << el;
    debug(n);
    debug(x);
    debug(a);
    del;

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