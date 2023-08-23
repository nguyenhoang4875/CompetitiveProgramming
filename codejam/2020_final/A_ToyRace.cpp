#include<bits/stdc++.h>

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/19592
 * Solution: brute force
 *  - Find the fastest toy
 *  - Calculate the booter need to when the fastest toy
 * 
 * TC: O(n)
 * MC: O(n)
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

int oo = 1e9;
int tcs, n, x, y;
int v[1000005];

void solve() {
    cin >> n >> x >> y;
    for(int i = 1; i <= n; i++) cin >> v[i];
    double tm = oo; // time min
    int id = 0;
    for(int i = 1; i < n; i++) {
        double temp = 1.0 * x / v[i];
        if(tm > temp) {
            tm = temp;
            id = i ;
        }
    }

    // if v[n] is max no need booster
    if(v[id] < v[n]) {
        cout << "0\n";
        return;
    }

    double z = x - 1.0*(x - v[id])*v[n] / v[id]; 
    int ans = ceil(z);
    if(ans == z) ans++;
    if(ans > y) {
        cout << "-1\n";
        return;
    }
    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}