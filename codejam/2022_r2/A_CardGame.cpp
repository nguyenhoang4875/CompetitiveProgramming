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
int n;
string a, b;

void solve() {
    cin >> n;
    cin >> a >> b;
    int minA = stoll(a);
    reverse(a.begin(), a.end());
    minA = min(minA, stoll(a));

    sort(b.begin(), b.end());
    string st = "";
    for(int i = n - 1; i >= 0; i--) st += b[i];
    int ans = 0; 

    do {
        string tb = b;
        tb.pop_back();
        int t1 = stoll(tb);
        if(t1 < minA && t1 > ans) ans = t1;
        int t2= stoll(b);
        if(t2 < minA && t2 > ans) ans = t2;
    } while(next_permutation(b.begin(), b.end()));

    cout << ans << "\n";

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