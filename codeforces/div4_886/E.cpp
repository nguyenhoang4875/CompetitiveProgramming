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

//*** START CODING ***//

int tcs, n, c;
int a[200005];

void solve() {
    cin >> n >> c;
    int s = 0;
    int x = 0;
    int xx = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i] * a[i];
        x += 4 * a[i];
    } 
    xx = 4 * n;

    int mx = sqrt((c - s) /xx);

    int l = 0, r = mx;
    while(l <= r) {
        int mid = (l + r) / 2;
        int val = xx * mid * mid + x * mid + s;
        if(val == c) {
            cout << mid << '\n';
            return;
        } else if(val < c) {
            l = mid + 1;
        } else r = mid - 1; 
    }

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