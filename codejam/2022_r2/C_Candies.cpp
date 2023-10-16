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

const int oo = 1e18, mod = 987654323;
const int ms = 5e4 + 5;;
int n;
int v[ms];

void solve() {
    cin >> n;
    int vmax = 0;
    int m = 0;
    Fori(i, 1, n) {
        cin >> v[i];
        m += v[i];
        vmax = max(vmax, v[i]);
    }
    if(vmax > m / 2  + 1) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    int lOdd = 1, lEven = 2;
    vi c(m + 5);
    int i = 1;
    Fori(i, 1 , n) cout << v[i] << ' ';
    cout << '\n';
    Fori(i, 1, n) {
        // cout << lOdd << " " << lEven << '\n';
        if(lOdd < lEven) {
            // lOdd += 2;
            while(v[i]) {
                c[lOdd] = i;
                v[i]--;
                lOdd += 2;
            }
        } else {
            // lEven += 2;
            while(v[i]) {
                c[lEven] = i;
                v[i]--;
                lEven+= 2;
            }

        }
    }
    
    debug(c);
    // Fori(i, 1, m) cout << c[i] << ' ';
    // cout << endl;

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