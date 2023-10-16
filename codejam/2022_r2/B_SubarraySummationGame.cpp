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
const int ms = 2e5 + 5;
int n, m;
int a[50005];
int x[ms], y[ms];

vector<int> fac;

void initFac(int n) {
    fac.resize(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
}



void solve() {
    cin >> n >> m;
    Fori(i, 1, n) cin >> a[i];
    Fori(i, 1, m) cin >> x[i] >> y[i];
   vi cnt(n + 5, 0);
    Fori(i, 1, m) {
        // cout << x[i] << " " << y[i] << '\n';
        cnt[x[i]]++;
        cnt[y[i] + 1]--;
    }
    // debug(cnt);
    Fori(i, 1, n) cnt[i] += cnt[i - 1];
    // debug(cnt);
    sort(cnt.begin() + 1, cnt.begin() + n + 1, greater<int>());
    sort(a + 1, a + n + 1, greater<int>());
    int sum = 0;
    Fori(i, 1, n) {
        sum += cnt[i] * a[i];
    }
    map<int, int> mi;
    Fori(i, 1, n) mi[cnt[i]]++;
    int cntWay = 1;
    for(auto [f, s] : mi) {
        if(s > 1) {
            cntWay = cntWay * fac[s] % mod;
        }
    }
    cout << sum << " " << cntWay << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    initFac(50005);
    int tcs;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}