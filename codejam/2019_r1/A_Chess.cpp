#include<bits/stdc++.h>

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/17122
 * Solution: 
 * - Convert A1 to 1
 * - Check the color of two cells
 * 
 * TC: O(64) // for construct table
 * MC: O(64)
*/

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
#define pb push_back
#define FOR(_i,_a,_b) for(int _i = (_a); _i < (_b); _i++)
#define FORI(_i,_a,_b) for(int _i = (_a); _i <= (_b); _i++)
#define FORE(it,x) for(auto it = x.begin(); it != x.end(); ++it)

//*** custom using ***//
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vc = vector<char>;
using vvc = vector<vc>;
using pii = pair<int, int>;

//*** START CODING ***//

int tcs, n;
bool color[65];
void init() {
    bool c = false; // black: 0, white: 1
    color[1] = 0;
    for(int i = 2; i <= 64; i++) {
        if(i % 8 != 1) c = !c;
        color[i] = c;
    }
}

void solve() {
    string a, b;
    cin >> a >> b;
    int na = (a[1] - '1') * 8 + (a[0] - 'A' + 1);
    int nb = stoi(b);
    if(color[na] == color[nb]) {
        cout << "YES\n";
    }
    else cout << "NO\n";

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}