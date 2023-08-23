#include<bits/stdc++.h>

using namespace std;
/**
 * Problem: https://codejam.lge.com/problem/17124
 * Solution:
 *  - Sort array a, b ascending
 *  - Find the nearest for a[1] // O(m)
 *  - Find the nearest for each a[i] in array b // O(n);
 * TC: O(max(n, m))  (max = 10^6 => AC)
 * MC: O(max(n, m))
 * 
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

const int MS = 1e6 + 5; // max size
const int oo = 1e18;
int tcs, n, m;
int a[MS], b[MS], c[MS];

void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);

    // find first index of array b for a[i];
    int fIdx = 0;
    int diff = oo;
    for(int i = 1; i <= m; i++) {
        int td = abs(a[1] - b[i]);
        if(td < diff) {
            diff = td;
            fIdx = i; 
        }
    }
    int sum = 0;
    sum += b[fIdx]; // for a[1]

    int lIdx = fIdx; // keep the last index of array b 
    for(int i = 2; i <= n; i++) {
        while(lIdx < m && (abs(a[i] - b[lIdx]) > abs(a[i] - b[lIdx + 1]))) lIdx++;
        sum += b[lIdx];
    }
    cout << sum << '\n';
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