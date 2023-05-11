#include<bits/stdc++.h>

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
#define int long long
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)

//*** typedef ***//
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;

//*** START CODING ***//


int tcs, n, m;
const int  MOD = 1e9 + 7;
vector<int> fac;

void initFac(int n) {
    fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
		fac[i] = (fac[i - 1] * i) % MOD;
    }
}

int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}
 
// Returns n^(-1) mod p
int modInverse(int n, int p) {
    return power(n, p - 2, p);
}
 
// Returns nCr % p using Fermat's little theorem.
int nCrModPFermat(int n, int r, int p) {
    if (n < r) return 0;
    if (r == 0) return 1;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
 

void solve() {
    cin >> n >> m;
    int x, y;
    int ans = 0;
    FOR(i, n,  min(m - 1, 2*n - 1) + 1){
        x = nCrModPFermat(2*n - 1, i, MOD);
        y = nCrModPFermat(2*(m - n), m - (2*n - 1 - i), MOD);
        ans += x * y;
        ans %= MOD;
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    initFac(2e5 + 1);
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}