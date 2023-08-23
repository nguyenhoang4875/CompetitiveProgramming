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
using pii = pair<int, int>;

//*** START CODING ***//

const int MS = 1e5 + 5;
const int MOD = 1e9 + 7;
int tcs, n;
int a[MS];


int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1) res = (res * x) % p;
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

void solve() {
    cin >> n; 
    for(int i = 1; i <= n; i++) cin >> a[i];
    unordered_set<int> s;
    int sum = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        bool dup = false;
        s.insert(i);
        for(int j = i + 1; j <= n; j++) {

            if(s.count(a[j])) {
                dup = true;
                break;
            }
            s.insert(a[j]);
            int len = j - i + 1;
            sum += (power(i, len, MOD) + power(j, len, MOD)) % MOD;
            sum %= MOD;
            // s.clear();
        }
        s.erase(a[i]);
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