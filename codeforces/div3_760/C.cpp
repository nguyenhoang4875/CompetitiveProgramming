#include<bits/stdc++.h>
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
const int ms = 100 + 5;
int n;
int a[ms];

void solve() {
    cin >> n;
    For(i, 1, n) cin >> a[i];

    int go = 0, ge = 0;

    For(i, 1, n) {
        if(i & 1) go = __gcd(go, a[i]);
        else ge = __gcd(ge, a[i]);
    }
    debug(go);
    debug(ge);

    if(go == 1 and ge == 1) {
        cout << 0 << el; return;
    }
    if(go > 1) {
        bool ok = true; 
        for(int i = 2; i <= n; i += 2)  {
            if(a[i] % go == 0) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << go << el;
            return;
        }
    }
    if(ge > 1) {
        bool ok = true; 
        for(int i = 1; i <= n; i += 2)  {
            if(a[i] % ge == 0) {
                ok = false;
                break;
            }
        }
        if(ok) {
            cout << ge << el;
            return;
        }
    }
    cout << 0 << el;

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