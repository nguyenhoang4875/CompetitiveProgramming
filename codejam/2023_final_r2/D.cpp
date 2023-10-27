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
#define For(i, a, b) for (int i = (int)a; i <= (int)b; i++)
#define Ford(i, a, b) for (int i = (int)a; i >= (int)b; i--)
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

const int oo = 1e18, mod = 1000003;
const int ms = 1e5 + 5;
int r, c, n;

void solve() {
    cin >> r >> c >> n;

    vi xa, ya;
    For(i, 1, n) {
        int x, y;
        cin >> x >> y;
        xa.pb(x);
        ya.pb(y);
    }

    vi temp = xa;
    sort(all(temp));
    for(int i = 0; i < n; i++) {
        xa[i] = lower_bound(temp.begin(), temp.end(), xa[i]) - temp.begin() + 1;
    }
    for(auto x: xa) cout << x << " ";
    cout << "\n";

    vi temp2 = ya;
    sort(all(temp2));
    for(int i = 0; i < n; i++) {
        ya[i] = lower_bound(temp2.begin(), temp2.end(), ya[i]) - temp2.begin() + 1;
    }
    for(auto e: ya) cout << e << " ya ";
    cout << "\n";

    int rMax = xa.size();
    int cMax = ya.size();
    cout << rMax << " " << cMax << endl;
    int a[rMax + 5][cMax + 5] = {0};
    for(int i = 0; i <= rMax; i++) {
        cout << xa[i] << " p " << ya[i] << '\n';
        a[xa[i]][ya[i]] = 1;
    };
    for(int i = 1; i <= rMax; i++) {
        for(int j = 1; j <= rMax; j++) {
            cout << a[i][j] << ' ';
        }
        cout << "\n";
    }
    // vvi dp(rMax + 5, vi(rMax + 5, 0));
    // dp[1][1] = 1;
    // for(int i = 1; i <= rMax; i++) {
    //     for(int j = 1; j <= rMax; j++) {
    //       dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    //       dp[i][j] %= mod;
    //     }
    // }
    // cout << dp[rMax][rMax] << "\n";

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