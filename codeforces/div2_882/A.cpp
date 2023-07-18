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

int tcs, n, k;
int a[105];
int b[105];

struct node {
    int val;
    int lDiff, rDiff;
};

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int sum = 0;
    for(int i = 0; i < n - 1; i++ ) {
        b[i] = abs(a[i+1] - a[i]);
        sum += abs(a[i+1] - a[i]);
    }
    // cout << "sum = " << sum << endl;
    sort(b, b + n - 1, greater<int>());

    k -= 1;
    for(int i = 0; i < k; i++) {
        sum -= b[i];
    }
    cout << sum << "\n";
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