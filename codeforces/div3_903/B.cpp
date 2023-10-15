#include<bits/stdc++.h>
#define int long long
#define pb push_back

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
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)

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
int a[5];
int n = 3;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if(a == b && a == c) {
        cout << "YES\n";
        return;
    }
    int tmn = min({a, b, c});
    int tmx = max({a, b, c});
    int tmd = (a + b + c) - (tmn + tmx);
    if(tmd % tmn != 0 || tmx % tmn != 0) {
        cout << "NO\n";
        return;
    }

    int sum = a + b + c;
    int t = sum / tmn;
    if(t >= 3 && t <= 6) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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