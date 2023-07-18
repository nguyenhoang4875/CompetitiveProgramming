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

int tcs, n;
int a[200005];

void solve() {
    cin >> n;
    // int allOne = (1 << 30) - 1;
    // int minAll = allOne;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int minAll = a[1];
    for(int i = 1; i <= n; i++) {
        minAll &= a[i];
    }
    // cout << "minAll = " << minAll << endl;

    int temp = a[1];
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        temp &= a[i];
        if(temp == minAll && minAll == 0) {
            cnt++;
            temp = a[i+1];
        }
    }

    cout << max(cnt, 1LL) << "\n";

}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    // cout << (1 << 30) - 1 << endl;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}