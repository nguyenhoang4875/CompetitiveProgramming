#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

using namespace std;

//*** debug(x) ***//
#define debug(x) cout << "[" << #x << "]" << " : " << (x) << endl

#if 1
template <class Ch, class Tr, class Container>
basic_ostream <Ch, Tr> & operator << (basic_ostream <Ch, Tr> & os, Container const& x) {
    os << "{ ";
    for(auto& y : x)os << y << ", ";
    return os << "}";
}

template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "(" << p.first << ", " << p.second << ")" ;
}
#endif

template<typename T>
void check_here(T x){
    cout << "------------- " << x << " -------------" << endl;
}

//*** define ***//
#define For(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define Fori(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define Fore(it,x) for(auto it = x.begin(); it != x.end(); ++it)

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

const int oo = 1e18, mod = 1e9 + 7;
const int ms = 1e5 + 5;
int n, a, b, c;
int v[ms];
int preSum[ms];

void solve() {
    cin >> n;
    cin >>  a >> b >> c;
    // debug(n);
    Fori(i, 1, n) cin >> v[i];
    Fori(i, 1, n) preSum[i] = preSum[i - 1] + v[i];

    // Fori(i, 1, n) cout << v[i] << " ";
    // cout << endl;

    Fori(i, 1, n) cout << preSum[i] << " ";
    cout << endl;


    vi tt = {0, 1, 2};
    vi s = {a, b, c};
    int ans = -2*oo;
    int total = a + b + c;
    do {
        a = s[tt[0]];
        b = s[tt[1]];
        c = s[tt[2]];
        cout << a << b << c << endl;
        int sa, sb, sc;
        for(int i = 1; i <= n - total + 1; i++) {
            sa = preSum[i + a - 1] - preSum[i - 1];
            sb = preSum[i + a + b - 1] - preSum[i + a - 1];
            sc = preSum[i + a + b + c - 1] - preSum[i + a + b - 1];
            cout << sa << " " << sb  << " " << sc << "\n";
            ans = max(ans, sa * sb * sc);
        }


    } while(next_permutation(tt.begin(), tt.end()));
    cout << ans << '\n';

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}