#include<bits/stdc++.h>
#define int long long

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
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define For(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define Ford(_i, _a, _b) for (int _i = (_a); _i >= (_b); _i--)
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


void solve() {
    cin >> n;
    set<pii> mts;
    char type;
    int a, b;
    For(i, 1, n) {
        cin >> type;
        cin >> a >> b;
        pii p = {a, b};
        if(type == '+') {
            auto up = mts.upper_bound(p);
            if(up == mts.end()) {
                --up;
                pii vUp = *up;
                int x, y;
                if(vUp.F <= b) {
                    x = min(a, vUp.F);
                    y = max(b, vUp.S);
                    mts.erase(up);
                    mts.insert({x, y});
                }

            } else {
                pii vUp = *up;
                auto low = prev(up);
                pii vLow = *(low);
                int x, y;
                if(vUp.first <= b) {
                    x = min(a, vUp.F);
                    y = max(b, vUp.S);
                    mts.erase(up);
                    // mts.insert({x, y});
                }
                
                if(vLow.S >= a) {
                    x = min(x, vLow.F);
                    mts.erase(low);
                }
                mts.insert({x, y});
            }

        } else {

        }
        if(mts.size() >= 2) {
            cout << "YES\n";
        } else cout << "NO\n";


    }
    cout << "abc" << endl;

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int tcs;
    // cin >> tcs;
    tcs = 1;
    while(tcs--) {
        solve();
    }
    return 0;
}