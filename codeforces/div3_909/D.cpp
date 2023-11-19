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
#define sz(a) (int)(a).size()
#define el '\n'
#define F first
#define S second
#define For(i, a, b) for (int i = a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = a; i >= (int)b; i--)
#define Fore(it, x) for (auto it = x.begin(); it != x.end(); ++it)

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
const int ms = 2e5 + 5;
int n;
int a[ms];

int power(int a, int n) {
    int ans = 1;
    while (n > 0) {
        if (n & 1) ans *= a;
        n /= 2;
        a *= a;
    }
    return ans;
}

int nC2(int n) {
    return n * (n - 1) / 2;
}

void solve() {
    cin >> n;
    map<int, int> mii;
    int maxVal = 0;
    For(i, 1, n) {
        cin >> a[i];
        maxVal = max(maxVal, a[i]);
        mii[a[i]]++;
    }
    int ans = 0;
    for(auto [f, s]: mii) {
        if(s >= 2) ans += nC2(s);
    }

    for(auto [f, s]: mii) {
        if(mii.count(2*f)) {
            if(f != 1) continue;
            ans += s * mii[2*f];
        }
        if(2 * f > maxVal) break;
    }
    cout << ans << el;
    


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // cout << power(8, 64) << el;
    // cout << power(64, 8) << el;
    int tcs;
    cin >> tcs;
    while(tcs--) {
        solve();
    }
    return 0;
}