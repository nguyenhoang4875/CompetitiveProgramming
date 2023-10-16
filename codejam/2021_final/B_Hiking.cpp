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
#define For(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
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
const int ms = 20;
int n, m, x, C, D;
int a[ms], b[ms];
int aa[ms], bb[ms];


vector<int> fac;

void initFac(int n) {
    fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
}

int getBit(int n, int idx) {
    return (n >> idx) & 1;
}

void solve() {
    cin >> n >> m >> x >> C >> D;
    For(i, 0, n - 1) cin >> a[i];
    For(i, 0, n - 1) cin >> b[i];

    sort(a,a + n);
    sort(b,b + n);
    
    // prefix sum;
    // For(i, 1, n) aa[i] = aa[i - 1] + a[i];
    // For(i, 1, n) bb[i] = bb[i - 1] + b[i];

    // vii vaa;
    // vii vbb;
    vi vaa[n + 5];
    vi vbb[n + 5];
    int cnt = 0;
    // count for A

    For(mask, 1, (1 << n) - 1) {

        int sumA = 0;
        int sumB = 0;
        debug(mask);
        For(i, 0, n - 1) {
            if(getBit(mask, i)) {
                
                sumA += a[i];
                sumB += b[i];
                debug(i);
            }
        }
        int numBit = __popcount(mask);
        if(sumA >= C && sumA <= D) {
            // vaa.pb({numBit, sumA});
            vaa[numBit].pb(sumA);
        }
        if(sumB >= C && sumB <= D) {
            vbb[numBit].pb(sumB);
        }

    }
    For(i, 1, n) {
        sort(all(vaa[i]));
        sort(all(vbb[i]));
        debug(vaa[i]);
        debug(vbb[i]);
    }
    int sum = 0;

    // one mountain
    if(!vaa[1].empty()) {
        sum += vaa[1].size();
    }
    if(!vbb[1].empty()) {
        sum += vbb[1].size();
    }
    sum %= mod;
    cout << sum << endl;



}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    initFac(2 * ms);
    int tcs;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}