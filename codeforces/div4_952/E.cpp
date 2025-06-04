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
#define all(x) x.begin(), x.end()
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Rof(i, a, b) for (int i = a; i >= (int)b; i--)
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

const int oo = 2e18, mod = 1e9 + 7;
const int ms = 2e5 + 5;
int n, x, y, z, k;

vi getDivisors(int n) {
    vi ans;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ans.pb(i);
            if (i * i != n) ans.pb(n / i);
        }
    }
    sort(all(ans));
    return ans;
}

void solve() {
    cin >> x >> y >> z >> k;
    // x++; y++; z++;

    vi a = {x, y, z};
    sort(all(a));
    x = a[0];
    y = a[1];
    z = a[2];
    debug(a);

    vi ds = getDivisors(k);
    debug(ds);
    int n = ds.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(ds[i] > x) break;
        for(int j = i; j < n; j++) {
            if(ds[j] > y) break;

            if(ds[i] * ds[j] > k) break;

            int t = k / (ds[i] * ds[j]);
            if(t * ds[i] * ds[j] != k) continue;
            if(t > z) continue;

            int z1 = x - ds[i] + 1;
            int z2 = y - ds[j] + 1;
            int z3 = z - t + 1;
            if(z1 <= 0 or z2 <= 0 or z3 <= 0) continue;
            debug(vi({z1, z2, z3}));
            ans = max(ans, z1 * z2 * z3);
            debug(ans);
        }
    }
    cout << ans << el;
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